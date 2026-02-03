#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// ---------- DHT ----------
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ---------- OLED ----------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  delay(1000);

  // Start DHT
  dht.begin();
  delay(2000);

  // Start I2C (ESP32 default pins)
  Wire.begin(21, 22);

  // Start OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println("OLED not found");
    while (true); // stop here
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("DHT11 + OLED");
  display.display();
  delay(2000);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read DHT11");
    return;
  }

  // Serial output
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %  ");

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.println(" C");

  // OLED output
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("DHT11 Readings");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("T: ");
  display.print(temperature);
  display.println("C");

  display.setCursor(0, 45);
  display.print("H: ");
  display.print(humidity);
  display.println("%");

  display.display();

  delay(3000); // DHT11-safe delay
}
