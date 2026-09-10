#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "example.h"
#include "otherfile.h"

/**
 * is_acceptable_id - Valida si un ID es aceptable
 * @id: ID a validar
 *
 * Return: true si el ID es válido (entre 1000 y 10000 y no existe en BD),
 *         false en caso contrario
 *
 * Esta es una función estática de utilidad usada por some_function().
 */
static bool is_acceptable_id(unsigned int id) {

    if (database_id_exists(id))
        return false;

    return id > 1000 && id < 10000;
}

/**
 * some_function - Procesa un argumento llamando a otras funciones
 * @argument: Argumento a procesar
 *
 * Esta función ilustra cómo las funciones pueden depender de otras
 * que pueden ser mockeadas en pruebas.
 */
void some_function(int argument) {
    fprintf(stderr, "Processing argument: %d\n", argument);
    function_somewhere_else(argument);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <id>\n", basename(argv[0]));
        return 1;
    }
    
    int id = atoi(argv[1]);
    
    /* Validar que el ID sea un número válido */
    if (id < 0) {
        fprintf(stderr, "Error: ID must be a positive number\n");
        return 1;
    }
    
    bool is_acceptable = is_acceptable_id((unsigned int)id);

    printf("ID is acceptable: %s\n", is_acceptable ? "yes" : "no");

    return 0;
}
