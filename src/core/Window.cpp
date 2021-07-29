#include "Window.hpp"

Window::Window(const Vector2u __window_size, const string __caption)
  : is_open(false)
{
  this->create(__window_size, __caption);
}
// setting and setter
void Window::create(const Vector2u __window_size, const string __caption) noexcept
{
  WindowOpenGLSetting::settingSDL();
  WindowOpenGLSetting::settingOpenGL();

  this->is_open = (this->window = SDL_CreateWindow(
    __caption.c_str(),
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    __window_size.x, __window_size.y,
    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN)
  ) != NULL;
  this->renderer = SDL_CreateRenderer (
    this->window, -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );

  this->context = SDL_GL_CreateContext(this->window);

  SDL_GL_MakeCurrent(this->window, this->context);
  SDL_GL_SetSwapInterval(1);
}
void Window::close() noexcept
{
  this->is_open = false;
}
void Window::display() noexcept
{
  SDL_GL_SwapWindow(this->window);
}
void Window::clear(const Color __color) noexcept
{
  glClearColor((float)__color.r / 255.f, (float)__color.g / 255.f, (float)__color.b / 255.f, (float)__color.a / 255.f);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
void Window::draw(Drawable &__drawable) noexcept
{
  __drawable.draw(this->getRenderer());
}
// getting and getter
bool Window::isOpen() const
{
  return this->is_open;
}
SDL_Renderer *Window::getRenderer() noexcept
{
  return this->renderer;
}
SDL_Window *Window::getWindow() noexcept
{
  return this->window;
}
SDL_GLContext &Window::getContext() noexcept
{
  return this->context;
}

Window::~Window()
{
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
  SDL_GL_DeleteContext(this->context);
  SDL_Quit();
}