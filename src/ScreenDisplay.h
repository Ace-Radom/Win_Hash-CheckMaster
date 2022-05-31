#ifndef _SCREENDISPLAY_H_
#define _SCREENDISPLAY_H_

#include<iostream>
#include<windows.h>
#include"defMain.h"

void setcolor( int _colorNUM );
void colorprintf( std::string _dataPrint , int _colorNUM , int _originalcolorNUM );
void colorprintln( std::string _dataPrint , int _colorNUM , int _originalcolorNUM );

void printWARNING( int _after_colorNUM );
void printERROR( int _after_colorNUM );
void printLINEBEGIN( int _after_colorNUM );

void printhelp();

void printCheckUnavailable( uint8_t _HashType );
void printCheckAvailable( uint8_t _HashType );
std::string HashTypeChange( uint8_t _HashType );

#endif