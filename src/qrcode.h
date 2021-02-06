#include "Adafruit_SSD1306.h"

class QRcode
{
	private:
		Adafruit_SSD1306 *display;
		void render(int x, int y, int color);

	public:
		QRcode(Adafruit_SSD1306 *display);

		void init();
		void debug();
		void screenwhite();
		void create(String message);
};
