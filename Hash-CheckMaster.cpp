#include<bits/stdc++.h>
#include"HashCheck.h"
#include"ScreenDisplay.h"
#include"logIO.h"

#include"defMain.h"
#include"typedefMain.h"

using namespace std;

bool HashAvailability[5];  /* availability for four hash types */

HashCheck Hash;
//logIO LOG;

int CheckTypeChange( string _type );
bool PSVersionCheck();
bool Complete;
void HashPrecheck();
string strlowercase( string _str );
void check();
void create();

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
    Hash.resetall();
    while ( 1 )
    {
        Complete = false;
        printLINEBEGIN( WHITE );
        cout << "Hash Check or Create Checklist? (input check / create)" << endl;
        printLINEBEGIN( WHITE );
        string Command;
        getline( cin , Command );
        if ( strlowercase( Command ) == "check" )
        {
            check();
            if ( Complete )
            {
                system( "pause" );
                return 0;
            }
        }
        else
        {
            if ( strlowercase( Command ) == "create" )
            {
                create();
                if ( Complete )
                {
                    system( "pause" );
                    return 0;
                }
            }
            else
            {
                printERROR( WHITE );
                cout << "Wrong Command" << endl;
            }
        }
    }
    system( "pause" );
    return 0;
}

int CheckTypeChange( string _type ){
    if ( strlowercase( _type ) == "md5" )
    {
        return MD5;
    }
    if ( strlowercase( _type ) == "sha1" )
    {
        return SHA1;
    }
    if ( strlowercase( _type ) == "sha256" )
    {
        return SHA256;
    }
    if ( strlowercase( _type ) == "sha512" )
    {
        return SHA512;
    }
    return _ERROR_;
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

/* Lowercase all upper case letters */
string strlowercase( string _str ){
    for ( int i = 0 ; i < _str.length() ; i++ )
    {
        if ( _str[i] >= 'A' && _str[i] <= 'Z' )
        {
            _str[i] += 32;
        }
    }
    return _str;
}

void check(){
    printLINEBEGIN( WHITE );
    cout << "Please input Workfolder Path: ";
    string _Workfolder;
    getline( cin , _Workfolder );
    printLINEBEGIN( WHITE );
    cout << "Please set Checklist Path: ";
    string _Checklist;
    getline( cin , _Checklist );
    printLINEBEGIN( WHITE );
    cout << "Please set Hash Type: ";
    string _Type;
    cin >> _Type;
    if ( CheckTypeChange( _Type ) == _ERROR_ )
    {
        printERROR( WHITE );
        cout << "Wrong or unsupported Hash Type" << endl;
        return;
    }
    Hash.setWorkfolder( _Workfolder );
    Hash.setChecklist( CheckTypeChange( _Type ) , _Checklist );
    Hash.checkstart();
    Complete = true;
    return;
}

void create(){
    printLINEBEGIN( WHITE );
    cout << "Please input Workfolder Path: ";
    string _Workfolder;
    getline( cin , _Workfolder );
    printLINEBEGIN( WHITE );
    cout << "Please set Checklist Name: ";
    string _Checklist;
    getline( cin , _Checklist );
    printLINEBEGIN( WHITE );
    cout << "Please set Hash Type: ";
    string _Type;
    cin >> _Type;
    if ( CheckTypeChange( _Type ) == _ERROR_ )
    {
        printERROR( WHITE );
        cout << "Wrong or unsupported Hash Type" << endl;
        return;
    }
    Hash.setWorkfolder( _Workfolder );
    Hash.changeHashCheckMode( CheckTypeChange( _Type ) );
    Hash.createChecklist( _Checklist );
    Complete = true;
    return;
}