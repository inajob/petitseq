#include "Track.h"
#include "Player.h"

extern volatile unsigned int d[4];
extern volatile unsigned char vol[4];
extern unsigned int tones[];
extern Player player;


void Track::init(){
  for(byte i = 0; i < 8; i ++){
    for(byte j = 0; j < 8; j ++){
      context.track[i][j] = 255;
    }
  }
  context.trackNo = 0;
  context.trackPos = 0;
}

SceneID Track::run(){
  if(arduboy.justPressed(B_BUTTON)){
    vol[0] = 0;
    vol[1] = 0;
    vol[2] = 0;
    return TITLE;
  }
  if(arduboy.justPressed(A_BUTTON)){
    vol[0] = 0;
    vol[1] = 0;
    vol[2] = 0;
    return PVIEW;
  }
  if(arduboy.justPressed(LEFT_BUTTON)){
    if(context.trackPos > 0){
      context.trackPos --;
    }
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
    if(context.trackPos < 7){
      context.trackPos ++;
    }
  }
  if(arduboy.justPressed(DOWN_BUTTON)){
    if(context.trackNo < 1){
      context.trackNo ++;
    }
  }
  if(arduboy.justPressed(UP_BUTTON)){
    if(context.trackNo > 0){
      context.trackNo --;
    }
  }

  player.run();
  return STAY;
}

void Track::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("PETITSEQ TRACK"));


  for(byte i = 0; i < 3; i ++){
    for(byte j = 0; j < 8; j ++){
      if(context.track[i][j] != 255){
        arduboy.setCursor(j*8*2, 9 + i*20);
        arduboy.print(context.track[i][j]);
        for(byte k = 0; k < 8; k ++){
          if(context.pattern[context.track[i][j]][k] != 0){
            arduboy.fillRect(j*8*2 + k*2, 9 + i*20 + 20 - context.pattern[context.track[i][j]][k] , 2, 1);
          }
        }
      }else{
        //arduboy.drawRect(j*8,i*20, 8,20);
      }
    }
  }
  if(arduboy.everyXFrames(2)){
    //cursor
    arduboy.drawRect(context.trackPos*8*2, 9 + context.trackNo*20 , 8*2, 20);
  }
  //seek
  arduboy.drawFastVLine((player.trackPos * 8 + player.seek)*2, 9, 64);
}
