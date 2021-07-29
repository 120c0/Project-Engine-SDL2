#ifndef CLOCK_H
#define CLOCK_H

#include <SDL2/SDL.h>

class Clock
{
  public:
    Clock();

    virtual int getTimeAsMilliseconds() const noexcept;
    virtual void restart() noexcept;

    virtual ~Clock() = default;
  private:
    int begin_tick;
};

#endif