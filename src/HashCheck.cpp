#include"HashCheck.h"

/* read in a new file in worklist */
void Worklist::create( std::string _Hash_ReadIN , std::string _fileaddress_ReadIN ){
    _Hash = _Hash_ReadIN;
    _fileaddress = _fileaddress_ReadIN;
    return;
}

/* ============================================= public ============================================= */

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

/* set and readin checklist data and reset hash type */
void HashCheck::setChecklist( uint8_t _Checklist_HashType , std::string _Checklist_address_ReadIN ){
    changeHashCheckMode( _Checklist_HashType );
    _Checklisk_address = _Checklist_address_ReadIN;
    readINchecklist( _Checklisk_address );
    return;
}

/* ============================================= private ============================================= */

/* read checklist data from hard drive and check each line of data */
void HashCheck::readINchecklist( std::string _Checklist_address ){
    std::ifstream _Checklist_Input;
    _Checklist_Input.open( _Checklist_address , std::ios::in );
    //set file input stream
    if ( !_Checklist_Input.is_open() )
    {
        printERROR( WHITE );
        std::cout << "Unconformable address or checklist file not found" << std::endl;
        return;
    }
    //error exists
    char _lineDATA[1000];  /* data of one line in the checklist */
    uint32_t _listlength = 0;  /* count how many conformable hash codes need to be checked */
    uint32_t _lineNUM = 0;  /* count how many lines does the checklist have */
    while ( _Checklist_Input.getline( _lineDATA , sizeof( _lineDATA ) ) )
    {
        _lineNUM++;
        bool _lineVerify;
        int _bit;  /* bits of the hash code */
        switch ( _HashType ){
            case MD5:
                _bit = MD5_CHECK;
                _lineVerify = linecheck( _lineDATA , MD5_CHECK );
                break;
            case SHA1:
                _bit = SHA1_CHECK;
                _lineVerify = linecheck( _lineDATA , SHA1_CHECK );
                break;
            case SHA256:
                _bit = SHA256_CHECK;
                _lineVerify = linecheck( _lineDATA , SHA256_CHECK );
                break;
            case SHA512:
                _bit = SHA512_CHECK;
                _lineVerify = linecheck( _lineDATA , SHA512_CHECK );
                break;
        }
        //switch four different hash types and check if this line is conformable or not
        if ( !_lineVerify )
        {
            printWARNING( YELLOW );
            std::cout << "In line " << _lineNUM << ": ";
            setcolor( WHITE );
            std::cout << "Unconformable Hash code" << std::endl;
            continue;
        }
        //unconformable hash code
        std::string _Hash_IN_line( _lineDATA , _bit );  /* the hash code in this line */
        std::string _address_IN_line;  /* the file address in this line */
        if ( _lineDATA[_bit+1] == '*' )
        {
            _address_IN_line = _Workfolder_address;
            //copy default folder
            int _temp = _bit + 2;
            while ( _lineDATA[_temp] != '\0' )
            {
                _address_IN_line += _lineDATA[_temp];
                _temp++;
            }
        }
        //using default folder to copy file address
        else
        {
            int _temp = _bit + 1;
            while ( _lineDATA[_temp] != '\0' )
            {
                _address_IN_line += _lineDATA[_temp];
                _temp++;
            }
        }
        //copy file address, default folder unused
        if ( !isaddressConformable( _address_IN_line ) )
        {
            printWARNING( YELLOW );
            std::cout << "In line " << _lineNUM << ": ";
            setcolor( WHITE );
            std::cout << "File unfound or file address not correct" << std::endl;
            continue;
        }
        //check file address
        _listlength++;
        _Worklist[_listlength].create( _Hash_IN_line , _address_IN_line );
        //copy hash code and file address to the worklist
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

/* check file address */
bool HashCheck::isaddressConformable( std::string _address ){
    FILE *_addressTest;
    char _addresscopy[1000];
    strcpy( _addresscopy , _address.c_str() );
    if ( ( _addressTest = _popen( _addresscopy , "r" ) ) != NULL )
    {
        return true;
    }
    return false;
}