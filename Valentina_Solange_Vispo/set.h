#ifndef _SET_H_
#define _SET_H_

#include <stdbool.h>            /* Definition of bool      */
#include "type_elem.h"          /* Definition of type_elem */

typedef struct s_set *set;

/* CONSTRUCTORS */

// Crea un conjunto vacío.
set set_empty(void);

// Agrega el elemento 'e' al conjunto 's'.
set set_add(set s, type_elem e);


/* OPERATIONS   */

// Devuelve la cantidad de elementos que tiene 's'.
unsigned int set_cardinal(set s);

// Devuelve True si 's' es vacío.
bool set_is_empty(set s);

// Devuelve True si el elemento 'e' pertenece al conjunto 's'.
bool set_member(type_elem e, set s);

// Elimina el elemento 'e' del conjunto 's', en caso que esté.
set set_elim(set s, type_elem e);

// Agrega a 's' todos los elementos de 's0'.
set set_union(set s, set s0);

// Elimina de 's' todos los elementos que NO pertenezcan a 's0'.
set set_inters(set s, set s0);

// Elimina de 's' todos los elementos que pertenecen a 's0'.
set set_dif(set s, set s0);

// Obtiene el primer elemento del conjunto 's'.
type_elem set_get(set s);

// Copia el conjunto 's'
set set_copy(set s);

// Libera memoria en caso que haya sido pedida.
set set_destroy(set s);

#endif
