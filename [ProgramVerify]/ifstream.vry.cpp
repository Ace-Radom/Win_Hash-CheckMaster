#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream Input;
    Input.open( "ifstream.vry.sha256" , ios::in );
    if ( !Input.is_open() )
    {
        cout << "open error" << endl;
        return 0;
    }
    char data[1000] = {0};
    while ( Input.getline( data , sizeof( data ) ) )
    {
        cout << data << endl;
    }
    Input.close();

    Input.open( "ifstream.vry.md5" , ios::in );
    if ( !Input.is_open() )
    {
        cout << "open error" << endl;
        return 0;
    }
    while ( Input.getline( data , sizeof( data ) ) )
    {
        cout << data << endl;
    }
    Input.close();
    return 0;
}