#include<bits/stdc++.h>

using namespace std;

string _Command_INuse;

void make_checkfileexistbat( string _address ){
    _Command_INuse.clear();
    _Command_INuse = "if exist \"";
    _Command_INuse += _address;
    _Command_INuse += "\" echo FileExist";
    cout << _Command_INuse << endl;
    return;
}

void make_hashcheckbat( std::string _address ){
    _Command_INuse.clear();
    _Command_INuse = "certutil -hashfile \"";
    _Command_INuse += _address;
    _Command_INuse += "\" ";
    //link file path and .bat command
    _Command_INuse += "MD5";  
    //link hash type
    return;
}

bool isaddressConformable( string _address ){
    make_checkfileexistbat( _address );
    FILE *_batANS;
    char ans[1024] = {0};
    cout << _Command_INuse.c_str() << endl;
    _batANS = _popen( _Command_INuse.c_str() , "r" );
    fgets( ans , 1024 , _batANS );
    cout << ans << endl;
    if ( strcmp( ans , "FileExist\n" ) == 0 )
    {
        return true;
    }
    return false;
}

bool doHashCheck( std::string _hash , std::string _address ){
    make_hashcheckbat( _address );
    FILE *_batANS;
    char _ans[1024] = {0};
    _batANS = _popen( _Command_INuse.c_str() , "r" );
    fgets( _ans , 1024 , _batANS );
    fgets( _ans , 1024 , _batANS );
    //for 'certutil -hashfile' command, the hash code always appears in the second line
    //therefore fgets() twice in order to get the data in the second line
    pclose( _batANS );
    std::string _hash_copy = _hash + "\n";
    //just like before, there's a \n mark at the end of _ans, therefore _hash also needs to have a \n mark
    if ( strcmp( _ans , _hash_copy.c_str() ) == 0 )
    {
        return true;
    }
    return false;
}

int main(){
    if ( isaddressConformable( "E:\\Anime RAW\\86¨D¥¨¥¤¥Æ¥£¥·¥Ã¥¯¥¹¨D [DDYjiang@U2] [BDRip] [1920¡Á1080 h.264 YUV420 8bit] [FLAC 48kHz£¯24bit 2.0] (Ep 01-11.5 Only)\\86¨D¥¨¥¤¥Æ¥£¥·¥Ã¥¯¥¹¨D [01] [1920x1080 h.264 8bit PCM].mkv" ) )
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    if ( doHashCheck( "f9adcba51204515d0a20457ad7ae07de" , "E:\\Anime RAW\\86¨D¥¨¥¤¥Æ¥£¥·¥Ã¥¯¥¹¨D [DDYjiang@U2] [BDRip] [1920¡Á1080 h.264 YUV420 8bit] [FLAC 48kHz£¯24bit 2.0] (Ep 01-11.5 Only)\\86¨D¥¨¥¤¥Æ¥£¥·¥Ã¥¯¥¹¨D [01] [1920x1080 h.264 8bit PCM].mkv" ) )
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}