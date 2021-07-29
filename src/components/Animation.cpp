#include "Animation.hpp"

Animation::Animation(const string __name, int __max_columns, int __max_rows, int __delay)
  : Component(__name), max_columns(__max_columns), max_rows(__max_rows), delay(__delay), row(0), column(0)
{
  
}
void Animation::start() noexcept
{
  Component::start();
  this->getEntity()->get<Sprite>("Sprite")->setTextureRect (
    SDL_Rect {
      0,0,
      this->getEntity()->get<Sprite>("Sprite")->getTextureTransformRect().w / this->max_columns,
      this->getEntity()->get<Sprite>("Sprite")->getTextureTransformRect().h / this->max_rows
    }
  );
}
void Animation::setColumn(const int __column) noexcept
{
  this->column = __column;
}
void Animation::setRow(const int __row) noexcept
{
  this->row = __row;
}
const int& Animation::getColumn() const noexcept
{
  return this->column;
}
const int& Animation::getRow() const noexcept
{
  return this->row;
}
void Animation::update() noexcept
{
  if(clock.getTimeAsMilliseconds() > delay)
  {
    if(this->column >= this->max_columns)
      this->column = 0;
    this->getEntity()->get<Sprite>("Sprite")->setTextureRect (
      SDL_Rect {
        this->getEntity()->get<Sprite>("Sprite")->getTextureTransformRect().w * column++,
        this->getEntity()->get<Sprite>("Sprite")->getTextureTransformRect().h * row,
        this->getEntity()->get<Sprite>("Sprite")->getTextureTransformRect().w,
        this->getEntity()->get<Sprite>("Sprite")->getTextureTransformRect().h
      }
    );
    clock.restart();
  }
}
Animation::~Animation()
{

}
void Animation::draw(SDL_Renderer *) noexcept
{

}