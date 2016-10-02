
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
            printf("%c",o->this.character);
            break;
            
        case SFS_STRING :
            printf("%s",o->this.string);
            break;
            
        case SFS_SYMBOL :
            printf("%s",o->this.symbol);
            break;
    }
}

void sfs_print_pair( object o ) {
    
    printf("(");
    sfs_print( (o->this.pair).car );
    printf(" ");
    sfs_print( (o->this.pair).cdr );
    printf(")");

}

void sfs_print( object o ) {

    if ( SFS_PAIR == o->type ) {
        
        sfs_print_pair( o );
    }
    
    else {
        
        sfs_print_atom( o );
    }

}
