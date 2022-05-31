#include"Command.h"

CommandData _CMDDATA[]{
    {},
    { "-l " , _l_ },
    { "-d " , _d_ },
    { "-c " , _c_ },
    { "-ln" , _ln_ },
    { "-e " , _e_ }
};

void CommandCenter::read( std::string _Command ){
    _cmd = _Command;
    uint32_t _CMDBegin = _cmd.find( '-' );
    setCommandNUM( _CMDBegin );
    switch ( _CommandNUM ){
        case _l_:
            //_Checklist = _cmd.substr();
            break;
    
    default:
        break;
    }
}

void CommandCenter::setCommandNUM( uint32_t _CMDBegin ){
    for ( int i = 1 ; i <= DATALENGTH ; i++ )
    {
        if ( _cmd.substr( _CMDBegin , 2 ) == _CMDDATA[i]._Command )
        {
            _CommandNUM = _CMDDATA[i]._NUM;
            std::cout << _CommandNUM << std::endl;
            return;
        }
    }
    _CommandNUM = _ERROR_;
    return;
}
