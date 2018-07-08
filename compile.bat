@echo off

cls
g++ %1.cpp
if %ERRORLEVEL% EQU 0 (
	a.exe
)