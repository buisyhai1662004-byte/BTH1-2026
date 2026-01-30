#include <Arduino.h>
#include "DHT.h"

// ====== CẤU HÌNH DHT22 ======
#define DHTPIN 5        // Chân DATA nối GPIO 4
#define DHTTYPE DHT22   // Loại cảm biến

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(1000);          // đợi Serial ổn định
  dht.begin();

  Serial.println("Khoi dong cam bien DHT22...");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // °C

  // Kiểm tra lỗi đọc
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Doc DHT22 THAT BAI!");
  } else {
    Serial.print("Nhiet do: ");
    Serial.print(temperature);
    Serial.print(" °C | Do am: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(2000); // DHT22 chỉ đọc mỗi 2 giây
}
