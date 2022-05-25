#include"HashCheck.h"

/* read in a new file in worklist */
void Worklist::create( std::string _Hash_ReadIN , std::string _fileaddress_ReadIN ){
    _Hash = _Hash_ReadIN;
    _fileaddress = _fileaddress_ReadIN;
    return;
}

/* clear this worklist subject */
void Worklist::clear(){
    _Hash.clear();
    _fileaddress.clear();
    return;
}

/* check if this worklist is empty */
bool Worklist::isempty(){
    if ( _Hash.empty() && _fileaddress.empty() )
    {
        return true;
    }
    return false;
}

/* ============================================= public ============================================= */

/* class reset */
void HashCheck::resetall(){
    _HashType = NO_HASHTYPE;
    _file_now_in_check = 0;
    _Worklist_length = 0;
    for ( int i = 0 ; i < _Worklist_LengthMAX ; i++ )
    {
        _Worklist[i].clear();
    }
    //clear Worklist data
    _Checklist_address.clear();
    _Workfolder_address.clear();
    _is_checklistready = NOT_READY;
    _is_hashtypeset = NOT_READY;
    _is_Workfolderset = NOT_READY;
    return;
}

/* start hash check */
void HashCheck::checkstart(){
    if ( !ischeckavailable() )
    {
        return;
    }
    printLINEBEGIN( WHITE );
    std::cout << "Hash check started..." << std::endl;
    for ( int i = 1 ; i <= _Worklist_length ; i++ )
    {

    }
}

/* change or set the hash type the program uses */
void HashCheck::changeHashCheckMode( uint8_t _newType ){
    _HashType = _newType;
    _is_hashtypeset = READY;
    return;
}

/* set default folder */
void HashCheck::setWorkfolder( std::string _Workfolder_address_ReadIN ){
    _Workfolder_address = _Workfolder_address_ReadIN;
    _is_Workfolderset = READY;
    return;
}

/* set and readin checklist data and reset hash type */
void HashCheck::setChecklist( uint8_t _Checklist_HashType , std::string _Checklist_address_ReadIN ){
    changeHashCheckMode( _Checklist_HashType );
    _Checklist_address = _Checklist_address_ReadIN;
    _is_hashtypeset = READY;
    readINchecklist( _Checklist_address );
    if ( !_is_checklistready )
    {
        printLINEBEGIN( WHITE );
        std::cout << "Checklist read but error occur" << std::endl;
    }
    //checklist set failed
    return;
}

/* ============================================= private ============================================= */

/* read checklist data from hard drive and check each line of data */
void HashCheck::readINchecklist( std::string _Checklist_address ){
    _is_checklistready = NOT_READY;
    //reset checklist status
    printLINEBEGIN( WHITE );
    std::cout << "Start Checklist readin" << std::endl;
    std::ifstream _Checklist_Input;
    _Checklist_Input.open( _Checklist_address , std::ios::in );
    //set file input stream
    if ( !_Checklist_Input.is_open() )
    {
        printERROR( WHITE );
        std::cout << "Checklist file not found or unconformable path" << std::endl;
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
            if ( _is_Workfolderset == NOT_READY )
            {
                printWARNING( YELLOW );
                std::cout << "In line " << _lineNUM << ": ";
                setcolor( WHITE );
                std::cout << "Worfolder unset but * found" << std::endl;
                continue;
            }
            //check if workfolder isn't set
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
            std::cout << "File unfound or file path not correct" << std::endl;
            continue;
        }
        //check file address
        _listlength++;
        _Worklist[_listlength].create( _Hash_IN_line , _address_IN_line );
        //copy hash code and file address to the worklist
    }
    if ( _listlength == 0 )
    {
        printERROR( WHITE );
        std::cout << "Checklist file empty or no conformable data in Checklist file is found" << std::endl;
        return;
    }
    printLINEBEGIN( WHITE );
    std::cout << "Checklist is read in without error" << std::endl;
    printLINEBEGIN( WHITE );
    std::cout << "Totally " << _listlength << " comformable file found in Checklist, " << _listlength << " file added to Worklist" << std::endl;
    _is_checklistready = READY;
    _Worklist_length = _listlength;
    return;
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
    make_checkfileexistbat( _address );
    FILE *_batANS;
    char _ans[1024] = {0};
    _batANS = _popen( _Command_INuse.c_str() , "r" );
    fgets( _ans , 1024 , _batANS );
    _pclose( _batANS );
    if ( strcmp( _ans , "FileExist\n" ) == 0 )  
    //in cmd, command 'echo' always has a \n mark at the end of the line, and that'll also be copied by the fgets() into ans
    {
        return true;
    }
    return false;
}

/* check if Hashcheck is able to start */
bool HashCheck::ischeckavailable(){
    if ( _is_checklistready && _is_hashtypeset )
    {
        return true;
    }
    if ( !_is_checklistready )
    {
        printERROR( WHITE );
        std::cout << "Checklist not set or unready" << std::endl;
        return false;
    }
    if ( !_is_hashtypeset )
    {
        printERROR( WHITE );
        std::cout << "No exact Hash type set" << std::endl;
        return false;
    }
    printERROR( WHITE );
    std::cout << "Unknown error exist" << std::endl;
    return false;
}

bool HashCheck::doHashCheck( std::string _hash , std::string _address ){
    make_hashcheckbat( _address );
    FILE *_batANS;
    char _ans[1024] = {0};
    _batANS = _popen( _Command_INuse.c_str() , "r" );
    fgets( _ans , 1024 , _batANS );
    fgets( _ans , 1024 , _batANS );
    //for 'certutil -hashfile' command, the hash code always appears in the second line
    //therefore fgets() twice in order to get the data in the second line
    pclose( _batANS );
    std::string _hash_copy = _hash + "\n";
    //just like before, there's a \n mark at the end of _ans, therefore _hash also needs to have a \n mark
    if ( strcmp( _ans , _hash_copy.c_str() ) == 0 )
    {
        return true;
    }
    return false;
}

/* create command for file exist check */
void HashCheck::make_checkfileexistbat( std::string _address ){
    _Command_INuse.clear();
    _Command_INuse = "if exist \"";
    _Command_INuse += _address;
    _Command_INuse += "\" echo FileExist";
    //link file path and .bat command
    return;
}

/* create command for certutil.exe */
void HashCheck::make_hashcheckbat( std::string _address ){
    _Command_INuse.clear();
    _Command_INuse = "certutil -hashfile \"";
    _Command_INuse += _address;
    _Command_INuse += "\" ";
    //link file path and .bat command
    switch ( _HashType ){
        case MD5:
            _Command_INuse += "MD5";
            break;
        case SHA1:
            _Command_INuse += "SHA1";
            break;
        case SHA256:
            _Command_INuse += "SHA256";
            break;
        case SHA512:
            _Command_INuse += "SHA512";
            break;
    }
    //link hash type
    return;
}