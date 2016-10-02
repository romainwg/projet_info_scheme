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
    
    /* gestion des erreurs à revoir !!!
     
     if (  p_end[0] != ' ' ) {
     
     WARNING_MSG("TYPE_ERROR : not a number");
     return NULL;
     } */
    
    *here = *here + size_number( atom_number.this.integer );
    
    atom = make_integer( atom_number.this.integer );
    
    return atom;
}


/* READ ATOM CHAINE */
/* Lecture de la chaîne à partir de *here */
/* On stocke la chaîne dans la variable chaine */
/* Make_string crée la chaîne et retourne l'object atom sinon si erreur NULL */

object read_atom_chaine(char *input, uint *here){
    
    object atom = NULL;
    
    char *chaine = malloc( 100 );
    
    chaine[0]='\"';
    
    int i=1;
    int current_here = (*here)+1;
    
    if ( input[current_here] == '\"' ) {
        
        return NULL;
    }
    
    while ( input[current_here] != '\"' || !input[current_here] ) {
        
        chaine[i]=input[current_here];
        current_here++;
        i++;
    }
    
    chaine[i]='\"';
    
    if ( input[current_here] != '\"' ) {
        
        WARNING_MSG("TYPE_ERROR : not a finished quote");
    }
    
    if ( chaine == NULL ) {
        
        WARNING_MSG("TYPE_ERROR : not a string");
        return NULL;
        
    }
    
    *here = current_here+1;
    
    atom = make_string(chaine);
    
    return atom;
}

/* READ ATOM CHARACTER */
/* Lecture de la chaîne à partir de *here */
/* On stocke la chaîne dans la variable character */
/* Make_character crée la chaîne et retourne l'object atom sinon si erreur NULL */

object read_atom_character(char *input,uint *here){
    
    object atom = NULL;

    char* character = malloc ( 100 );
    
    character[0]='#';
    character[1]='\\';
    
    int i=2;
    int current_here = (*here)+2;
    
    while ( isgraph(input[current_here]) != 0 ) {
        
        character[i]=input[current_here];
        
        current_here++;
        i++;
    }
    
    *here = current_here;
    
    atom = make_character(character);
    
    return atom;
}

/* READ ATOM BOOLEAN */
/* Lecture de la chaîne à partir de *here */
/* On stocke le booléen dans la variable boolean */
/* Make_boolean crée la chaîne et retourne l'object atom sinon si erreur NULL */

/* Attention, le booléen n'est pas encore considéré ici comme un object spécial : A VOIR */

object read_atom_boolean(char *input, uint *here){
    
    object atom = NULL;
    
    char boolean[2];
    
    boolean[0]=input[*here];
    boolean[1]=input[*here+1];
    
    *here = *here + 2;
    
    atom = make_boolean(boolean);
    
    return atom;
}

object read_atom_symbol(char *input, uint *here){
    
    object atom = NULL;
    
    int i=0;
    int current_here = *here;
    
    char* symbol = malloc ( 100 );
    
    while ( isalpha(input[current_here]) != 0 || is_special_initial(input[current_here]) != 0 ) {
        
        symbol[i]=input[current_here];
        
        current_here++;
        i++;
    }
    
    *here = current_here;
    
    atom = make_symbol(symbol);
    
    return atom;
}