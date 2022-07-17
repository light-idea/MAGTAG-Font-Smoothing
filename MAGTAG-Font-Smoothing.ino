#include <GxEPD2_4G_4G.h>
#include "fonts/NotoSerif_Regular56pt7bGrey.h"

GxEPD2_4G_4G<GxEPD2_290_T5, GxEPD2_290_T5::HEIGHT> display(GxEPD2_290_T5(8, 7, 6, 5)); // GDEW029T5
#define DISP_W 296
#define DISP_H 128

void setup() {
  String str = "5:30";
  int16_t x, y;
  uint16_t w, h;

  display.init(115200);
  display.setRotation(3);
  display.setFont(&NotoSerif_Regular56pt7bGrey[0]);
  display.getTextBounds(str, 0, 0, &x, &y, &w, &h);

  display.setFullWindow();
  display.firstPage();
  do {
      display.fillScreen(GxEPD_WHITE);
      for (int i = 2; i >= 0; --i) {
        display.setTextColor((i==2) ? GxEPD_LIGHTGREY : 
                             (i==1) ? GxEPD_DARKGREY : 
                                      GxEPD_BLACK);
        display.setFont(&NotoSerif_Regular56pt7bGrey[i]);
        display.setCursor((DISP_W - w)/2, (DISP_H + h)/2); // center text
        display.print(str);
      }
  } while (display.nextPage());
  display.hibernate();
}

void loop() {
  delay(60000);
  display.setFullWindow();
  display.firstPage();
  do {
      display.fillScreen(GxEPD_WHITE);
  } while (display.nextPage());
  display.hibernate();
  display.powerOff();
}
