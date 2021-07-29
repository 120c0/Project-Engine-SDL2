#include "Event.hpp"

int Event::getType() noexcept
{
  return this->event.type;
}
const SDL_Event &Event::getEvent() const
{
  return this->event;
}
int Event::pollEvent() noexcept
{
  return SDL_PollEvent(&this->event);
}