/* *********************************************************************************
 * SSD1306 QRcode Plotter
 * dependency library :
 *   Adafruit_SSD1306 and Adafruit GFX Library
 *
***********************************************************************************/

#include <qrcode.h>
#include "Adafruit_SSD1306.h"

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
QRcode qrcode (&display);

void setup() {

    Serial.begin(115200);
    Serial.println("");
    Serial.println("Starting...");

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
      Serial.println(F("SSD1306 allocation failed"));
      for (;;)
        ; // Don't proceed, loop forever
    }
    display.display();

    // Initialize QRcode display using library
    qrcode.init();
    // create qrcode
    qrcode.create("Hello world.");

}

void loop() { }
