#include<bits/stdc++.h>

using namespace std;

int main(){
    string _line;
    getline( cin , _line );
    if ( _line[32] != ' ' )
    {
        cout << "false g";
        return 0;
    }
    for ( int i = 0 ; i < 32 ; i++ )
    {
        if ( !( ( ( _line[i] >= '0' ) && ( _line[i] <= '9' ) ) || ( ( _line[i] >= 'a' ) && ( _line[i] <= 'f' ) ) ) )
        {
            cout << "false t" << i;
            return 0;
        }
    }
    cout << "true";
    return 0;
}