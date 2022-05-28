#include<bits/stdc++.h>
#include"defMain.h"

using namespace std;

int _bit = MD5_CHECK;
//char _lineDATA[] = "c16e122b798e5b9d0ea0a4a3f459dac1 *Win_Hash-CheckMaster\\[test]\\ifstream.otheraddress.test.sh1";
char _lineDATA[] = "c16e122b798e5b9d0ea0a4a3f459dac1 D:\\C++Program\\Win_Hash-CheckMaster\\[test]\\ifstream.otheraddress.test.sh1";

int main(){
    std::string _Hash_IN_line( _lineDATA , _bit );  /* the hash code in this line */
    std::string _address_IN_line;  /* the file address in this line */
    if ( _lineDATA[_bit+1] == '*' )
    {
        _address_IN_line = "D:\\C++Program\\";
        //copy default folder
        int _temp = _bit + 2;
        while ( _lineDATA[_temp] != '\0' )
        {
            _address_IN_line += _lineDATA[_temp];
            _temp++;
        }
    }
    //using default folder to copy file address
    else
    {
        int _temp = _bit + 1;
        while ( _lineDATA[_temp] != '\0' )
        {
            _address_IN_line += _lineDATA[_temp];
            _temp++;
        }
    }
    cout << _Hash_IN_line << endl;
    cout << _address_IN_line;
    return 0;
}