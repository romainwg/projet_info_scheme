
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

object make_pair( void ) {
    
    object o = NULL;
    
    o = make_object(SFS_PAIR);
    
    o->this.pair.car = NULL;
    o->this.pair.cdr = NULL;
    
    return o;
}

object make_integer( int valeur ) {
    
    object o = NULL;
    o = make_object(SFS_NUMBER);
    
    o->this.number.this.integer = valeur;
    
    return o;
}

object make_string ( char* chaine ) {
    
    object o = NULL;
    o = make_object(SFS_STRING);
    
    strcpy (o->this.string, chaine);
    
    return o;
}

object make_character ( char* character ) {
    
    object o = NULL;
    o = make_object(SFS_CHARACTER);
    
    DEBUG_MSG("je suis là");
    
    strcpy (o->this.character, character);
    
    return o;
}

object make_boolean ( char* boolean ) {
    
    object o = NULL;
    o = make_object(SFS_BOOLEAN);
    
    strcpy(o->this.symbol,boolean);
    
    return o;
}

object make_symbol ( char* symbol ) {
    
    object o = NULL;
    o = make_object(SFS_BOOLEAN);
    
    strcpy(o->this.symbol,symbol);
    
    return o;
}