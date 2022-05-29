#ifndef _LOGIO_H_
#define _LOGIO_H_

#include<fstream>
#include<string>
#include<cstdio>

class logIO{
    public:
        void create( std::string _logPath );
        void write( std::string _writeData );
        void writeln( std::string _writeData );
        void endl();
        void close();
        void erase();

    private:
        std::ofstream _logFile;
        std::string _logFilePath;
};

#endif