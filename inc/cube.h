/*
 * cube.h
 *
 *  Created on: Nov 6, 2025
 *      Author: benny
 */

#ifndef INC_CUBE_H_
#define INC_CUBE_H_

#include "vec.h"
#include "canvas.h"
#include "c_graphics.h"
#include <math.h>

typedef char AsciiOperation(int);

typedef struct
{
	Vec3 vertex[8];
	Vec2 edge[12];
	Vec3 faces[12];
	Vec3 rotation;
}Cube;

void cube_init(Cube *c);
void rotate(Cube* cnv);
void draw_cube(String* cnv, Cube* c);
void draw_verticies(String *cnv, Cube* c, char ch, int n_vert);
void draw_edges(String *cnv, Cube* c, char ch, int n_edges);
void draw_faces(String *cnv, Cube* c, AsciiOperation *ascii_fun, int n_faces);

#endif /* INC_CUBE_H_ */
