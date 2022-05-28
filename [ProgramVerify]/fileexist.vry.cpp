#include<bits/stdc++.h>

using namespace std;

/*
bool isaddressConformable( std::string _address ){
    FILE *_addressTest;
    //char _addresscopy[1000];
    //strcpy( _addresscopy , _address.c_str() );
    //setlocale( LC_ALL , "Chinese-simplified" );
    _addressTest = fopen( _address.c_str() , "r" );
    if ( _addressTest != NULL )
    {
        return true;
    }
    return false;
    //setlocale( LC_ALL , "C" );
}
*/

int main(){
    char command[] = "if exist C:\\Users\\LSC06\\Desktop\\86.mkv echo FileExist >D:\\C++Program\\Win_Hash-CheckMaster\\test.log";
    system( command );
    ifstream File;
    File.open( "D:\\C++Program\\Win_Hash-CheckMaster\\test.log" );
    char ans[1000];
    File.getline( ans , sizeof( ans ) );
    cout << ans << endl;
    return 0;
    /*
    //
    fstream File;
    char address[] = "C:\\Users\\LSC06\\Desktop\\86.mkv";
    cout << address << endl;
    //locale::global( locale( "Chinese-simplified" ) );
    //setlocale( LC_ALL , "" );
    //File.open( "D:\\C++Program\\Win_Hash-CheckMaster\\Hash-CheckMaster.exe" );
    File.open( address );
    //setlocale( LC_ALL , "C" );
    //locale::global( locale( "C" ) );
    if ( !File )
    {
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    //
    return 0;
    */
}