#include "Scene.h"

#ifndef Params_h
#define Params_h
extern Arduboy2 arduboy;

class Params : public Scene
{
  byte cursor;
  bool selected;
  void applyShift();
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
