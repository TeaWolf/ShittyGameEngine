// Teawolf

#pragma once

#include <string>

class ObjectLoadParameters
{
public:
	ObjectLoadParameters(
		int p_x, int p_y,
		double p_vel_x, double p_vel_y,
		double p_acc_x, double p_acc_y,
		int p_width, int p_height,
		const std::string& p_texture_id
	);
	virtual ~ObjectLoadParameters() = default;

	// TODO some fucking accessors please...
	int x, y, width, height;
	double vel_x, vel_y, acc_x, acc_y;
	std::string texture_id;
};
