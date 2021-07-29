#ifndef ANIMATINO_H
#define ANIMATION_H

#include "components/Sprite.hpp"
#include "core/Component.hpp"
#include "core/Entity.hpp"
#include "utils/Clock.hpp"

class Animation : public Drawable, public Component
{
  public:
    explicit Animation(const string, int, int, int);

    virtual void setColumn(const int) noexcept;
    virtual void setRow(const int) noexcept;
    virtual const int& getColumn() const noexcept;
    virtual const int& getRow() const noexcept;

    virtual void start() noexcept;
    virtual void update() noexcept;

    virtual ~Animation();
  private:
    int max_columns, max_rows, delay, row, column;
    Clock clock;

    virtual void draw(SDL_Renderer*) noexcept;
};

#endif