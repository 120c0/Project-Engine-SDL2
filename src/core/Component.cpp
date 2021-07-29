#include "Component.hpp"

Component::Component(const string __name)
  : name(__name), started(false)
{

}

void Component::setEntity(Entity *__entity) noexcept
{
  this->entity = __entity;
}
Entity *Component::getEntity() noexcept
{
  return this->entity;
}
void Component::update() noexcept
{
}
void Component::start() noexcept
{
  this->started = true;
}
const string &Component::getName() const
{
  return this->name;
}

Component::~Component()
{
}