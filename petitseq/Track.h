#include "Scene.h"

#ifndef Track_h
#define Track_h
extern Arduboy2 arduboy;

class Track : public Scene
{
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
