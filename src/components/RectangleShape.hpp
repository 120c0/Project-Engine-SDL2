#ifndef RECTANGLESHAPE_H
#define RECTANGLESHAPE_H

#include "components/Transform.hpp"
#include "core/Component.hpp"
#include "core/Entity.hpp"
#include "utils/Drawable.hpp"

class RectangleShape : public Drawable, public Component 
{
  public:
    explicit RectangleShape(const string, Vector2f);

    virtual ~RectangleShape();
  private:
    virtual void draw(SDL_Renderer*) noexcept;

    Vector2f size;
    SDL_Rect rect;
};

#endif