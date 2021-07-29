#ifndef PLATAFORM_H
#define PLATAFORM_H

#include "Sprite.hpp"

class Plataform : public Sprite
{
  public:
    explicit Plataform(const string, const Vector2f, const string, SDL_Renderer*, const bool = false);

    virtual const bool &getCollision() const noexcept {return this->collision; };

    virtual ~Plataform();
    bool collision;
  private:
};

#endif