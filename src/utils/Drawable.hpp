#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL2/SDL.h>

class Drawable
{
  friend class Window;
  friend class TileMap;
  virtual void draw(SDL_Renderer*) noexcept = 0;
};

#endif