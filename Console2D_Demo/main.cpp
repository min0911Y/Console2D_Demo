#include "CONSOLE2D.h"
Console2D console;
DWORD WINAPI Fun(LPVOID lpParamter)
{
    Console2D* console = (Console2D*)lpParamter;
    console->Thread();
    return 0L;
}

int main()
{
    HANDLE hThread = CreateThread(NULL, 0, Fun, (Console2D*)&console, 0, NULL);
    CloseHandle(hThread);
    console.game();
    return 0;
}