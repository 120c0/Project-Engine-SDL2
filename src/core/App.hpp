#ifndef APP_H
#define APP_H

#include "math/Vector2.hpp"

#include "utils/Event.hpp"
#include "utils/Color.hpp"

#include "core/Entity.hpp"
#include "core/Window.hpp"
#include "core/TileMap.hpp"

#include "components/Transform.hpp"
#include "components/Sprite.hpp"
#include "components/Animation.hpp"

class App
{
  public:
    explicit App(const Vector2u, const string);
    virtual void run() noexcept;

    // setting and setter
    virtual void update() noexcept;
    virtual void clear() noexcept;
    virtual void display() noexcept;
 
    // - Player
    virtual void initPlayer() noexcept;
    virtual void updatePlayer() noexcept;
    // getting and setter

    virtual ~App();
  private:
    Window window;
    Event event;

    Entity player, background;
    TileMap universe_c37a;
    bool player_right, player_left;
    int vel_y;
};

#endif