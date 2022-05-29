#include"logIO.h"

/* create log file*/
void logIO::create( std::string _logPath ){
    if ( _logFile )
    {
        _logFile.close();
    }
    //if there's already one log file been opened, close it
    _logFilePath = _logPath;
    _logFile.open( _logFilePath , std::ios::out );
    return;
}

/* write data to log file */
void logIO::write( std::string _writeData ){
    _logFile << _writeData;
    return;
}

/* write data to log file and end this line */
void logIO::writeln( std::string _writeData ){
    _logFile << _writeData << std::endl;
    return;
}

/* end line */
void logIO::endl(){
    _logFile << std::endl;
    return;
}

/* close log file ofstream */
void logIO::close(){
    _logFile.close();
    return;
}

/* delete log file */
void logIO::erase(){
    _logFile.close();
    remove( _logFilePath.c_str() );
    return;
}

