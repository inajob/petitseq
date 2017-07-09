#include "Title.h"

PROGMEM const unsigned char logo[] = {0xc4, 0x44, 0x47, 0x01, 0x9f, 0x90, 0x0f, 0xe1, 0x4f, 0x90, 0x1f, 0x01, 0x1f, 0x10, 0x1c, 0x04,
0x05, 0x05, 0x07, 0x00, 0x4f, 0xea, 0xe0, 0x7f, 0x00, 0x04, 0x03, 0x1c, 0x22, 0x32, 0x3c, 0x00};

void Title::init(){
  cursor = 0;
  cursorH = 0;
  context.speed = 5;
}

SceneID Title::run(){
  if(arduboy.justPressed(A_BUTTON)){
    switch(cursorH){
      case 0:
      switch(cursor){
        case 0: context.patternNo = 0; return PATTERN;
        case 1: context.patternNo = 1; return PATTERN;
        case 2: context.patternNo = 2; return PATTERN;
        case 3: context.patternNo = 3; return PATTERN;
        case 4: context.patternNo = 4; return PATTERN;
        case 5: context.patternNo = 5; return PATTERN;
      }
      break;
      case 1:
      switch(cursor){
        case 0: return TRACK;
        case 1: return PARAMS;
      }
    }
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(cursor > 0){
      cursor --;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(cursor < 5){
      cursor ++;
    }
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
    if(cursorH > 0){
      cursorH --;
    }
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
    if(cursorH < 1){
      cursorH ++;
    }
  }

  return STAY;
}

void Title::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("PETITSEQ"));

  arduboy.setCursor(9,9);
  arduboy.print(F("P 0"));
  arduboy.setCursor(9,9 + 9 * 1);
  arduboy.print(F("P 1"));
  arduboy.setCursor(9,9 + 9 * 2);
  arduboy.print(F("P 2"));
  arduboy.setCursor(9,9 + 9 * 3);
  arduboy.print(F("P 3"));
  arduboy.setCursor(9,9 + 9 * 4);
  arduboy.print(F("P 4"));
  arduboy.setCursor(9,9 + 9 * 5);
  arduboy.print(F("P 5"));

  arduboy.setCursor(9+64,9);
  arduboy.print(F("TRACK"));
  arduboy.setCursor(9+64,9 + 9 * 1);
  arduboy.print(F("PARAMS"));

  arduboy.setCursor(48,9 + 9 * 5);
  arduboy.print(F("by @ina_ani"));



  arduboy.setCursor(cursorH * 64,9 + 9 * cursor);
  if(arduboy.everyXFrames(2)){
    arduboy.print(F(">"));
  }

  arduboy.drawBitmap(64 + 32, 36, logo, 16, 16, 1);
}
