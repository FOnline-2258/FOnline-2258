#2024/12 - ps1 script by cth
#Features cleaning, monitoring the server, killing the process and running it again whenever needed.

$process = Get-Process -Name "fonlineserver" -ErrorAction SilentlyContinue
if ($process){
    Stop-Process -Name "fonlineserver" -Force
}

Write-Output "Cleaning binaries..."

$dirs = @("scripts", "maps")
$fileExtensions = @("*.fosb", "*.fosp", "*.fomapb")
$exclusions = "noexceptionsIguess"
foreach ($dir in $dirs) {
    if (Test-Path $dir) {
        foreach ($ext in $fileExtensions) {
            Get-ChildItem -Path $dir -Filter $ext -Recurse | Where-Object {
                $_.Name -notmatch $exclusions
            } | Remove-Item -Force
        }
    }
}
Write-Output "Starting the server..."

& ./FOnlineServer.exe -start

Write-Output "---"
Write-Output "DONE! The server is running now! Starting server uptime monitoring."
Write-Output "---"

$iterator = 0
$CheckInterval = 10 # Check every N seconds

while ($true) {
    $process = Get-Process -Name "fonlineserver" -ErrorAction SilentlyContinue
    $Host.UI.RawUI.WindowTitle = "Monitor: " + $CheckInterval * $iterator + " seconds"
    $iterator++
    if ($process) {
        $cpuUsage1 = $process | Measure-Object -Property CPU -Sum | Select-Object -ExpandProperty Sum
        Start-Sleep -Seconds $CheckInterval
        if ($iterator % 100 -eq 0){
            Write-Host $CheckInterval * 100 + " second tick"
        }
        $cpuUsage2 = $process | Measure-Object -Property CPU -Sum | Select-Object -ExpandProperty Sum
        if ($cpuUsage1 -eq $cpuUsage2) {
            Write-Host "CPU is not being used by the server. Restarting Fonline Server..."
            Stop-Process -Name "fonlineserver" -Force
            & ./FOnlineServer.exe -start
        }
    } else {
        Write-Host "Fonline server is not running. Starting it..."
        & ./FOnlineServer.exe -start
    }
}
