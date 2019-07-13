#define _WIN32_WINNT 0x0500


#include "Headers/Game.hpp"
#include <windows.h>
#include <iostream>

int main()
{
    HWND hWnd = GetConsoleWindow(); 
    ShowWindow( hWnd, SW_HIDE ); 
   
    Game::getInstance()->start();
    Game::getInstance()->destroy();
    
    return 0;
}