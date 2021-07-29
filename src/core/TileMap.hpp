#ifndef TILEMAP_H
#define TILEMAP_H

#include "utils/Drawable.hpp"
#include "components/Plataform.hpp"
#include "components/Sprite.hpp"
#include "Entity.hpp"
#include "Texture.hpp"
#include <vector>

#include <tmx/tmx.h>

class TileMap : public Drawable
{
  public:
    TileMap();
    explicit TileMap(const string, const string, SDL_Renderer*);

    virtual void load(const string, const string, SDL_Renderer*) noexcept;
    virtual void loadLayer(tmx_map*, tmx_layer*) noexcept;
    virtual void loadAllLayers(tmx_map*, tmx_layer*) noexcept;
    virtual const vector<Entity*> getPlataformVector() const noexcept;

    virtual ~TileMap();

  private:
    virtual void draw(SDL_Renderer*) noexcept;
    tmx_map *map;
    std::vector<Entity*> plataforms;
    string image_path;
};

#endif