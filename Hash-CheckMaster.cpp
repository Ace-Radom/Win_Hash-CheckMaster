#include<bits/stdc++.h>
#include"HashCheck.h"
#include"ScreenDisplay.h"
#include"logIO.h"

#include"defMain.h"
#include"typedefMain.h"

using namespace std;

bool PSVersionCheck();
void HashPrecheck();

bool HashAvailability[5];  /* availability for four hash types */

int main(){
    printLINEBEGIN( WHITE );
    cout << "Checking Powershell version..." << endl;
    if ( !PSVersionCheck() )
    {
        printERROR( WHITE );
        cout << "Powershell 3.0 or newer is required" << endl;
        system( "pause" );
        return 0;
    }
    //check PS version
    printLINEBEGIN( WHITE );
    cout << "Collecting OS infos..." << endl;
    system( "powershell .\\src\\OSRead.ps1" );
    //collect OS infos
    printLINEBEGIN( WHITE );
    cout << "Checking Hash availability..." << endl;
    memset( HashAvailability , NOT_READY , sizeof( HashAvailability ) );
    HashPrecheck();
    //check hash availability
    if ( !( HashAvailability[MD5] || HashAvailability[SHA1] || HashAvailability[SHA256] || HashAvailability[SHA512] ) )
    {
        printERROR( WHITE );
        cout << "No Hash Type is available, please check if *\\certutil-precheck is modified and certutil support" << endl;
        system( "pause" );
        return 0;
    }
    printLINEBEGIN( WHITE );
    cout << "Pre-Check complete" << endl;
    while ( 1 )
    {
        printLINEBEGIN( WHITE );
        string _COMMAND;
        getline( cin , _COMMAND );
        cout << _COMMAND << endl;
    }
    system( "pause" );
    return 0;
}

/* check if PS version is newer then 3.0 or not */
bool PSVersionCheck(){
    FILE *_PSVersionCheckTemp;
    char _ANS[1024] = {0};
    _PSVersionCheckTemp = _popen( "powershell .\\src\\PSVersioncheck.ps1" , "r" );
    fgets( _ANS , 1024 , _PSVersionCheckTemp );
    //get PSVersioncheck.ps1 respond
    _pclose( _PSVersionCheckTemp );
    if ( strcmp( _ANS , "YES\n" ) == 0 )
    {
        return READY;
    }
    return NOT_READY;
}

/* check each hash type's availabity */
void HashPrecheck(){
    FILE *_HashPrecheckTemp;
    char _ANS[1024] = {0};
    _HashPrecheckTemp = _popen( "powershell .\\src\\certutil-precheck.ps1" , "r" );
    fgets( _ANS , 1024 , _HashPrecheckTemp );
    //get certutil-precheck.ps1 respond for MD5
    if ( strcmp( _ANS , "MD5\n" ) != 0 )
    {
        printCheckUnavailable( MD5 );
        HashAvailability[MD5] = NOT_READY;
    }
    else
    {
        printCheckAvailable( MD5 );
        HashAvailability[MD5] = READY;
    }
    fgets( _ANS , 1024 , _HashPrecheckTemp );
    //get certutil-precheck.ps1 respond for SHA1
    if ( strcmp( _ANS , "SHA1\n" ) != 0 )
    {
        printCheckUnavailable( SHA1 );
        HashAvailability[SHA1] = NOT_READY;
    }
    else
    {
        printCheckAvailable( SHA1 );
        HashAvailability[SHA1] = READY;
    }
    fgets( _ANS , 1024 , _HashPrecheckTemp );
    //get certutil-precheck.ps1 respond for SHA256
    if ( strcmp( _ANS , "SHA256\n" ) != 0 )
    {
        printCheckUnavailable( SHA256 );
        HashAvailability[SHA256] = NOT_READY;
    }
    else
    {
        printCheckAvailable( SHA256 );
        HashAvailability[SHA256] = READY;
    }
    fgets( _ANS , 1024 , _HashPrecheckTemp );
    //get certutil-precheck.ps1 respond for SHA512
    if ( strcmp( _ANS , "SHA512\n" ) != 0 )
    {
        printCheckUnavailable( SHA512 );
        HashAvailability[SHA512] = NOT_READY;
    }
    else
    {
        printCheckAvailable( SHA512 );
        HashAvailability[SHA512] = READY;
    }
    return;
}