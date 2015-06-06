// Teawolf

#pragma once

#include <string>

class ObjectLoadParameters
{
public:
	ObjectLoadParameters(int p_x, int p_y, int p_width, int p_height, const std::string& p_texture_id);
	~ObjectLoadParameters() {}

	int x, y, width, height;
	std::string texture_id;
};
