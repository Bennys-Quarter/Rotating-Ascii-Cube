/*
 * c_graphics.c
 *
 *  Created on: Nov 6, 2025
 *      Author: benny
 */

#include "c_graphics.h"

Vec2 projection_2d(Vec3 vert, int scr_width, int scr_height)
{
	/* Calculates the 3D to 2D projected coordinates
	 * with the origin in the center
	 */

	double y_m = 2*(1.0/0.3333333);
	double x_m = 4*(1.0/0.3333333);
	double x_p = (vert.x * x_m) / (vert.z + 2) + scr_width/2;
	double y_p = (vert.y * y_m) / (vert.z + 2) + scr_height/2;

	Vec2 coo = {round(x_p), round(y_p)};
	return coo;
}
