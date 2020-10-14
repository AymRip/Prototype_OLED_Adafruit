#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display largeur, en pixels
#define SCREEN_HEIGHT 64 // OLED display hauteur, en pixels
// Declaration pour un SSD1306 display connecté en I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  //----------------------------------------------------TEXTE
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  //délai de 2 secondes
  delay(2000);
  //reset du display
  display.clearDisplay();
  //grosseur du texte
  display.setTextSize(2);
  //couleur du texte
  display.setTextColor(WHITE);
  //Permet de déplacer le curseur pour afficher le texte à l'endroit voulu
  display.setCursor(0, 0);
  //Permet d'écrire du texte sur l'écran OLED
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
  //print seul permet d'écrire sur une même ligne
  display.print("78");
  display.print((char)247);
  display.println("F");
  display.setCursor(45, 39);
  display.println("OFF");
  display.setCursor(90, 39);
  display.println("OFF");
  //Permet d'afficher le texte sur l'écran OLED
  display.display(); 
}

void loop() {
  // put your main code here, to run repeatedly:
}
