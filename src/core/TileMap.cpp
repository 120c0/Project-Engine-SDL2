#include "TileMap.hpp"

SDL_Renderer *__renderer__ = NULL;

void *__TMXLoadTexture__(const char* path)
{
  return IMG_LoadTexture(__renderer__, path);
}

TileMap::TileMap()
{
}
TileMap::TileMap(const string __xml_file, const string __tileset, SDL_Renderer *__renderer)
{
  this->load(__xml_file, __tileset, __renderer);
}

void TileMap::load(const string __xml_file, const string __tileset, SDL_Renderer *__renderer) noexcept
{ 
  __renderer__ = __renderer;
	this->image_path = __tileset;
  this->map = tmx_load(__xml_file.c_str());

  if(!this->map)
    fputs("ERROR::tmx_load()\n", stderr);

  tmx_img_load_func = __TMXLoadTexture__;
  tmx_img_free_func = (void (*)(void*)) SDL_DestroyTexture;
	
	this->loadAllLayers(this->map, this->map->ly_head);
}

void TileMap::draw(SDL_Renderer *__renderer) noexcept
{
	for(auto &it : this->plataforms)
		it->get<Plataform>("Plataform")->draw(__renderer);
}
const vector<Entity*> TileMap::getPlataformVector() const noexcept
{
	return this->plataforms;
}
void TileMap::loadLayer(tmx_map *__map, tmx_layer *layer) noexcept {
	unsigned long i, j;
	unsigned int gid, x, y, w, h, flags, id;
	float op;
	tmx_tileset *ts;
	void* image;
	op = layer->opacity;
	for (i=0; i<__map->height; i++) {
		for (j=0; j<__map->width; j++) {
			gid = (layer->content.gids[(i*__map->width)+j]) & TMX_FLIP_BITS_REMOVAL;
			if (__map->tiles[gid] != NULL) {
				ts = __map->tiles[gid]->tileset;
				x  = __map->tiles[gid]->ul_x;
				y  = __map->tiles[gid]->ul_y;
				w  = ts->tile_width;
				h  = ts->tile_height;

				id = __map->tiles[gid]->id;
				Entity *plataform = new Entity();
					
				plataform->add(new Transform("Transform", Vector2f((float) (j*ts->tile_width), (float) (i*ts->tile_height))));
				plataform->add(new Plataform("Plataform", Vector2f(w, h), this->image_path, __renderer__, (id != 53)));
				plataform->get<Plataform>("Plataform")->setTextureRect(SDL_Rect {(int) x, (int) y, (int) w, (int) h});

				plataforms.push_back(plataform);
				
				// flags = (layer->content.gids[(i*map->width)+j]) & ~TMX_FLIP_BITS_REMOVAL;
				// draw_tile(this->texture.getTextureSDL(), x, y, w, h, j*ts->tile_width, i*ts->tile_height, op, flags);;
			}
		}
	}
}

void TileMap::loadAllLayers(tmx_map *__map, tmx_layer *layers) noexcept {
	while (layers) {
		if (layers->visible) {
			if (layers->type == L_GROUP) {
				loadAllLayers(__map, layers->content.group_head);
			}
			if (layers->type == L_LAYER) {
				loadLayer(__map, layers);
			}
		}
		layers = layers->next;
	}
}

TileMap::~TileMap()
{
	for(auto &it : this->plataforms)
		delete it;
}