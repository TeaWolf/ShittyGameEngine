// Teawolf

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <string>

class TextureManager
{
public:
	static TextureManager* instance();

	bool load(const std::string& file_name, const std::string& id, SDL_Renderer* renderer);

	void draw_frame(const std::string& id, int x, int y, int width, int height, int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void clean();
	void clear_texture(const std::string& file_name);

private:
	TextureManager() = default;
	~TextureManager() = default;
	static TextureManager* m_instance;

	std::map<std::string, SDL_Texture*> m_textures;
};
