#include "App.hpp"

App::App(const Vector2u __window_size, const string __caption)
  : player_right(false), player_left(false), vel_y(0.f)
{
  this->window.create(__window_size, __caption);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGui_ImplOpenGL2_Init();
  ImGui_ImplSDL2_InitForOpenGL(this->window.getWindow(), this->window.getContext());

  this->initPlayer();
}
void App::run() noexcept
{
  while (window.isOpen())
  {
    this->update();
    this->clear();
    this->display();
  }
}

// setting and setter
void App::updatePlayer() noexcept
{
  this->player.get<Transform>("Transform")->move(Vector2f(0.f, vel_y += vel_y > 20 ? 0 : 1));
  for(auto &it : this->universe_c37a.getPlataformVector())
  {
    Sprite *a = this->player.get<Sprite>("Sprite");
    Sprite *b = it->get<Plataform>("Plataform");
    if(
      a->getLeft() < b->getRight() &&
      a->getRight() > b->getLeft() &&
      a->getTop() < b->getBottom() &&
      a->getBottom() > b->getTop() && it->get<Plataform>("Plataform")->collision
      )
    {
      this->player.get<Transform>("Transform")->setPosition (
        this->player.get<Transform>("Transform")->getPosition().x,
        it->get<Plataform>("Plataform")->getTop() - 16.f
      );
      this->vel_y = 0.f;
    }
  }
  if(this->player_left)
  {
    this->player.get<Sprite>("Sprite")->setFlip(SDL_FLIP_HORIZONTAL);
    this->player.get<Transform>("Transform")->move(Vector2f(-3.f, 0));
    this->player.get<Animation>("Animation")->setRow(1);
  }
  else if(this->player_right)
  {
    this->player.get<Sprite>("Sprite")->setFlip(SDL_FLIP_NONE);
    this->player.get<Transform>("Transform")->move(Vector2f(3.f, 0));
    this->player.get<Animation>("Animation")->setRow(1);
  }
  else
  {
    this->player.get<Animation>("Animation")->setRow(0);
  }
  this->player.update();
}
void App::update() noexcept
{
  while (this->event.pollEvent())
  {
    ImGui_ImplSDL2_ProcessEvent(&this->event.getEvent());
    if (this->event.getType() == SDL_QUIT)
      this->window.close();
    if (this->event.getType() == SDL_MOUSEBUTTONDOWN)
    {
      static int x, y;
      SDL_GetMouseState(&x, &y);
      this->player.get<Transform>("Transform")->setPosition(
        x, y
      );
      std::cout << "X: " << x << ", Y: " << y << std::endl;
    }
    if (this->event.getEvent().key.keysym.sym == SDLK_SPACE)
      this->vel_y = -10.f;
    if (this->event.getType() == SDL_KEYDOWN)
    {
      if (this->event.getEvent().key.keysym.sym == SDLK_d)
        player_right = true;
      if (this->event.getEvent().key.keysym.sym == SDLK_a)
        player_left = true;
    }
    else if (this->event.getType() == SDL_KEYUP)
    {
      if (this->event.getEvent().key.keysym.sym == SDLK_d)
        player_right = false;
      if (this->event.getEvent().key.keysym.sym == SDLK_a)
        player_left = false;
    }
  }
  this->updatePlayer();
}
void App::clear() noexcept
{
  ImGui_ImplSDL2_NewFrame();
  ImGui_ImplOpenGL2_NewFrame();
  ImGui::NewFrame();

  ImGui::Begin("Menu");

  ImGui::Text("Click inside home for spawn player.");

  ImGui::End();
  
  ImGui::Render();
  this->window.clear(Color(179,224,242, 255));
}
void App::display() noexcept
{
  this->window.draw(*this->background.get<Drawable>("Sprite"));
  this->window.draw(this->universe_c37a);
  this->window.draw(*this->player.get<Drawable>("Sprite"));

  ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
  this->window.display();
}

void App::initPlayer() noexcept
{
  this->universe_c37a.load("../data/map/map.tmx", "../data/assets/tileset.png", this->window.getRenderer());
  this->background.add(new Transform("Transform"));
  this->background.add(new Sprite("Sprite", Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT), "../data/assets/background_0.png", this->window.getRenderer()));

  this->player.add(new Sprite("Sprite", Vector2f(16.f, 16.f), "../data/assets/jhon.png", this->window.getRenderer()));
  this->player.add(new Transform("Transform", Vector2f(354, 353)));
  this->player.add(new Animation("Animation", 5, 2, 100));
}
// getting and setter

App::~App()
{
  ImGui_ImplSDL2_Shutdown();
  ImGui_ImplOpenGL2_Shutdown();
  ImGui::DestroyContext();
}