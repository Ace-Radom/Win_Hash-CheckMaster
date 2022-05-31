#read OS details and powershell version

#print different color in one line
function Write-Color( [String[]]$Text , 
                      [ConsoleColor[]]$Color = "White" , 
                      [int]$StartTab = 0 , [int] $LinesBefore = 0 , [int] $LinesAfter = 0 , 
                      [string] $LogFile = "" , $TimeFormat = "yyyy-MM-dd HH:mm:ss" ){
    $DefaultColor = $Color[0]
    if ( $LinesBefore -ne 0 ) 
    { 
        for ( $i = 0 ; $i -lt $LinesBefore ; $i++ ) 
        { 
            Write-Host "`n" -NoNewline 
        } 
    } 
    #Add empty line before
    if ( $StartTab -ne 0 ) 
    { 
        for ( $i = 0 ; $i -lt $StartTab ; $i++ )
        { 
            Write-Host "`t" -NoNewLine 
        }
    } 
    #Add TABS before text
    if ( $Color.Count -ge $Text.Count )
    {
        for ( $i = 0 ; $i -lt $Text.Length ; $i++ )
        { 
            Write-Host $Text[$i] -ForegroundColor $Color[$i] -NoNewLine 
        }
    } 
    else
    {
        for ( $i = 0 ; $i -lt $Color.Length ; $i++ ) 
        {
            Write-Host $Text[$i] -ForegroundColor $Color[$i] -NoNewLine
        }
        for ( $i = $Color.Length ; $i -lt $Text.Length ; $i++ )
        {
            Write-Host $Text[$i] -ForegroundColor $DefaultColor -NoNewLine
        }
    }
    Write-Host
        if ( $LinesAfter -ne 0 ) 
        { 
            for ( $i = 0 ; $i -lt $LinesAfter ; $i++ )
            {
                Write-Host "`n"
            }
        } 
        #Add empty line after
        if ( $LogFile -ne "" )
        {
            $TextToFile = ""
            for ( $i = 0 ; $i -lt $Text.Length ; $i++ )
            {
                $TextToFile += $Text[$i]
            }
            Write-Output "[$([datetime]::Now.ToString($TimeFormat))]$TextToFile" | Out-File $LogFile -Encoding unicode -Append
        }
}

$logPath = "$PSScriptRoot\certutil-precheckOutputLOG"
#get OS version
Get-CimInstance -ClassName Win32_OperatingSystem | Select-Object -property Version | Out-file $logPath
Write-Color -Text "[OS]> OS Version: " , $( ( Get-Content $logPath -Tail 3 )[-3] ) -Color white , yellow
#get CPU name
Get-CimInstance -ClassName Win32_Processor | Select-Object -property Name | Out-file $logPath
Write-Color -Text "[OS]> CPU: " , $( ( Get-Content $logPath -Tail 3 )[-3] ) -Color white , yellow
#get RAM
$RAMinTotal = ( ( Get-CimInstance Win32_PhysicalMemory | Measure-Object -Property capacity -Sum ).sum / 1gb )
Write-Color -Text "[OS]> Physic RAM: " , $RAMinTotal -Color white , yellow
#get powershell version
$host | Select-Object -property Version | Out-file $logPath
Write-Color -Text "[OS]> Powershell Version: " , $( ( Get-Content $logPath -Tail 3 )[-3] ) -Color white , yellow
#delete log
Remove-Item $logPath