#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include "vec.h"
#include "cube.h"
#include "canvas.h"


#define ROT_STEP 32

#define SAVE_TO_FILE 0

static void update(String* canvas, Cube *cube, int f_nr);


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

	int f_nr = 0;
	while (1)
	{
		rot.x += (M_PI/ROT_STEP);
		rot.y += (M_PI/ROT_STEP);
		rot.z += (M_PI/ROT_STEP);
		cube.rotation = rot;

		rotate(&cube);

		update(canvas, &cube, f_nr);
		usleep(200000);
		canvas_init(canvas);

		f_nr++;
	}

	free_canvas(canvas);
	return 0;
}


static void update(String* canvas, Cube *cube, int f_nr)
{
	cls();

	if (SAVE_TO_FILE)
	{
		char step_str[20];
		char path[256] = "./doc/figures/";
		sprintf(step_str, "%d", f_nr);
		strcat(path, step_str);
		const char* appendix = ".txt";
		strcat(path, appendix);

		FILE *fp = fopen(path, "w");
	    if (fp == NULL)
	    {
	        perror("Error opening file");
	        return;
	    }

		draw_cube(canvas, cube);

		for (int i= 0; i<V_MAX; i++)
		{
			draw(canvas[i]);
			draw_to_file(canvas[i], fp);
		}

		fclose(fp);

	}
	else
	{
		draw_cube(canvas, cube);

		for (int i= 0; i<V_MAX; i++)
		{
			draw(canvas[i]);
		}
	}

	fflush(stdout);

}
