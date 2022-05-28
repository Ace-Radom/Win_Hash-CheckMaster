#include<bits/stdc++.h>

using namespace std;

int main(){
    string workfolder;
    string address;
    getline( cin , workfolder );
    getline( cin , address );
    cout << address.replace( address.find( workfolder ) , workfolder.length() , "*" ) << endl;
    return 0;
}