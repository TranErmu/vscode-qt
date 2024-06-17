@echo off
setlocal

set build_dir="./build"
if not exist %build_dir% mkdir %build_dir%

set root_path=""
for /f "delims=" %%i in ('pwd') do set "root_path=%%i"
@REM echo %root_path%

if "%1" equ "clean" (
    cmd /c "cd /d %root_path%\ &&  del /S /Q %build_dir%\* > NUL 2>&1"
    exit /b 0
)

set cmake_tool=""
for /f "delims=" %%i in ('where cmake') do set "cmake_tool=%%i"
@REM echo %cmake_tool%

set make_tool=""
for /f "delims=" %%i in ('where make') do set "make_tool=%%i"
@REM echo %make_tool%



call :build_proj
exit /b 0

:build_proj
cd %build_dir%
%cmake_tool% -G "MinGW Makefiles" %root_path%
%make_tool%
exit /b 0
