#include "Pattern.h"
extern volatile unsigned int d[4];
extern volatile unsigned char vol[4];

void Pattern::init(){
  for(byte i = 0; i < 8; i ++){
    for(byte j = 0; j < 8; j ++){
      context.pattern[i][j] = 0;
    }
  }
  cursor = 0;
  cursorY = 0;
  seek = 0;
}

SceneID Pattern::run(){
  // button event
  if(arduboy.justPressed(B_BUTTON)){
    vol[0] = 0;
    return TITLE;
  }
  if(arduboy.justPressed(A_BUTTON)){
    context.pattern[context.patternNo][cursor] = cursorY;
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
    if(cursor > 0){
      cursor --;
    }
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
    if(cursor < 7){
      cursor ++;
    }
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(cursorY < 21){
      cursorY ++;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(cursorY > 0){
      cursorY --;
    }
  }

  // sound generate
  if(arduboy.everyXFrames(context.speed)){
    //sound.tone(tones[context.pattern[context.patternNo][seek]],100);
    d[0] = context.tones[context.pattern[context.patternNo][seek]];
    vol[0] = 128;
    seek ++;
    seek = seek & 7;

    if(seek&1){
      arduboy.setRGBled(16, 0, 0);
    }else{
      arduboy.setRGBled(0, 0, 0);
    }
  }

  return STAY;
}

void Pattern::draw(){
  const byte SIZEY = 3;

  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("PETITSEQ PATTERN"));

  for(byte i = 0; i < 8; i ++){
    arduboy.drawRect(i*8, 64 - (context.pattern[context.patternNo][i] + 1) * SIZEY, 7, SIZEY);
  }
  if(arduboy.everyXFrames(2)){
    arduboy.fillRect(cursor * 8, 64 - (cursorY + 1) * SIZEY, 8, SIZEY);
  }
  arduboy.drawFastVLine(seek * 8, 9, 64);
}
