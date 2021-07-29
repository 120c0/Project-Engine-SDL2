#ifndef SPRITE_H
#define SPRITE_H

#include "core/Texture.hpp"
#include "core/Entity.hpp"
#include "core/Component.hpp"
#include "Transform.hpp"
#include "utils/Drawable.hpp"
#include "core/Window.hpp"

class Sprite : public Component, public Drawable
{
  public:
    explicit Sprite(const string, const Vector2f, const string, SDL_Renderer*);

    // getter and getting
    virtual const SDL_Rect& getTextureTransformRect() noexcept;
    virtual const SDL_Rect& getTransformRect() noexcept;
    virtual const SDL_RendererFlip &getFlip() const noexcept;
    virtual const int& getAngle() const noexcept;

    // setter and setting
    virtual void setTextureRect(const SDL_Rect) noexcept;
    virtual void setTransformRect(const SDL_Rect) noexcept;
    virtual void setSize(const float, const float) noexcept;
    virtual void setSize(const Vector2f) noexcept;
    virtual void setAngle(const int) noexcept;
    virtual void setFlip(const SDL_RendererFlip) noexcept;
    virtual int getLeft() const noexcept;
    virtual int getRight() const noexcept;
    virtual int getTop() const noexcept;
    virtual int getBottom() const noexcept;

    virtual void update() noexcept;

    virtual ~Sprite();
  private:
    friend class TileMap;
    Texture texture;
    SDL_Rect texture_transform;
    SDL_Rect transform;

    int angle;
    SDL_Point point;
    SDL_RendererFlip flip;

    virtual void draw(SDL_Renderer*) noexcept;
};

#endif