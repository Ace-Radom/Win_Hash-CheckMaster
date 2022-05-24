#include"HashCheck.h"

/* ============================================= public ============================================= */

/* read in a new file in worklist */
void Worklist::create( std::string _Hash_ReadIN , std::string _fileaddress_ReadIN ){
    _Hash = _Hash_ReadIN;
    _fileaddress = _fileaddress_ReadIN;
    return;
}

/* change or set the hash type the program uses */
void HashCheck::changeHashCheckMode( uint8_t _newType ){
    _HashType = _newType;
    return;
}

/* set default folder */
void HashCheck::setWorkfolder( std::string _Workfolder_address_ReadIN ){
    _Workfolder_address = _Workfolder_address_ReadIN;
    return;
}

/* ============================================= private ============================================= */

void HashCheck::readINchecklist( std::string _Checklist_address ){
    std::ifstream _Checklist_Input;
    _Checklist_Input.open( _Checklist_address , std::ios::in );
    //set file input stream
    if ( !_Checklist_Input.is_open() )
    {
        colorprintf( "ERROR" , RED , WHITE );
        std::cout << "> Unable to open this checklist file, please check the file address and file name and then retry" << std::endl;
        return;
    }
    //error exists
    char _lineDATA[1000];  /* data of one line in the checklist */
    uint32_t _listlength = 0;  /* count how many */
    uint32_t _lineNUM = 0;  /* count how many lines does the checklist have */
    while ( _Checklist_Input.getline( _lineDATA , sizeof( _lineDATA ) ) )
    {
        _lineNUM++;
        bool _lineVerify;
        switch ( _HashType ){
            case MD5:
                _lineVerify = linecheck( _lineDATA , MD5_CHECK );
                break;
            case SHA1:
                _lineVerify = linecheck( _lineDATA , SHA1_CHECK );
                break;
            case SHA256:
                _lineVerify = linecheck( _lineDATA , SHA256_CHECK );
                break;
            case SHA512:
                _lineVerify = linecheck( _lineDATA , SHA512_CHECK );
                break;
        }
        //switch four different hash types and check if this line is conformable or not
        if ( !_lineVerify )
        {
            colorprintf( "WARNING" , PURPIL , WHITE );
            std::cout << "> ";
            setcolor( YELLOW );
            std::cout << "In line " << _lineNUM << ": ";
            setcolor( WHITE );
            std::cout << "Hash code unconformable" << std::endl;
            continue;
        }
        //unconformable hash code
    }
}

/* check if the hash code in this line is conformable or not*/
bool HashCheck::linecheck( char *_line , uint8_t _HashTypeBit ){
    if ( _line[_HashTypeBit] != ' ' )
    {
        return false;
    }
    for ( int i = 0 ; i < _HashTypeBit ; i++ )
    {
        if ( !( ( ( _line[i] >= '0' ) && ( _line[i] <= '9' ) ) || ( ( _line[i] >= 'a' ) && ( _line[i] <= 'f' ) ) ) )
        {
            return false;
        }
    }
    return true;
}