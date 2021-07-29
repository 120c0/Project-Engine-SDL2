#include "Plataform.hpp"

Plataform::Plataform(const string __name, const Vector2f __size, const string __image_path, SDL_Renderer *__renderer, const bool __collision)
  : Sprite(__name, __size, __image_path, __renderer), collision(__collision)
{
}
Plataform::~Plataform()
{

}