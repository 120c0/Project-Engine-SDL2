#include "Transform.hpp"

Transform::Transform(const string __name, const Vector2f __position)
    : Component(__name), position(__position)
{
}

void Transform::update() noexcept
{
}
void Transform::setPosition(const Vector2f __position) noexcept
{
  this->setPosition(__position.x, __position.y);
}
void Transform::setPosition(const float __x, const float __y) noexcept
{
  this->position.x = __x;
  this->position.y = __y;
}
void Transform::move(const Vector2f __to) noexcept
{
  this->setPosition(
    this->getPosition().x + __to.x,
    this->getPosition().y + __to.y
  );
}
const Vector2f &Transform::getPosition() const
{
  return this->position;
}

Transform::~Transform()
{
}