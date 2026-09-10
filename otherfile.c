#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "otherfile.h"

/**
 * function_somewhere_else - Función de demostración que ilustra 
 * funciones no testeadas en el proyecto
 * @argument: Parámetro de entrada
 *
 * Nota: Esta función nunca debería ser llamada en pruebas unitarias.
 * Si se ejecuta, indica un error en el flujo de control.
 */
void function_somewhere_else(int argument) {
    fprintf(stderr, "ERROR: %s() was unexpectedly called with argument: %d\n", 
            __func__, argument);
    abort();
}

/**
 * database_id_exists - Verifica si un ID existe en la base de datos
 * @id: ID a verificar
 *
 * Return: true si el ID existe, false en caso contrario
 *
 * Nota: Esta es una función ficticia que simula conectividad a BD.
 * En pruebas unitarias debe ser mockeada.
 */
bool database_id_exists(unsigned int id) {
    fprintf(stderr, "ERROR: %s() was unexpectedly called with id: %u\n", 
            __func__, id);
    abort();
    return false;
}
