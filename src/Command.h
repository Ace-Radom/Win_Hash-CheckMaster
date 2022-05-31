#ifndef _WHCM_COMMAND_H_
#define _WHCM_COMMAND_H_

#include"defMain.h"
#include"typedefMain.h"
#include<string>
//#include<iostream>

/* struct for saving commands */
struct CommandData{
    std::string _Command;
    uint8_t _NUM;
};

class CommandCenter{
    public:
        void read( std::string _Command );
        int getCommandNUM();

    private:
        int _CommandNUM;  /* the number of the command */
        std::string _Checklist;  /* Checklist path */
        std::string _WorkFolder;  /* Workfolder path */
        std::string _ChecklistName;  /* checklist name (-ln command) */
        std::string _Format;  /* given format (-e command) */
};

#endif