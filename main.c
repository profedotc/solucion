#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "gol.h"

int main()
{
	int i = 0;
	bool worlds[2][GOL_SIZE_X][GOL_SIZE_Y];
	unsigned int current_world = 0;

	gol_init(worlds[current_world]);
	do {
		printf("\033cIteration %d\n", i++);
		gol_print(worlds[current_world]);
		gol_step(worlds[current_world], worlds[!current_world]);
		current_world = !current_world;
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}
