#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  //----------------------------------------------------TEXTE
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Aquarium");
  display.setCursor(0, 17);
  display.setTextSize(1);
  display.println("IP: 192.168.15.160");
  display.setCursor(0, 28);
  display.println("Eau");
  display.setCursor(45, 28);
  display.println("led");
  display.setCursor(90, 28);
  display.println("pompe");
  display.setCursor(0, 39);
  display.print("78");
  display.print((char)247);
  display.println("F");
  display.setCursor(45, 39);
  display.println("OFF");
  display.setCursor(90, 39);
  display.println("OFF");
  display.display(); 
}

void loop() {
  // put your main code here, to run repeatedly:
}
