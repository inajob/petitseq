#include "Scene.h"

#ifndef Pattern_h
#define Pattern_h
extern Arduboy2 arduboy;
extern ArduboyTones sound;
extern Context context;

class Pattern : public Scene
{
  byte cursor;
  byte cursorY;
  byte seek;
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};



#endif
