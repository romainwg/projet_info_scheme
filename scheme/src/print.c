
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
            
        case SFS_BOOLEAN :
            printf("%s",o->this.symbol);
            
        case SFS_CHARACTER :
            printf("%c",o->this.character);
            
        case SFS_STRING :
            printf("%s",o->this.string);
            
        case SFS_SYMBOL :
            printf("%s",o->this.symbol);
    }
    
    return;
}

void sfs_print_pair( object o ) {
    
    sfs_print( (o->this.pair).car );
    sfs_print( (o->this.pair).cdr );

    return;
}

void sfs_print( object o ) {

    if ( SFS_PAIR == o->type ) {
        
        sfs_print_pair( o );
    }
    
    else {
        
        sfs_print_atom( o );
    }

}
