/*  
 read_atom.c
 
 
 Created by Jérémy Hraman on 15/09/2016. 
 SICOM-A

*/

#include "read_atom.h"


uint typeInput(char *input, uint *here) {
    
    uint type_input=SFS_NOTYPE;

    char first_char=input[*here];
    
   printf("sfs typeInput récupération char : %c \n",first_char);
    
    /* NUMBER */
    
    char *p_end;
    strtol(input + *here, &p_end, 10);
    
    if ( isspace(p_end[0]) || iscntrl(p_end[0]) ) {
        
        return SFS_NUMBER;
    }
    
    /* STRING */
    
    char apostrophe = '\'' ;
    printf("ye suis là: %c \n",first_char);
    
    if ( first_char==apostrophe ) {

        return SFS_STRING;
    }
    
    /* BOOLEAN - CHARACTER */
    
    /*if ( strcmp(input[*here],))*/
        
    
    else {
        WARNING_MSG("TYPE_ERROR : not a readable type");
    }
    
   /* printf("type_input = %d \n",type_input); */
    
    return type_input;
}


/* Fonctions de read_atom */

/* READ ATOM NUMBER */
/* Tous les nombres sont considérés comme entier */
/* On stocke le nombre dans atom_number */
/* Make_integer crée l'entier et retourne l'atome */

object read_atom_number(char *input, uint *here) {
    
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
    
    atom = make_integer( atom_number.this.integer );
    
    return atom;
}

/*
// sachant que le prochain char edans la chaine est un char,
// lit ce char dans la chaine input a partir *here,
// avance juste apres
// et retourne l'object c qui represente cet atome
// ou retourne null si erreur */

object read_atom_chaine(char *input, uint *here){
    
    object atom = NULL;
    
    char* chaine=NULL;
    int i=0;
    
    while ( chaine[i] != '\'' ) {
        chaine[i-1]=input[*here + i] //A COMPLETER
    }
    
    
    if (  chaine == NULL ) {
        
        WARNING_MSG("TYPE_ERROR : not a string");
        return NULL;
    }
    
    atom = make_string(chaine);
    
    return atom;
}

object read_atom_character(char *input,uint *here){
    
    object atom = NULL;
    
    atom = make_object(SFS_CHARACTER);


    
    return atom;
}

object read_atom_boolean(char *input, uint *here){
    
    object atom = NULL;
    
    atom = make_object(SFS_BOOLEAN);
    
    return atom;
}

object read_atom_symbol(char *input, uint *here){
    
    object atom = NULL;
    
    atom = make_object(SFS_SYMBOL);
    
    return atom;
}

object read_atom_empty(char *input, uint *here){
    
    object atom = NULL;
    
    atom = make_object(SFS_NIL);
    
    return atom;
}