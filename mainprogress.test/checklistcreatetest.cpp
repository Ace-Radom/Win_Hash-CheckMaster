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
    Hash.changeHashCheckMode( MD5 );
    Hash.createChecklist( address , ".png" );
    system( "pause" );
    return 0;
}