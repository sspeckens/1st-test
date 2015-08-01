#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <windows.h>
#include "Timer.h"

#define ID_15MIN  	0x00010
#define ID_30MIN  	0x00020
#define ID_1H   	0x00030
#define ID_2H   	0x00040
#define ID_ABORT  	0x00080
#define ID_Exit 	0x00100

class AppManager
{
 public:
 AppManager() { appInitialized = false; }
 ~AppManager();

 void InitializeComponents(HWND* _windowHandle);
 void WM_COMMAND_MessageHandler(const WPARAM &wParam, const LPARAM &lParam);

 private:
 bool appInitialized;

 HMENU menubarHandle;
 HMENU fileMenuHandle;

 HWND* windowHandle;

 Timer* timer_1;
};

#endif // APPMANAGER_H