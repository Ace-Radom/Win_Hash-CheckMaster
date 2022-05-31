#include"ScreenDisplay.h"

/* set print color */
void setcolor( int _colorNUM ){
    switch ( _colorNUM ){
        case RED:
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ) , FOREGROUND_INTENSITY | FOREGROUND_RED );
            break;
        case GREEN:
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ) , FOREGROUND_INTENSITY | FOREGROUND_GREEN );
            break;
        case YELLOW:
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ) , FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN );
            //mix red and green to get yellow
            break;
        case WHITE:
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ) , FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
            //mix all three colors to get white
            break;
        case PURPIL:
            SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ) ,                        FOREGROUND_PURPIL );
            //set purpil from defMain.h
            break;
    }
    return;
}

/* print one string with a special color (will return to original color in the end) */
void colorprintf( std::string _dataPrint , int _colorNUM , int _originalcolorNUM ){
    setcolor( _colorNUM );
    std::cout << _dataPrint;
    setcolor( _originalcolorNUM );
    return;
}

/* print one string with a special color and end this line (will return to original color in the end) */
void colorprintln( std::string _dataPrint , int _colorNUM , int _originalcolorNUM ){
    setcolor( _colorNUM );
    std::cout << _dataPrint << std::endl;
    setcolor( _originalcolorNUM );
    return;
}

/* print WARNING */
void printWARNING( int _after_colorNUM ){
    colorprintf( "WARNING" , PURPIL , WHITE );
    std::cout << "> ";
    setcolor( _after_colorNUM );
    return;
}

/* print ERROR */
void printERROR( int _after_colorNUM ){
    colorprintf( "ERROR" , RED , WHITE );
    std::cout << "> ";
    setcolor( _after_colorNUM );
    return;
}

/* print normally line begin */
void printLINEBEGIN( int _after_colorNUM ){
    colorprintf( "Hash Check Master> " , WHITE , _after_colorNUM );
    return;
}

void printhelp(){
    printLINEBEGIN( WHITE );
    colorprintf( "-l ${Checklist Path}" , YELLOW , WHITE );
    std::cout << ": set the checklist path" << std::endl;
    printLINEBEGIN( WHITE );
    colorprintf( "-d ${Workfolder Path}" , YELLOW , WHITE );
    std::cout << ": set default workfolder" << std::endl;
    printLINEBEGIN( WHITE );
    colorprintf( "-c ${Folder Path} -ln ${Checklist Name}" , YELLOW , WHITE );
    std::cout << ": create one hash checklist for a folder" << std::endl;
    printLINEBEGIN( WHITE );
    colorprintf( "-c ${Folder Path} -e ${File Extension} -ln ${Checklist Name}" , YELLOW , WHITE );
    std::cout << ": create one hash checklist only with files with given extension for a folder " << std::endl;
    return; 
}

/* print unavailable hash type in main program */
void printCheckUnavailable( uint8_t _HashType ){
    printWARNING( WHITE );
    colorprintf( HashTypeChange( _HashType ) , YELLOW , WHITE );
    std::cout << " Check is Unavailable" << std::endl;
    return;
}

/* print available hash type in main program */
void printCheckAvailable( uint8_t _HashType ){
    printLINEBEGIN( WHITE );
    colorprintf( HashTypeChange( _HashType ) , YELLOW , WHITE );
    std::cout << " Check is Available" << std::endl;
    return;
}

/* change Hash type from uint8_t to char* */
std::string HashTypeChange( uint8_t _HashType ){
    switch ( _HashType ){
        case MD5:
            return "MD5";
            break;
    
        case SHA1:
            return "SHA1";
            break;
    
        case SHA256:
            return "SHA256";
            break;
    
        case SHA512:
            return "SHA512";
            break;
    }
    return "error";
}