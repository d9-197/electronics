
/**
 * This display is a take on the work game slither.io
 * 
 * The work is not allowed to swirm off of the display.  The worm
 * looks for a locaiton on the board if it is against a wall.
 * 
 * 
 *  Required Libraries:
 *  
 *    Use Adafruit NeoMatrix version 1.1.0
 *    and Adafruit GFX 1.0.2
 *    and Adafruit_Neopixel 1.0.4
 */

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "Worm.h"

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 15

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)

const int width = 8;
const int height = 4;

// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(width, height, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB            + NEO_KHZ800);

Worm colorWorm = Worm(0,0, 0, 0);

Worm worm1 = Worm(width, height, 5, colorWorm.Color(255, 0, 0));
Worm worm2 = Worm(width, height, 6, colorWorm.Color(0, 255, 0));            
Worm worm3 = Worm(width, height, 7, colorWorm.Color(0, 0, 255));
                    
int wormCount = 3;

Worm worms [] = 
{
    worm1,
    worm2,
    worm3
};

void loop() 
{
    matrix.fillScreen(0);

    for(int w=0; w<wormCount; w++)
    {
      worms[w].move();
      
      worms[w].draw(&matrix);        
    }

    matrix.show();
  
    delay(500);
}

void setup() 
{
    worm1.segmentColor = worm1.Color(255, 0, 0);
    worm2.segmentColor = worm2.Color(0, 255, 0);
    worm3.segmentColor = worm3.Color(0, 0, 255);
    
    matrix.begin();
    matrix.setBrightness(5);
}
