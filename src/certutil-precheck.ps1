#use for checking if certutil.exe under /system32 is usable or not
#get the hash code of one special file and check if they match or not, and then comes out the result

$logPath = "$PSScriptRoot\certutil-precheckOutputLOG"
$filePath = "$PSScriptRoot\certutil-precheck"
#start MD5 check
certutil -hashfile $filePath MD5 | Out-file $logPath
if ( ( Get-Content $logPath -Tail 2 )[-2] -eq "bd28a36bead761bfb8da8db32aea820a" )
{
    Write-Output "MD5"
}
else
{
    Write-Output "MD5 No"
}
#start SHA1 check
certutil -hashfile $filePath SHA1 | Out-file $logPath
if ( ( Get-Content $logPath -Tail 2 )[-2] -eq "edc5b0e51d43fac1a5418b7c4d64042da5a37655" )
{
    Write-Output "SHA1"
}
else
{
    Write-Output "SHA1 No"
}
#start SHA256 check
certutil -hashfile $filePath SHA256 | Out-file $logPath
if ( ( Get-Content $logPath -Tail 2 )[-2] -eq "cedc6857629142e8e858f7b437aa1226813ea55160f8f03d98cd9a4d2f13d599" )
{
    Write-Output "SHA256"
}
else
{
    Write-Output "SHA256 No"
}
#start SHA512 check
certutil -hashfile $filePath SHA512 | Out-file $logPath
if ( ( Get-Content $logPath -Tail 2 )[-2] -eq "00a22fc1eea8abd9f16d9f7aca4253af2bcaf618fcf9ef82ab0d84d701efc9237c9c1ffaa8c1bb04785725591484bbdd64758879ef4d32e973f9f2148ca08b27" )
{
    Write-Output "SHA512"
}
else
{
    Write-Output "SHA512 No"
}
#check end
#delete log
Remove-Item $logPath
