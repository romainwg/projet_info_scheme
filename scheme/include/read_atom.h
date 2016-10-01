/*
  read_atom.h
  

  Created by Jérémy Hraman on 15/09/2016.

*/

#ifndef read_atom_h
#define read_atom_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include "object.h"
  
/* vérification d'un special initial */

int is_special_initial(char input);

/*Le type de l'entrée clavier*/

uint typeInput(char *input, uint *here);

/*Les différents types d'atome*/

object read_atom_number(    char *input,    uint *here);
object read_atom_boolean(   char *input,    uint *here);
object read_atom_character( char *input,    uint *here);
object read_atom_chaine(    char *input,    uint *here);
object read_atom_symbol(    char *input,    uint *here);
object read_atom_empty(     char *input,    uint *here);

#ifdef __cplusplus
}
#endif

#endif /* read_atom_h */
