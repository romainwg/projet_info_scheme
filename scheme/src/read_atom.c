/*  
 read_atom.c
 
 
 Created by Jérémy Hraman on 15/09/2016. 
 SICOM-A

*/

#include "read_atom.h"


uint typeInput(char *input, uint *here) {
    
    printf("sfs typeInput début \n");
    
    uint type_input = 0;

    char first_char=NULL;
    first_char=input[*here];
    
    printf("sfs typeInput récupération char : %c \n",first_char);
    
    if (isdigit(first_char) || first_char=='+' || first_char=='-') {
        type_input=SFS_NUMBER;
    }
    
  /*  else if (first_char=="'") {
        
        type_input=SFS_STRING;
    }
    
    else if (first_char[0]=='#') {
        if (strcmp(first_char,"#d")==0) { /* Bug avec le "\"
            
            type_input=SFS_SYMBOL;
        }
        
    }
     */
    
    printf("type_input = %d \n",type_input);
    
    return type_input;
}


/* Fonctions de read_atom */

object read_atom_number(char *input, uint *here) {
    
    object atom = NULL;
    
    atom = make_object(SFS_NUMBER);
    
    
    
    atom = make_integer(
    
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
    
    /*object o = make_integer(5);*/
    
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