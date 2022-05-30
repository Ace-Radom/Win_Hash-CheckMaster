$logPath = "$PSScriptRoot\certutil-precheckOutputLOG"
#get OS version
Get-CimInstance -ClassName Win32_OperatingSystem | Select-Object -property Version | Out-file $logPath
Write-Output "[OS]> OS Version: $( ( Get-Content $logPath -Tail 3 )[-3] )"
#get CPU name
Get-CimInstance -ClassName Win32_Processor | Select-Object -property Name | Out-file $logPath
Write-Output "[OS]> CPU: $( ( Get-Content $logPath -Tail 3 )[-3] )"
#get RAM
$RAMinTotal = ( (Get-CimInstance Win32_PhysicalMemory | Measure-Object -Property capacity -Sum).sum /1gb )
Write-Output "[OS]> Physic RAM: $( $RAMinTotal )"
#delete log
Remove-Item $logPath