
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

void sfs_print_atom( object o ) {
    
    switch (o->type) {
        case SFS_NUMBER :
            
            printf("%d",o->this.number.this.integer);
            break;
            
        case SFS_BOOLEAN :
            
            printf("%s",o->this.symbol);
            break;
            
        case SFS_CHARACTER :
            
            /* if ( strcmp("#\\newline",o->this.character) == 0) {
                printf("\n");
            }
            else if ( strcmp("#\\space",o->this.character) == 0) {
                printf(" ");
            } */
            /* else { */
                printf("%s",o->this.character);
            /* } */
            break;
            
        case SFS_STRING :
            
            printf("%s",o->this.string);
            break;
            
        case SFS_SYMBOL :
            
            printf("%s",o->this.symbol);
            break;
    }
}

void sfs_print_pair( object o , uint *root) {
    
    if ( ( (o->this.pair).cdr->type == SFS_NIL && (o->this.pair).car->type == SFS_PAIR ) || ( (o->this.pair).cdr->type == SFS_PAIR && (o->this.pair).car->type == SFS_PAIR ) ) {
        printf("(");
    }
    
    sfs_print( (o->this.pair).car , root);
    
    if ( (o->this.pair).cdr->type != SFS_NIL ) {
        printf(" ");
    }

    sfs_print( (o->this.pair).cdr , root);
    
    if ( (o->this.pair).cdr->type == SFS_NIL ) {
        printf(")");
    }

}


void sfs_print( object o , uint* root ) {


    if ( SFS_PAIR == o->type ) {
        
        if (*root == 1) {
            *root = 0;
            printf("(");
        }
        
        sfs_print_pair( o , root);
    }
    
    else {
        
        sfs_print_atom( o );
    }

}
