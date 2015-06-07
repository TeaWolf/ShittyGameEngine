// Teawolf

#include "object_load_parameters.h"

ObjectLoadParameters::ObjectLoadParameters(
	int p_x, int p_y,
	double p_vel_x, double p_vel_y,
	double p_acc_x, double p_acc_y,
	int p_width, int p_height,
	const std::string& p_texture_id)
:
	x(p_x), y(p_y),
	vel_x{p_vel_x}, vel_y{p_vel_y},
	acc_x{p_acc_x}, acc_y{p_acc_y},
	width(p_width), height(p_height),
	texture_id(p_texture_id)
{}
