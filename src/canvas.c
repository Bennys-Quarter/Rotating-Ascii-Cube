/*
 * canvas.c
 *
 *  Created on: Nov 6, 2025
 *      Author: benny
 */

#include "canvas.h"


void canvas_init(String* cnv)
{
	char ch_init = CANVAS_BACKGROUND_CH;
	char str[H_MAX + 1];

	for (int i=0; i<H_MAX; i++)
	{
		str[i] = ch_init;
	}
	str[H_MAX] = '\0';


	for (int i = 0; i<V_MAX; i++)
	{
		new_str(&cnv[i], str);
	}
}

void new_str(String *n_str, const char* str_in)
{
	n_str->len = str_len(str_in);

	n_str->str = (char*) malloc((n_str->len + 1) * sizeof(char));
	for (size_t i=0; i<n_str->len; i++)
	{
		n_str->str[i] = str_in[i];
	}
}


size_t str_len(const char* str)
{
	/* return the length of a string */
	size_t length = 0;

	while(str[length] != '\0')
	{
		length++;
	}
	return length;
}


void draw(String str)
{
	/* draw a string */
	for (size_t i=0; i<str.len; i++)
	{
		printf("%c", str.str[i]);
	}
	printf("\n");
}


void free_canvas(String *cnv)
{
	for (int i=0; i<V_MAX; i++)
	{
		free_string(&cnv[i]);
	}
}

void free_string(String *n_str)
{
	free(n_str->str);
	n_str->str = NULL;
}

#ifdef __linux__
void cls(void)
{
	/* Clear entire console in Linux */
	system("clear");
}
#else
void cls(void)
{
	/* Clear entire console no OS */
	printf("\033[H\033[J");
	fflush(stdout);
}
#endif
