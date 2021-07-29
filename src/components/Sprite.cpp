#include "Sprite.hpp"

Sprite::Sprite(const string __name, const Vector2f __size, const string __image_path, SDL_Renderer *__renderer)
    : Component(__name), flip(SDL_FLIP_NONE), angle(0)
{
  this->texture.loadFromFile(__image_path, __renderer);
  this->point = {
      (int)__size.x / 2,
      (int)__size.y / 2};
  this->texture_transform = {
      0, 0,
      this->texture.getTextureSize().x,
      this->texture.getTextureSize().y};
  this->transform = {
      0, 0, (int)__size.x, (int)__size.y};
}
// getter and getting
const SDL_Rect &Sprite::getTransformRect() noexcept
{
  return this->transform;
}
const SDL_Rect &Sprite::getTextureTransformRect() noexcept
{
  return this->texture_transform;
}
const int &Sprite::getAngle() const noexcept
{
  return this->angle;
}
const SDL_RendererFlip &Sprite::getFlip() const noexcept
{
  return this->flip;
}
int Sprite::getBottom() const noexcept
{
  return this->transform.y + this->transform.h;
}
int Sprite::getRight() const noexcept
{
  return this->transform.x + this->transform.w;
}
int Sprite::getLeft() const noexcept
{
  return this->transform.x;
}
int Sprite::getTop() const noexcept
{
  return this->transform.y;
}

// setter and setting
void Sprite::setFlip(const SDL_RendererFlip __flip) noexcept
{
  this->flip = __flip;
}
void Sprite::setAngle(const int __angle) noexcept
{
  this->angle = __angle;
}
void Sprite::setTextureRect(const SDL_Rect __rect) noexcept
{
  this->texture_transform = __rect;
}
void Sprite::setSize(const float __width, const float __height) noexcept
{
  this->transform.w = __width;
  this->transform.h = __height;
}
void Sprite::setSize(const Vector2f __size) noexcept
{
  this->transform.w = __size.x;
  this->transform.h = __size.y;
}
void Sprite::setTransformRect(const SDL_Rect __rect) noexcept
{
  this->transform = __rect;
}
void Sprite::draw(SDL_Renderer *__renderer) noexcept
{
  this->update();
  SDL_RenderCopyEx(
      __renderer, this->texture.getTextureSDL(),
      &this->texture_transform, &this->transform,
      this->angle, &this->point, this->flip);
}
void Sprite::update() noexcept
{
  const Vector2f position = this->getEntity()->get<Transform>("Transform")->getPosition();
  this->transform = {
      (int)std::round(position.x),
      (int)std::round(position.y),
      this->transform.w,
      this->transform.h};
}
Sprite::~Sprite()
{
}