#include "Clock.hpp"

Clock::Clock()
  : begin_tick(SDL_GetTicks())
{
}

int Clock::getTimeAsMilliseconds() const noexcept
{
  return SDL_GetTicks() - begin_tick;
}
void Clock::restart() noexcept
{
  this->begin_tick = SDL_GetTicks();
}