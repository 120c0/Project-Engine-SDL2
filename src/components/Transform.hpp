#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "core/Component.hpp"
#include "math/Vector2.hpp"

class Transform : public Component
{
  public:
    explicit Transform(const string, const Vector2f = Vector2f(0, 0));

    virtual void update() noexcept;

    virtual void setPosition(const Vector2f) noexcept;
    virtual void setPosition(const float, const float) noexcept;
    virtual void move(const Vector2f) noexcept;

    virtual const Vector2f &getPosition() const;

    virtual ~Transform();
  private:
    Vector2f position;
};

#endif