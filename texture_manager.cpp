// Teawolf

#include "texture_manager.h"

// Loads the specified file into the m_textures variable
bool TextureManager::load(const std::string& file_name, const std::string& id, SDL_Renderer* renderer){
	std::clog << "Loading " << file_name << " as " << id << "..." << std::endl;

	SDL_Surface* temp_surface = IMG_Load(file_name.c_str());
	if (temp_surface == 0) 
	{
		std::cerr << "IMG_Load error: " << SDL_GetError() << std::endl;	
		return false;
	}

	std::clog << "Successfully loaded " << id << " as temporary surface" << std::endl;
	std::clog << "Creating texture for " << id << "..." << std::endl;

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	if (texture == 0) 
	{
		std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
		return false;
	}
	
	std::clog << "Successfully created the texture for " << id << std::endl;
	std::clog << "Adding " << id << " to the map..." << std::endl;

	m_textures[id] = texture;

	std::clog << "Successfuly added " << id << "to the map" << std::endl;

	return true;
}

// Draw a specific frame, also used for statics (which could be a source of inefficiency in the future
void TextureManager::draw_frame(const std::string& id, int x, int y, int width, int height, int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip)
{	
	SDL_Rect srect, drect;
	srect.x = width * current_frame;
	srect.y = height * current_row;
	srect.w = drect.w = width;
	srect.h = drect.h = height;

	drect.x = x;
	drect.y = y;

	SDL_RenderCopyEx(renderer, m_textures[id], &srect, &drect, 0, 0, flip);
}
