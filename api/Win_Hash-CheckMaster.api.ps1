function Test-Ping
{
    param
    (
        [Switch]
        $t
    )
    if ($t)
    {
        Write-Host '一直ping'
    }
    else
    {
        Write-Host 'ping 4 次'
    }
}