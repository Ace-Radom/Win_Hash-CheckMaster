#include<bits/stdc++.h>

using namespace std;

int main(){
    ofstream File( "filecreate.vry.bat" );
    File << "cd /d %~dp0 \nif exist \"C:\\Users\\LSC06\\Desktop\\�½��ı��ĵ�.txt\" echo FileExist >filecreate.vry.log";
    system( "filecreate.vry.bat" );
    return 0;
}