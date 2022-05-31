#Command to get the default Workfolder in main program, when the Workfolder is not set by the user
#normally it will only be used at preset in HashCheck.h

$logPath = "$PSScriptRoot\certutil-precheckOutputLOG"
#Write file Path to log
Get-Location | Out-file $logPath
$ans = ( Get-Content $logPath -Tail 3 )[-3]
Write-Output $ans
#delete log
Remove-Item $logPath