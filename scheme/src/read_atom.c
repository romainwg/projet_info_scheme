/*  
 read_atom.c
 
 
 Created by Jérémy Hraman on 15/09/2016. 
 SICOM-A

*/

#include "read_atom.h"
#include "aux_read.h"

/* FONCTIONS READ_ATOM */

/* READ ATOM NUMBER */
/* Tous les nombres sont considérés comme entier */
/* On stocke le nombre dans atom_number */
/* Make_integer crée l'entier et retourne l'object atom sinon si erreur NULL */


object read_atom_number(char * input, uint *here) {
    
    object atom = NULL;
    
    num atom_number;
    atom_number.numtype = NUM_INTEGER ;
    
    char * p_end=NULL;
    atom_number.this.integer = strtol(input + *here, &p_end, 10);
    
    DEBUG_MSG("read atom number %d",atom_number.this.integer);
    
    /* gestion des erreurs à revoir !!!
     
     if (  p_end[0] != ' ' ) {
     
     WARNING_MSG("TYPE_ERROR : not a number");
     return NULL;
     } */
    
    *here = *here + size_number( atom_number.this.integer );
    
    DEBUG_MSG("read atom number here %d",*here);
    
    atom = make_integer( atom_number.this.integer );
    
    return atom;
}


/* READ ATOM CHAINE */
/* Lecture de la chaîne à partir de *here */
/* On stocke la chaîne dans la variable chaine */
/* Make_string crée la chaîne et retourne l'object atom sinon si erreur NULL */

object read_atom_chaine(char *input, uint *here){
    
    object atom = NULL;
    
    char* chaine=NULL;
    
    int i=0;
    int current_here = (*here)+1;
    
    if ( input[current_here] == '\"' ) {
        
        return NULL;
    }
    
    while ( input[current_here] != '\"' && isalpha(input[current_here]) != 0 ) {
        
        chaine[i]=input[current_here];
        current_here++;
        i++;
        
    }
    
    if ( input[current_here] != '\"' ) {
        WARNING_MSG("TYPE_ERROR : ");
    }
    
    if (  chaine == NULL ) {
        
        WARNING_MSG("TYPE_ERROR : not a string");
        return NULL;
        
    }
    
    atom = make_string(chaine);
    
    return atom;
}

/* READ ATOM CHAINE */
/* Lecture de la chaîne à partir de *here */
/* On stocke la chaîne dans la variable character */
/* Make_character crée la chaîne et retourne l'object atom sinon si erreur NULL */

object read_atom_character(char *input,uint *here){
    
    object atom = NULL;

    char* character = NULL;

    atom = make_character(character);
    
    return atom;
}

object read_atom_boolean(char *input, uint *here){
    
    object atom = NULL;
    
    char* boolean = NULL;
    
    atom = make_boolean(boolean);
    
    return atom;
}

object read_atom_symbol(char *input, uint *here){
    
    object atom = NULL;
    
    char* symbol = NULL;
    
    atom = make_symbol(symbol);
    
    return atom;
}

object read_atom_empty(char *input, uint *here){
    
    object atom = NULL;
    
    atom = make_nil();
    
    return atom;
}