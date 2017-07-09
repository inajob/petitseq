#include "Player.h"
extern volatile unsigned int d[4];
extern volatile unsigned char vol[4];

void Player::init(){
  seek = 0;
  trackPos = 0;
}

void Player::run(){
  // sound generate
  if(arduboy.everyXFrames(context.speed)){
    if(context.track[0][trackPos] != 255){
    d[0] = context.tones[context.pattern[context.track[0][trackPos]][seek]];
    vol[0] = 127;
    }else{
      vol[0] = 0;
    }
    if(context.track[1][trackPos] != 255){
    d[1] = context.tones[context.pattern[context.track[1][trackPos]][seek]];
    vol[1] = 127;
    }else{
      vol[1] = 0;
    }
     if(context.track[2][trackPos] != 255){
    d[2] = context.tones[context.pattern[context.track[2][trackPos]][seek]];
    vol[2] = 127;
    }else{
      vol[2] = 0;
    }

    seek ++;
    if(seek == 8){
      seek = 0;
      trackPos ++;
      if(trackPos == 8){
        trackPos = 0;
      }
    }
    if(seek&1){
      arduboy.setRGBled(16, 0, 0);
    }else{
      arduboy.setRGBled(0, 0, 0);
    }
  }

}
