
/**
 * @file print.c
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 22 20:12:17 2012
 * @brief Printing stuff for SFS.
 *
 * Printing stuff for SFS.
 */

#include "print.h"

#include <stdio.h>

#include <string.h>

void sfs_print_atom( object obj ) {
    
	switch ()
	{
		case SFS_NUMBER:
			printf("%d",obj->this.number.this.integer);
			break;
		case SFS_CHARACTER:
			printf("%c",obj->this.character);
			break;
		case SFS_STRING:
			printf("%s",obj->this.string);
			break;
		case SFS_BOOLEAN:
			printf("%s",obj->this.symbol);
			break;
		case SFS_SYMBOL:
			printf("%s",obj->this.symbol);
			break;
		case SFS_NIL:
			//NIL
			//printf("");
			break;		
	}

}

void sfs_print_pair( object obj ) {
	
	//print de l'objet contenue à gauche puis à droite de l'arbre
	sfs_print(obj->this.pair.car);
	sfs_print(obj->this.pair.cdr);

}

void sfs_print( object obj ) {
	
	//l'object est une pair : print_pair
	//sinon print_atom
	if(obj->this.type == SFS_PAIR)
	{
		sfs_print_pair(obj);
	}
	else
	{
		sfs_print_atom(obj);
	}

}
