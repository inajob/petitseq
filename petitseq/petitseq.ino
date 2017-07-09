#include <Arduboy2.h>
Arduboy2 arduboy;

#include "Title.h"

Scene* scene;

Title title;

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(60); // super fast

  scene = &title;
}

void loop() {
  if (!(arduboy.nextFrame()))
  return;
    
  scene->run();
  scene->draw();

  arduboy.display();
}
