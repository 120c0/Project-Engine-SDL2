#ifndef WINDOWOPENGLSETTING_H
#define WINDOWOPENGLSETTING_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "const.hpp"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_opengl2.h>

class WindowOpenGLSetting
{
  public:
    static void settingOpenGL() noexcept;
    static void settingSDL() noexcept;
};

#endif