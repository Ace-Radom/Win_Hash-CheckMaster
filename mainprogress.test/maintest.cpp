#include<bits/stdc++.h>
#include"HashCheck.h"

using namespace std;

HashCheck Hash;
string address;

int main(){
    Hash.resetall();
    getline( cin , address );
    Hash.setWorkfolder( address );
    getline( cin , address );
    Hash.setChecklist( MD5 , address );
    Hash.checkstart();
    system( "pause" );
    return 0;
}