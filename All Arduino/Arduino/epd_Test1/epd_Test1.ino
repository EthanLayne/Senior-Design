#include <SPI.h>
#include "epd4in2.h"
#include "imagedata.h"
#include "epdpaint.h"

#define COLORED     0
#define UNCOLORED   1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Epd epd;


  if (epd.Init() != 0) {
    Serial.print("e-Paper init failed");
    return;
  }
	//Serial.print(UNCOLORED);
  /* This clears the SRAM of the e-paper display */
  epd.ClearFrame();

  /**
    * Due to RAM not enough in Arduino UNO, a frame buffer is not allowed.
    * In this case, a smaller image buffer is allocated and you have to 
    * update a partial display several times.
    * 1 byte = 8 pixels, therefore you have to set 8*N pixels at a time.
    */
  unsigned char image[1500];
  Paint paint(image, 400, 28);    //width should be the multiple of 8 

  paint.Clear(UNCOLORED);
  epd.DisplayFrame();
}

void loop() {
  // put your main code here, to run repeatedly:

}

