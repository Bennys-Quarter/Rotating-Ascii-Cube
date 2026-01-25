/*
 * cube.c
 *
 *  Created on: Nov 6, 2025
 *      Author: benny
 */
#include "cube.h"

const Cube UNIT_CUBE =
{
    .vertex =
    {
    	{-1,1,1},{1,1,1},{-1,-1,1}, {1,-1,1},
		{-1,-1,-1}, {1,-1,-1}, {1,1,-1}, {-1,1,-1}
    },
	.edge =
	{
		// 12 Outer Edges
		{0,1},{2,3},{3,1},{2,0},
		{5,6},{5,3},{1,6},{4,5},
		{4,2},{6,7},{7,0},{4,7},
	},
	.faces =
	{
		{4,5,7}, {5,6,7},{0,2,3}, {0,1,3},
		{2,3,4}, {3,4,5},{0,2,4}, {0,4,7},
		{0,1,7}, {1,6,7},{1,3,5}, {1,5,6}
	}
};


void cube_init(Cube *c)
{
	for (int i=0; i<8; i++)
	{
		c->vertex[i] = UNIT_CUBE.vertex[i];
	}

	c->rotation.x = 0.0;
	c->rotation.y = 0.0;
	c->rotation.z = 0.0;
}


void rotate(Cube* cnv)
{
	/* Rotation matrix for 3D objects
	 * x -> yaw , y -> pitch, z -> roll
	 */

	for (int i=0; i<8; i++)
	{
		cnv->vertex[i].z =
			UNIT_CUBE.vertex[i].z * (-sin(cnv->rotation.y) ) +
			UNIT_CUBE.vertex[i].y * ( cos(cnv->rotation.y) * sin(cnv->rotation.x)) +
			UNIT_CUBE.vertex[i].x * ( cos(cnv->rotation.y) * cos(cnv->rotation.x));
		cnv->vertex[i].y =
			UNIT_CUBE.vertex[i].z * (cos(cnv->rotation.z) * cos(cnv->rotation.y)) +
			UNIT_CUBE.vertex[i].y * (cos(cnv->rotation.z) * sin(cnv->rotation.y) * sin(cnv->rotation.x) - sin(cnv->rotation.z) * cos(cnv->rotation.x)) +
			UNIT_CUBE.vertex[i].x * (cos(cnv->rotation.z) * sin(cnv->rotation.y) * cos(cnv->rotation.z) + sin(cnv->rotation.z) * sin(cnv->rotation.x));
		cnv->vertex[i].x =
			UNIT_CUBE.vertex[i].z * (sin(cnv->rotation.z) * cos(cnv->rotation.y) ) +
			UNIT_CUBE.vertex[i].y * (sin(cnv->rotation.z) * sin(cnv->rotation.y) * sin(cnv->rotation.z) + cos(cnv->rotation.z) * cos(cnv->rotation.x) ) +
			UNIT_CUBE.vertex[i].x * (sin(cnv->rotation.z) * sin(cnv->rotation.y) * cos(cnv->rotation.x) - cos(cnv->rotation.z) * sin(cnv->rotation.x));
	}
}


void draw_cube(String* cnv, Cube* c, char ch)
{
	/* Update the chars in the canvas according to cube coordinates
	 *
	 */

	const int n_vert = 8;
	const int n_edges = 30;
	const int n_faces = 12;


	draw_faces(cnv, c, ch, n_faces);

	draw_edges(cnv, c, '.', n_edges);

	draw_verticies(cnv, c, 'X', n_vert);


}


void draw_verticies(String *cnv, Cube* c, char ch, int n_vert)
{
	Vec2 coo_v[n_vert];

	// Draw vertices
	for (int i= 0; i<n_vert; i++)
	{
		coo_v[i] = projection_2d(c->vertex[i], 50, 30);
		cnv[(int)coo_v[i].z].str[(int)coo_v[i].x] = ch;
	}
}


