#include <windows.h>
#include <WinUser.h>
#include <iostream>
#include <string>
#include <string.h>
#include<thread>
#include <conio.h>
using namespace std;
// Forward declaration of the LeftClick function
int x;
int y;
int IsFinished = 0;

bool shake = false;
void GetCursorw() {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    int y;
    x = cursorPos.x;
    y = cursorPos.y;
    cout << x << endl << y << endl;
    Sleep(50);
};
void LeftClick()
{
    INPUT    Input = { 0 };
    // left down
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    ::SendInput(1, &Input, sizeof(INPUT));

    // left up
    ::ZeroMemory(&Input, sizeof(INPUT));
    Input.type = INPUT_MOUSE;
    Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    ::SendInput(1, &Input, sizeof(INPUT));
};
void autoclick() {
    do {
        LeftClick();
        Sleep(5);
        LeftClick();
        Sleep(5);
        LeftClick();
        Sleep(5);
        LeftClick();
        Sleep(5);
        LeftClick();
        Sleep(5);
        LeftClick();
        Sleep(5);
        LeftClick();
        Sleep(5);
        LeftClick();
        Sleep(5);
    } while (IsFinished == 0);
    system("start "" /min C:\\Program Files");
    exit(0);
};
// Forward declaration of the MouseMove function
void toggle() {
    if (RegisterHotKey(
        NULL,
        2,
        MOD_NOREPEAT,
        191))  //0x42 is 'b'
    {
        printf("Hotkey 'ALT+/' registered, using MOD_NOREPEAT flag\n");
    }
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            IsFinished = 1;

        };
    };

};
int main()
{

    if (RegisterHotKey(
        NULL,
        1,
        MOD_ALT | MOD_NOREPEAT,
        191))  //0x42 is 'b'
    {
        printf("Hotkey 'ALT+/' registered, using MOD_NOREPEAT flag\n");
    }
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            printf("WM_HOTKEY received\n");

            thread second(toggle);
            thread first(autoclick);
            second.join();
            first.join();          // pauses until first finishes
// pauses until second finishes
        };
    };

};

// LeftClick function
//1043 793
/*    Sleep(10000);
    // This structure will be used to create the keyboard
      // input event.
    INPUT ip;

    // Pause for 5 seconds.
    Sleep(5000);

    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the "A" key
    ip.ki.wVk = 0x1B; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
    int x = 1043;
    int y = 793;
  SetCursorPos(x,y);*/
