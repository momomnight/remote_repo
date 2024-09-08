@echo off

if not exist "D:\UE_5.3\UnrealEngine-5.3.2-release\Engine\Binaries\Win64\ReflectionGenerate.exe" goto ReflectionGenerate_Error

D:\UE_5.3\UnrealEngine-5.3.2-release\Engine\Binaries\Win64\ReflectionGenerate.exe ProjectPath=%cd%

if errorlevel 1 goto Program_Error

D:"\Program Files\""\Epic Games\"UE_5.3\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe -projectfiles -project="%~dp0EditorExtension.uproject"

if errorlevel 1 goto ProjectFiles_Error

exit /B 0

:ProjectFiles_Error
echo.
echo ProjectFiles ERROR: Failure to refresh project;
echo.
pause
goto Exit

:Program_Error
echo.
echo ProjectProgram ERROR: Program startup failure;
echo.
pause
goto Exit

:ReflectionGenerate_Error
echo.
echo ProjectFiles ERROR: ReflectionGenerate.exe not exist;
echo.
pause
goto Exit