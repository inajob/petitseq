#include <Arduboy2.h>
#include "ArduboyTones.h"
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);

#include "Context.h"
#include "Player.h"
#include "Title.h"
#include "Pattern.h"
#include "Track.h"
#include "PView.h"
#include "Params.h"
#include "MultiTunes.h"

Scene* scene;

Player player;
Title title;
Pattern pattern;
Track track;
PView pview;
Params params;
Context context;
extern volatile unsigned int d[4];
extern volatile unsigned char vol[4];

void setup() {
  soundSetup();

  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(60); // super fast

  title.init();
  pattern.init();
  track.init();
  pview.init();
  params.init();

  scene = &title;
}

void loop() {
  if (!(arduboy.nextFrame()))
  return;

  arduboy.pollButtons();

  SceneID nextSceneID = scene->run();
  scene->draw();

  arduboy.display();

  switch(nextSceneID){
    case STAY:
      break;
    case TITLE:
      scene = &title;
      break;
    case PATTERN:
      scene = &pattern;
      break;
    case TRACK:
      scene = &track;
      break;
    case PVIEW:
      scene = &pview;
      break;
    case PARAMS:
      scene = &params;
      break;
  }
}
