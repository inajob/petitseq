#include <Arduboy2.h>
#include "ArduboyTones.h"
#include "Context.h"

#ifndef Scene_h
#define Scene_h

enum SceneID {
STAY,
TITLE,
PATTERN,
TRACK,
PVIEW,
PARAMS
};

class Scene
{
  public:
  virtual void init();
  virtual SceneID run();
  virtual void draw();
};

#endif
