#ifndef _HASHCHECK_H_
#define _HASHCHECH_H_

#include"typedefMain.h"
#include"defMain.h"
#include"ScreenDisplay.h"
#include<string>
#include<iostream>
#include<fstream>

/* struct for saving all files'address and hash codes */
struct Worklist{
    std::string _Hash;
    std::string _fileaddress;
    void create( std::string _Hash_ReadIN , std::string _fileaddress_ReadIN );
};


class HashCheck{
    public:
        void changeHashCheckMode( uint8_t _newType );
        void setWorkfolder( std::string _Workfolder_address_ReadIN );
        
    private:
        uint8_t _HashType;  /* the hash type the program uses */
        uint16_t _file_now_in_check;  /* the number of the file which is now in check */
        Worklist _Worklist[_Worklist_LengthMAX];  /* All files need to be checked */
        std::string _Checklisk_address;  /* the address of the checklist */
        std::string _Workfolder_address;  /* the address of the Workfolder (all file addresses begin with * will be set under this address) */

        void readINchecklist( std::string _Checklist_address );
        bool linecheck( char *_line , uint8_t _HashTypeBit );
};

#endif