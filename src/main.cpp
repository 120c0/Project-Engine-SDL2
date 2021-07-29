#include "core/App.hpp"
#include "const.hpp"

int main()
{
  App(Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_CAPTION).run();
  return EXIT_SUCCESS;
}
