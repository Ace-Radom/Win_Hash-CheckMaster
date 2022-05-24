#ifndef _SCREENDISPLAY_H_
#define _SCREENDISPLAY_H_

#include<iostream>
#include<windows.h>
#include"defMain.h"

void setcolor( int _colorNUM );
void colorprintf( std::string _dataPrint , int _colorNUM , int _originalcolorNUM );
void colorprintln( std::string _dataPrint , int _colorNUM , int _originalcolorNUM );

#endif