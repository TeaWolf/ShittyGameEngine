// Teawolf

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <string>

class TextureManager
{
public:
	bool load(const std::string& file_name, const std::string& id, SDL_Renderer* renderer);

	void draw_frame(const std::string& id, int x, int y, int width, int height, int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> m_textures;
};
