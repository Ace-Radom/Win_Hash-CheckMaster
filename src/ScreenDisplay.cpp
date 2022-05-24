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