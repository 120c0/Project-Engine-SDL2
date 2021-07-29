#include "Texture.hpp"

Texture::Texture()
{

}
Texture::Texture(const string __image_path, SDL_Renderer *__renderer)
{
  this->loadFromFile(__image_path, __renderer);
}
SDL_Texture *Texture::getTextureSDL() noexcept
{
  return this->texture;
}
const Vector2i Texture::getTextureSize() const
{
  return this->texture_size;
}
void Texture::loadFromFile(const string __image_path, SDL_Renderer *__renderer)
{
  if(!(this->texture = IMG_LoadTexture(__renderer, __image_path.c_str())))
    std::cerr << "Error: image '" << __image_path << "' not found." << endl;
  SDL_QueryTexture(this->texture, NULL, NULL, &this->texture_size.x, &this->texture_size.y);
}
Texture::~Texture()
{
  SDL_DestroyTexture(this->texture);
}