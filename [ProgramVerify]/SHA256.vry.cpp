#include<bits/stdc++.h>

using namespace std;

char cmd[1024] = {0};

char command[1024] = "certutil -hashfile \"D:\\C++Program\\Win_Hash-CheckMaster\\[ProgramVerify]\\_popen.vry.cpp\" SHA256";

int main(){
    FILE *file;
    if ( ( file = _popen( command , "r" ) ) != NULL )
    {
        fgets( cmd , 1024 , file );
        fgets( cmd , 1024 , file );
        _pclose( file );
    }
    cout << cmd << endl;
}