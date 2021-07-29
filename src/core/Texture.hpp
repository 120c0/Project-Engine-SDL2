#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstring>
#include "math/Vector2.hpp"

using namespace std;

class Texture
{
  public:
    Texture();
    explicit Texture(const string, SDL_Renderer*);

    virtual SDL_Texture *getTextureSDL() noexcept;
    const Vector2i getTextureSize() const;

    virtual void loadFromFile(const string, SDL_Renderer*);

    virtual ~Texture();
  private:
    SDL_Texture *texture;
    Vector2i texture_size;
};

#endif