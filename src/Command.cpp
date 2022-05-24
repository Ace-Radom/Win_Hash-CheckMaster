#include"Command.h"

/* return command code/number 
   in order to use switch in main class */
int _CommandCodeReturn( const char *_Command ){
    if ( strcmp( _Command , "./start" ) == 0 )
        return Program_Start;
    return _ERROR_;
}

/* program end check 
   when yes (input "./end"), return true */
bool _ProgramEndCheck( const char *_Command ){
    if ( strcmp( _Command , "./end" ) == 0 )
        return true;
    return false;
}