#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <SDL2/SDL.h>

class Event
{
  public:
    Event() noexcept = default;

    virtual int getType() noexcept;
    virtual const SDL_Event &getEvent() const;
    virtual int pollEvent() noexcept;

    virtual ~Event() noexcept = default;
  private:
    SDL_Event event;
};

#endif