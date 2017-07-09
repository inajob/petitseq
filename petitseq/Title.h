#include "Scene.h"

#ifndef Title_h
#define Title_h
extern Arduboy2 arduboy;

class Title : public Scene
{
  public:
  virtual void run();
  virtual void draw();
};

#endif
