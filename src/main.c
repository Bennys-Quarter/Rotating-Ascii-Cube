#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "vec.h"
#include "cube.h"
#include "canvas.h"


#define ROT_STEP 32


static void update(String* canvas, Cube *cube);


int main(void)
{
	String canvas[V_MAX];
	Cube cube;

	Vec3 rot =
	{
		.x = 0.0,
		.y = 0.0,
		.z = 0.0,
	};

	canvas_init(canvas);
	cube_init(&cube);


	while (1)
	{
		rot.x += M_PI/ROT_STEP;
		rot.y += M_PI/ROT_STEP;
		rot.z += M_PI/ROT_STEP;
		cube.rotation = rot;

		rotate(&cube);

		update(canvas, &cube);
		usleep(200000);
		canvas_init(canvas);
	}

	free_canvas(canvas);
	return 0;
}


static void update(String* canvas, Cube *cube)
{
	cls();

	draw_cube(canvas, cube);

	for (int i= 0; i<V_MAX; i++)
	{
		draw(canvas[i]);
	}

	fflush(stdout);

}
