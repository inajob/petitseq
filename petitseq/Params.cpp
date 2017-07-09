#include "Params.h"
#include "Player.h"
extern volatile unsigned char vol[4];
extern Player player;

unsigned int tones[] = {
NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,
NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5,
NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6,NOTE_G6,NOTE_A6,NOTE_B6,
NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7,NOTE_G7,NOTE_A7,NOTE_B7,
NOTE_C8, NOTE_D8, NOTE_E8, NOTE_F8,NOTE_G8,NOTE_A8,NOTE_B8,
};

void Params::init(){
  cursor = 0;
  selected = false;

  context.shift = 7;
  applyShift();
}

void Params::applyShift(){
  context.tones[0] = 0;
  for(int i = 0; i < 31; i ++){
    context.tones[i + 1] = tones[i + context.shift];
  }
}

SceneID Params::run(){
  if(arduboy.justPressed(B_BUTTON)){
    vol[0] = 0;
    vol[1] = 0;
    vol[2] = 0;
    return TITLE;
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
    switch(cursor){
      case 0: // SPEED
        if(context.speed > 0){
          context.speed --;
        }
        break;
      case 1: // shift
        if(context.shift > 0){
          context.shift --;
        }
        applyShift();
        break;
    }
  }
  if(arduboy.justPressed(RIGHT_BUTTON)){
    switch(cursor){
      case 0: // SPEED
        if(context.speed < 100){
          context.speed ++;
        }
        break;
      case 1: // shift
        if(context.shift < 16){
          context.shift ++;
        }
        applyShift();
        break;
    }
  }
  player.run();
  return STAY;
}

void Params::draw(){
  arduboy.clear();
  arduboy.setCursor(0,0);
  arduboy.print(F("PETITSEQ PARAMS"));

  arduboy.setCursor(9,9);
  arduboy.print(F("SPEED:"));
  arduboy.setCursor(5*8 + 9,9);
  arduboy.print(context.speed);

  arduboy.setCursor(9,9 + 9 * 1);
  arduboy.print(F("SHIFT:"));
  arduboy.setCursor(5*8 + 9,9 + 9 * 1);
  arduboy.print((int)context.shift);

  if(arduboy.everyXFrames(2)){
    arduboy.setCursor(0 ,9 + 9 * cursor);
    arduboy.print(F(">"));
  }

}

