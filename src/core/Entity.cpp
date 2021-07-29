#include "Entity.hpp"

Entity::Entity()
{
}
// setting and setter
void Entity::add(Component *__component) noexcept
{
  if (!this->has(__component->getName()))
  {
    __component->setEntity(this);
    this->components[__component->getName()] = __component;
  }
}
void Entity::remove(const string __name) noexcept
{
  if (this->has(__name))
    this->components.erase(__name);
}
void Entity::update() noexcept
{
  for (auto &element : this->components)
    if(!element.second->started)
      element.second->start();
    else
      element.second->update();
}
// getting and getter
bool Entity::has(const string __name) const
{
  return this->components.find(__name) != this->components.end();
}

Entity::~Entity()
{
  for (auto it : this->components)
    delete it.second;
}