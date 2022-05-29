#include<bits/stdc++.h>
#include"logIO.h"

logIO logtest;

int main(){
    logtest.create( "D:\\C++Program\\Win_Hash-CheckMaster\\mainprogress.test\\logtest.log" );
    logtest.write( "first log write test" );
    logtest.endl();
    logtest.writeln( "first log writeln test" );
    logtest.close();
    return 0;
}