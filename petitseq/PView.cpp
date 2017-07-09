#include "PView.h"
extern volatile unsigned int d[4];
extern volatile unsigned char vol[4];


void PView::init(){
  patternNo = 0;
}
void PView::draw(){
  const byte SIZEY = 3;

  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("PETITSEQ TRACK PVIEW"));
  arduboy.setCursor(0,9);
  if(patternNo != -1){
    arduboy.print((int)patternNo);
    for(byte i = 0; i < 8; i ++){
      arduboy.fillRect(i*8, 64 - (context.pattern[patternNo][i] + 1) * SIZEY, 7, SIZEY);
    }

  }else{
    arduboy.print(F("none"));
  }

}
SceneID PView::run(){
  // button event
  if(arduboy.justPressed(B_BUTTON)){
    //cancel
    return TRACK;
  }
  if(arduboy.justPressed(A_BUTTON)){
    if(patternNo != -1){
      context.track[context.trackNo][context.trackPos] = patternNo;
    }else{
      context.track[context.trackNo][context.trackPos] = 255;
    }
    return TRACK;
  }


  if(arduboy.justPressed(UP_BUTTON)){
    if(patternNo > -1){
      patternNo --;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(patternNo < 5){
      patternNo ++;
    }
  }

  // sound generate
  if(arduboy.everyXFrames(context.speed)){
    //sound.tone(tones[context.pattern[context.patternNo][seek]],100);
    if(patternNo != -1){
      d[0] = context.tones[context.pattern[patternNo][seek]];
      vol[0] = 128;
      seek ++;
      seek = seek & 7;
    }
  }


  return STAY;
}
