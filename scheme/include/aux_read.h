/*
    aux_read.h


    Created by Jérémy Hraman on 01/10/2016.
    SICOM-A
*/

#ifndef aux_read_h
#define aux_read_h


    
#include <stdio.h>
#include <stdlib.h>
#include "object.h"


    /* Supprimer les espaces */

void SpaceCancel        ( char *input, uint *here   );

<<<<<<< HEAD
=======
    /* Recherche des fins d'atomes */

int is_end_atom         ( char input_char           );
int is_not_end_atom     ( char input_char           );

>>>>>>> d0088e3e26bc864bf24df0b41fa994c2c988a57b
    
    /* vérification d'un special initial */
    
int is_special_initial  ( char input                );

    
    /* Nombre de digits d'un nombre */
    
int size_number         ( int valeur                );

    
    /*Le type de l'entrée clavier*/
    
uint typeInput          ( char *input, uint *here   );



#endif /* aux_read_h */
