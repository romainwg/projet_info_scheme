/*
  aux_read.c
 

  Created by Jérémy Hraman on 01/10/2016.
  SICOM-A
 
*/

#include "aux_read.h"


/* RECHERCHE D'UN SPECIAL INITIAL */

int is_special_initial(char input) {
    
    char special_initial[14] = "!$%&*/:<=>?^_~";
    
    int i;
    for ( i=0 ; i<14 ; i++ ) {
        
        if ( input == special_initial[i] ) {
            
            return 1;
        }
    }
    
    return 0;
}

/* Calcul du nombre de chiffres d'un nombre */

int size_number ( int valeur ) {
    
    char char_int[16];
    
    sprintf(char_int,"%d",valeur);
    
    if ( strlen(char_int) == 0 ) {
        
        ERROR_MSG("Error number : lenght null");
    }
    
    return strlen(char_int);
}

/* CARACTERISATION DU TYPE DE L'ATOME */
/* Retourne le type selon les premiers caractères sinon si erreur NOTYPE */

uint typeInput(char *input, uint *here) {
    
    uint type_input=SFS_NOTYPE;
    
    char first_char=input[*here];
    
    DEBUG_MSG("sfs typeInput : begin");
    
    /* printf("sfs typeInput récupération char : %c \n",first_char);*/
    
    /* PAIR */
    
    if (input[*here] ==  '(') {
        
        DEBUG_MSG("SFS PAIR");
        
        return SFS_PAIR;
    }
    
    
    /* NUMBER */
    
    char *p_end;
    strtol(input + *here, &p_end, 10);
    
    if ( isspace(p_end[0]) || iscntrl(p_end[0]) ) {
        
        return SFS_NUMBER;
    }
    
    /* STRING */
    
    char guillemet = '\"' ;
    
    if ( first_char == guillemet ) {
        
        return SFS_STRING;
    }
    
    
    /* BOOLEAN - CHARACTER */
    
    if ( input[*here] == '#' ) {
        
        if ( ( input[*here+1] == 't' || input[*here+1] == 'f' ) && isgraph(input[*here+2]) == 0 ) {
            
            return SFS_BOOLEAN;
        }
        
        
        else if ( input[*here+1] == '\\' && isgraph(input[*here+2]) != 0) {
            
            return SFS_CHARACTER;
        }
    }
    
    /* SYMBOL */
    
    if ( isalpha(input[*here]) != 0 || is_special_initial(input[*here]) == 1 ) {
        
        return SFS_SYMBOL;
    }
    
    /* NOT A READABLE TYPE */
    
    else {
        WARNING_MSG("TYPE_ERROR : not a readable type");
    }
    
    return type_input;
}