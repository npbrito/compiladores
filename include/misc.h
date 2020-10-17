/* Natália Brito | 00274727 */
/* Yuri Jaschek  | 00231592 */

#ifndef MISC_H_
#define MISC_H_

#include "hash.h"
#include "list.h"

/* Other functions that help store values. */

#define NAT_VAR 0
#define NAT_VET 1
#define NAT_FUN 2

void store_identificador(hash_element**, lexeme_t*);

void store_nature(hash_element**, int nature);

void store_vet_size(hash_element** id_stored, int size);

void store_function_elem(hash_element**);

void store_param(hash_element**, ElementList*);

#endif // MISC_H_