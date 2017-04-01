
/**
 * This is a port of the Wyolum Badger Album sketch from ePaper display to an
 * Adafruit TFT Feather Wing.
 */

#include <SD.h>
#include <Adafruit_ILI9341.h> // Hardware-specific library
#include <Adafruit_STMPE610.h>

/**
 * One day, hopefully, Arduino will support relative filesystem paths.
 */
#include "C:\home\owner\versioning\github\electronics\src\main\arduino\adafruit\feather-wings\ILI9341-tft\swiper\swiper\board-compatibility.h"
#include "C:\home\owner\versioning\github\electronics\src\main\arduino\adafruit\feather-wings\ILI9341-tft\swiper\swiper_oo\TftFeatherWing.h"

#include "filesystem.h"

TftFeatherWing tftWing;

void loop() 
{
    bool update_needed = false;
    
  long current = millis();

  // ser_interact();
  if(false)//analogRead(MODE_PIN) > 512)
  {
//    Serial.println("Mode");
    prev_wif();
    update_needed = true;
  }
  
    // Retrieve a point  
    TS_Point p = ts.getPoint();
    
    // check the status of the swipe direction
    boolean swiped = xSwipeCheck(p.x);    
    if(swiped)//digitalRead(SEL_PIN))
    {
//      Serial.println("Sel");
        next_wif();
        update_needed = true;
    }
    
  if(false)//digitalRead(UP_PIN))
  {
//    Serial.println("Up");
    prev_dir();
    update_needed = true;
  }
  if(false)//digitalRead(DOWN_PIN))
  {
//     Serial.println("down");
    next_dir();
    update_needed = true;
  }
  
  if(update_needed)
  {
    lastWakeTime = current;
    display();
  } 
}

void setup() 
{
    Serial.begin(9600);
    
    delay(100);
    
    Serial.println("Hello image browsing world!");
    
    setupSdCard();
 
    setupTft();
    bmpDraw("ALBUM/B/A.bmp", 0, 0);
//    bmpDraw("red.bmp", 0, 0);
}