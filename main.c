#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void gol_init(/* Recibo un mundo */);
void gol_print(/* Recibo un mundo */);
void gol_step(/* Recibo dos mundos */);
int gol_count_neighbors(/* Recibo un mundo y unas coordenadas */);
bool gol_get_cell(/* Recibo un mundo y unas coordenadas */);
void gol_copy(/* Recibo dos mundos */);

int main()
{
	int i = 0;
	// TODO: Declara dos mundos

	// TODO: inicializa el mundo
	do {
		printf("\033cIteration %d\n", i++);
		// TODO: Imprime el mundo
		// TODO: Itera
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}

void gol_init(/* Recibo un mundo */)
{
	// TODO: Poner el mundo a false

	/* TODO: Inicializar con el patrón del glider:
	 *           . # .
	 *           . . #
	 *           # # #
	 */
}

void gol_print(/* Recibo un mundo */)
{
	// TODO: Imprimir el mundo por consola. Sugerencia:
	/*
	 *     . # . . . . . . . .
	 *     . . # . . . . . . .
	 *     # # # . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 *     . . . . . . . . . .
	 */
}

void gol_step(/* Recibo dos mundos */)
{
	/*
	 * TODO:
	 * - Recorrer el mundo célula por célula comprobando si nace, sobrevive
	 *   o muere.
	 *
	 * - No se puede cambiar el estado del mundo a la vez que se recorre:
	 *   Usar un mundo auxiliar para guardar el siguiente estado.
	 *
	 * - Copiar el mundo auxiliar sobre el mundo principal
	 */
}

int gol_count_neighbors(/* Recibo un mundo y unas coordenadas */)
{
	// Devuelve el número de vecinos
}

bool gol_get_cell(/* Recibo un mundo y unas coordenadas */)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
}

void gol_copy(/* Recibo dos mundos */)
{
	// TODO: copia el mundo segundo mundo sobre el primero
}
