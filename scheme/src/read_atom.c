/*  
 read_atom.c
 
 
 Created by Jérémy Hraman on 15/09/2016. 
 SICOM-A

*/

#include "read_atom.h"


uint typeInput(char *input, uint *here) {
    
    uint type_input=1;

    char first_char=input[*here];
    
 /*   printf("sfs typeInput récupération char : %c \n",first_char); */
    
    /* NUMBER */
    
    char *p_end;
    strtol(input + *here, &p_end, 10);
    
    if ( isspace(p_end[0]) || iscntrl(p_end[0]) ) {
        type_input=SFS_NUMBER;
    }
    
    /* BOOLEAN & SYMBOL */
    
    else {
        WARNING_MSG("TYPE_ERROR : not a readable type");
    }
    
   /* printf("type_input = %d \n",type_input); */
    
    return type_input;
}


/* Fonctions de read_atom */

object read_atom_number(char *input, uint *here) {
    
    object atom = NULL;
    
    num atom_number;
    
    /* Ici, tous les nombres seront des entiers */
    
    atom_number.numtype = NUM_INTEGER ;
    
    /* On stocke le nombre */
    
    char * p_end=NULL; 
    atom_number.this.integer = strtol(input + *here, &p_end, 10);
    
    atom = make_integer( atom_number.this.integer );
    
    return atom;
}

object read_atom_boolean(char *input, uint *here){
    
    object atom = NULL;
    
    atom = make_object(SFS_BOOLEAN);
    
    return atom;
}

/*
// sachant que le prochain char edans la chaine est un char,
// lit ce char dans la chaine input a partir *here,
// avance juste apres
// et retourne l'object c qui represente cet atome
// ou retourne null si erreur */

object read_atom_character(char *input,uint *here){
    
    object atom = NULL;
    
    atom = make_object(SFS_CHARACTER);

    
    
    return atom;
}

object read_atom_chaine(char *input, uint *here){
    
    object atom = NULL;
    
    atom = make_object(SFS_STRING);
    
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