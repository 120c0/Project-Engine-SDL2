#include "WindowOpenGLSetting.hpp"

void WindowOpenGLSetting::settingOpenGL() noexcept
{

  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

  SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 8);

  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
}
void WindowOpenGLSetting::settingSDL() noexcept
{
  glDisable(GL_DEPTH);


  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  gluOrtho2D(0.0, (GLdouble) WINDOW_WIDTH, (GLdouble) WINDOW_HEIGHT, 0.0);
}