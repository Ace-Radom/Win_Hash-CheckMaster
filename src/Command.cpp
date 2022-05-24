#include"Command.h"

int _CommandCodeReturn( const char *_Command ){
    if ( strcmp( _Command , "./start" ) == 0 )
        return 0x01;
    return _ERROR_;
}