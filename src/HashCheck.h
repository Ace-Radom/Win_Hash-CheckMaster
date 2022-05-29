#ifndef _HASHCHECK_H_
#define _HASHCHECH_H_

#include"typedefMain.h"
#include"defMain.h"
#include"ScreenDisplay.h"
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<io.h>

/* struct for saving all files'address and hash codes */
struct Worklist{
    std::string _Hash;
    std::string _fileaddress;
    void create( std::string _Hash_ReadIN , std::string _fileaddress_ReadIN );
    void clear();
    bool isempty();
};

class HashCheck{
    public:
        void resetall();
        void certutilprecheck();
        void checkstart();

        void changeHashCheckMode( uint8_t _newType );
        void setWorkfolder( std::string _Workfolder_address_ReadIN );
        void setChecklist( uint8_t _Checklist_HashType , std::string _Checklist_address_ReadIN );

        void createChecklist( std::string _Checklist_name );
        void createChecklist( std::string _Checklist_name , std::string _format );
        
    private:
        uint8_t _HashType;  /* the hash type the program uses */
        uint32_t _file_now_in_check;  /* the number of the file which is now in check */
        uint32_t _Worklist_length;  /* the length of the worklist */
        Worklist _Worklist[_Worklist_LengthMAX];  /* All files need to be checked */
        std::string _Checklist_address;  /* the address of the checklist */
        std::string _Workfolder_address;  /* the address of the Workfolder (all file addresses begin with * will be set under this address) */
        uint32_t _Workfolder_path_foldercound;  /* the number of \ in the Workfolder path */
        std::string _Command_INuse;  /* record the command now in use */
        std::string _wrong_hashcode;  /* the wrong hash code returned by certutil */
        std::vector <std::string> _files_under_workfolderpath;  /* all files found under Workfolder */

        bool _is_checklistready;  /* status of the Checklist */
        bool _is_hashtypeset;  /* status of the hash type set */
        bool _is_Workfolderset;  /* status of the Workfolder set */

        void readINchecklist( std::string _Checklist_address );
        bool linecheck( char *_line , uint8_t _HashTypeBit );
        bool isaddressConformable( std::string _address );
        bool ischeckavailable();

        bool doHashCheck( std::string _hash , std::string _address );
        std::string gethashcode( std::string _address );

        void make_checkfileexistbat( std::string _address );
        void make_hashcheckbat( std::string _address );
        void search_allfilesunderpath( std::string _folderaddress , std::vector <std::string> &_files );
        void search_allfilesunderpath_withformat( std::string _folderaddress , std::vector <std::string> &_files , std::string _format );
};

#endif