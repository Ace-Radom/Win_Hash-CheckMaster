#check PS version

#use old ways to get Workfolder in order to run on PS 2.0s or older version
$CurrentyDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$logPath = "$CurrentyDir\certutil-precheckOutputLOG"
$host | Select-Object -property Version | Out-file $logPath
if ( ( Get-Content $logPath -Tail 3 )[-3] -lt "3.0" )
{
    Write-Output "NO"
}
else
{
    Write-Output "YES"
}
Remove-Item $logPath