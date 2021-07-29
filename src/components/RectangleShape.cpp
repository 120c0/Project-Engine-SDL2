#include "RectangleShape.hpp"

RectangleShape::RectangleShape(const string __name, Vector2f __size)
  : Component(__name), size(__size)
{
}

RectangleShape::~RectangleShape()
{
}

void RectangleShape::draw(SDL_Renderer *__renderer) noexcept
{
  const Vector2f position = this->getEntity()->get<Transform>("Transform")->getPosition();
  this->rect = {
    (int) position.x,
    (int) position.y,
    (int) this->size.x,
    (int)  this->size.y
  };
  SDL_SetRenderDrawColor(__renderer, 255, 255, 0, 255);
  SDL_RenderFillRect(__renderer, &rect);
}