#include "Title.h"

void Title::run(){
}

void Title::draw(){
  arduboy.clear();
  arduboy.setCursor(4,9);
  arduboy.print(F("TITLE"));
}
