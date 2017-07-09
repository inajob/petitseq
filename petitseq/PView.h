#include "Scene.h"

#ifndef PView_h
#define PView_h
extern Arduboy2 arduboy;
extern ArduboyTones sound;
extern Context context;

class PView : public Scene
{
  char patternNo;
  byte seek;
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
