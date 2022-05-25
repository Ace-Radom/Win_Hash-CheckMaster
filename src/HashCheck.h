#ifndef _HASHCHECK_H_
#define _HASHCHECH_H_

#include"typedefMain.h"
#include"defMain.h"
#include"ScreenDisplay.h"
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>

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
        void setChecklist( uint8_t _Checklist_HashType , std::string _Checklist_address_ReadIN );
        
    private:
        uint8_t _HashType;  /* the hash type the program uses */
        uint32_t _file_now_in_check;  /* the number of the file which is now in check */
        uint32_t _Worklist_length;  /* the length of the worklist */
        Worklist _Worklist[_Worklist_LengthMAX];  /* All files need to be checked */
        std::string _Checklisk_address;  /* the address of the checklist */
        std::string _Workfolder_address;  /* the address of the Workfolder (all file addresses begin with * will be set under this address) */

        void readINchecklist( std::string _Checklist_address );
        bool linecheck( char *_line , uint8_t _HashTypeBit );
        bool isaddressConformable( std::string _address );
};

#endif