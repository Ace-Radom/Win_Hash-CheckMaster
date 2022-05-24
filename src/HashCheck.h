#ifndef _HASHCHECK_H_
#define _HASHCHECH_H_

#include"typedefMain.h"
#include"defMain.h"

class HashCheck{
    public:
        void changeHashCheck_Mode( uint8_t _newMode );
        void setWorkfolder( const char *_Workfolder_address );
        
    private:
        uint8_t _HashCheck_Mode;
        
};

#endif