void draw_edges(String *cnv, Cube* c, char ch, int n_edges)
{
	/* draw edges of cube but not diagonal polygon lines
	 *
	 */
	for (int j = 0; j<12;j++)
	{

		int x = (int)UNIT_CUBE.edge[j].x;
		int z = (int)UNIT_CUBE.edge[j].z;
		Vec2 p0 = projection_2d(c->vertex[x], 50, 30);
		Vec2 p1 = projection_2d(c->vertex[z], 50, 30);

		Vec2 p01 = subVec2(p1, p0);
		double abs_p01 = normVec2(p01);
		int N = (int)abs_p01;

		Vec2 v_step = {p01.x / abs_p01, p01.z / abs_p01};
		Vec2 v_n = {0.0, 0.0};

		for (int i=1; i<(N); i++)
		{
			Vec2 v_add = mulVec2Scalar(v_step, i);
			v_n = addVec2(p0, v_add);

			cnv[(int)v_n.z].str[(int)v_n.x] = ch;
		}
	}

}


void draw_faces(String *cnv, Cube* c, char ch, int n_faces)
{
	/* Scanline Triangle Fill
	 *
	 */

	for (int n = 0; n < n_faces; n++)
	{

		Vec3 face = UNIT_CUBE.faces[n];
		Vec2 A = projection_2d(c->vertex[(int)face.x], 50, 30);
		Vec2 B = projection_2d(c->vertex[(int)face.y], 50, 30);
		Vec2 C = projection_2d(c->vertex[(int)face.z], 50, 30);


		Vec2 tmp = {0.0, 0.0};
		Vec2 M = {-1.0, -1.0};

	    if (A.z > B.z) { tmp = A; A = B; B = tmp; }
	    if (A.z > C.z) { tmp = A; A = C; C = tmp; }
	    if (B.z > C.z) { tmp = B; B = C; C = tmp; }


	    if (B.z == C.z && B.x < C.x && B.x == A.x) {
	        tmp = B; B = C; C = tmp;
	    }

	    if (B.z == C.z && B.x > C.x && B.x == A.x) {
	        tmp = B; B = C; C = tmp;
	    }


	    if (A.x < C.x)
	    {
	    	M.x = A.x + (fabs(B.z - A.z)/(fabs(C.z - A.z))) * (fabs(C.x - A.x)) ;
	    	M.z = B.z;
	    }
	    else
	    {
	    	M.x = A.x - (fabs(B.z - A.z)/(fabs(C.z - A.z))) * (fabs(C.x - A.x)) ;
	    	M.z = B.z;
	    }

		// TODO: Check if face is facing the camera (Back - Face Culling)

		/* calc slope for top and bottom triangel */
		double k_AB = A.x == B.x ? 0.0 : (A.z - B.z) / (A.x - B.x);
		double k_AM = A.x == M.x ? 0.0 : (A.z - M.z) / (A.x - M.x);
		double k_MC = M.x == C.x ? 0.0 : (M.z - C.z) / (M.x - C.x);
		double k_BC = B.x == C.x ? 0.0 : (B.z - C.z) / (B.x - C.x);


		// TODO: Find iteration boundaries

		double x_top_lim_1 = M.x;
		double x_top_lim_2 = M.x;
		double x_bottom_lim_1 = A.x;
		double x_bottom_lim_2 = A.x;

		/* flat bottom iteration */
		for(int z=A.z; z<=M.z; z++)
		{
			if (A.x != M.x)
			{
				x_bottom_lim_1 = A.x + (z-A.z) / (k_AM) ;
			}
			if( k_AB != 0)
			{
				x_bottom_lim_2 = A.x + (z-A.z) / (k_AB) ;
			}

			int xStart = (int)ceil(fmin(x_bottom_lim_1, x_bottom_lim_2));
			int xEnd   = (int)floor(fmax(x_bottom_lim_1, x_bottom_lim_2));

			for(int x = xStart; x<=xEnd; x++)
			{
				cnv[(int)z].str[(int)x] = ch;
			}
		}

		/* flat top iteration */
		for(int z=M.z; z<=C.z; z++)
		{
			if (C.x != M.x)
			{
				x_top_lim_1 = M.x + (z-M.z) / (k_MC) ;
			}
			if( k_BC != 0)
			{
				x_top_lim_2 = B.x + (z-B.z) / (k_BC) ;
			}
			if(B.x == C.x)
			{
				x_top_lim_2 = B.x;
			}

			int xStart = (int)ceil(fmin(x_top_lim_1, x_top_lim_2));
			int xEnd   = (int)floor(fmax(x_top_lim_1, x_top_lim_2));

			for(int x = xStart; x<=xEnd; x++)
			{
				cnv[(int)z].str[(int)x] = ch;
			}

		}

	}

}

