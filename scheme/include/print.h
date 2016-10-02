
/**
 * @file print.h
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 22 20:12:52 2012
 * @brief Printing stuff for SFS.
 *
 * Printing stuff for SFS.
 */

#ifndef _PRINT_H_
#define _PRINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "object.h"


void sfs_print( object );
//La fonction print est le point d’entrée de l’affichage du résultat de votre interpréteur.
//Son rôle est de convertir un arbre syntaxique en chaîne de caractères et de l’afficher dans la sortie standard

//SI type == SFS_PAIR (3) -> print pair
//ELSE -> print atom


void sfs_print_atom( object );
//Conversion et écriture de l'atome
//Switch des types et écriture en conséquence
//SI liste vide : écriture d'une parenthèse fermante

void sfs_print_pair( object );
//écriture d'une parenthèse ouvrante

#ifdef __cplusplus
}
#endif

#endif /* _PRINT_H_ */
