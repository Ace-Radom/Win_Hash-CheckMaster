#include<bits/stdc++.h>

using namespace std;

char cmd[1024] = {0};

int main(){
    FILE *file;
    if ( ( file = _popen( "ping www.youtube.com" , "r" ) ) != NULL )
    {
        while ( fgets( cmd , 1024 , file ) != NULL )
        {
            /* code */
        }
        _pclose( file );
    }
    cout << cmd << endl;
    return 0;
}