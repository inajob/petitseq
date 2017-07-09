#include <Arduboy2.h>
#include "Context.h"

#ifndef Player_h
#define Player_h
extern Arduboy2 arduboy;
extern Context context;

class Player
{
  public:
  byte seek;
  byte trackPos;
  void init();
  void run();
};

#endif
