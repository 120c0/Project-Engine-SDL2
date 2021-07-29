#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <cstring>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "math/Vector2.hpp"
#include "utils/WindowOpenGLSetting.hpp"
#include "utils/Color.hpp"
#include "utils/Drawable.hpp"

using namespace std;

class Window
{
  public:
    Window() = default;
    explicit Window(const Vector2u, const string);

    // setting and setter
    virtual void create(const Vector2u, const string) noexcept;
    virtual void close() noexcept;
    virtual void display() noexcept;
    virtual void clear(const Color = Color::Black) noexcept;
    virtual void draw(Drawable&) noexcept;

    // getting and getter
    virtual bool isOpen() const;
    virtual SDL_Renderer *getRenderer() noexcept;
    virtual SDL_Window *getWindow() noexcept;
    virtual SDL_GLContext &getContext() noexcept;

    virtual ~Window();
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_GLContext context;
    bool is_open;
};

#endif