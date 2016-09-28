
/**
 * @file object.c
 * @author François Cayre <cayre@yiking.(null)>
 * @date Fri Jun 15 18:02:57 2012
 * @brief Object definitions for SFS.
 *
 * Object definitions for SFS.
 */

#include "object.h"
#include "mem.h"


object make_object( uint type ) {

    object t = sfs_malloc( sizeof( *t ) );

    t->type = type;

    return t;
}

object make_nil( void ) {

    object t = make_object( SFS_NIL );

    t->this.special = t;

    return t;
}

object make_integer( int valeur ) {
    
    object o = make_object(SFS_NUMBER);
    o->this.number.this.integer = valeur;
    return o;
}

object make_string ( char* chaine ) {
    
    object o = make_object(SFS_STRING);
    
    return o;
}

object make_character ( char character ) {
    
    object o = make_object(SFS_CHARACTER);
    
    return o;
}

object make_boolean ( char* boolean ) {
    
    object o = make_object(SFS_BOOLEAN);
    
    return o;
}

object make_symbol ( char* symbol ) {
    
    object o = make_object(SFS_BOOLEAN);
    
    return o;
}