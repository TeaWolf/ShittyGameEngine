// Teawolf

// Loads the specified file into the m_textures variable
bool TextureManager::load(const std::string& file_name, const std::string& id, SDL_Renderer* renderer){
	SDL_Surface* temp_surface = IMG_Load(file_name.c_str());
	if (temp_surface == 0) 
	{
		std::cerr << "IMG_Load error: " << SDL_GetError() << std::endl;	
		return false;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	if (texture == 0) 
	{
		std::cerr << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std:endl;
		return false;
	}

	m_textures[id] = texture;
	return true;
}

// Draw a specific frame, also used for statics (which could be a source of inefficiency in the future
void TextureManager::draw_frame(const std::string& id, int x, int y, int width, int height, int current_row = 0, int current_frame = 0, SDL_Renderer& renderer, SDL_RednerFlip flip)
{	
	SDL_Rect srect, drect;
	srect.x = width * current_frame;
	srect.y = height * current_row;
	srect.width = drect.width = width;
	srect.height = drect.height = height;

	drect.x = x;
	drect.y = y;

	SDL_RenderCopyEx(renderer, m_textures[id], &srect, &drect, NULL, NULL, flip);
}
