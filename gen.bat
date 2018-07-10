@echo off

md %1
cd %1
echo.> %1.cpp
echo.> %1.in
echo.> %1.out
%1.cpp
%1.in
%1.out
