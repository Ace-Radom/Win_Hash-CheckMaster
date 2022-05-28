#include<iostream>
#include<windows.h>

using namespace std;

int main(){
    int color = 5 & 0x0F;
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ) , color );
    cout << color << endl;
    return 0;
}