/*
 * canvas.h
 *
 *  Created on: Nov 6, 2025
 *      Author: benny
 */

#ifndef INC_CANVAS_H_
#define INC_CANVAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct
{
	size_t len;
	char* str;
}String;


void cls(void);
void draw(String str);
void canvas_init(String* cnv);
void free_canvas(String *cnv);
size_t str_len(const char* str);
void free_string(String *n_str);
void new_str(String *n_str, const char* str_in);

#define H_MAX 50
#define V_MAX 30
#define CANVAS_BACKGROUND_CH ' '

#endif /* INC_CANVAS_H_ */
