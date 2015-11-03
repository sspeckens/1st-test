#include "AppManager.h"

#include <iostream>

using namespace std;


AppManager::~AppManager(){
 windowHandle = NULL;
 appInitialized = false;
}

void AppManager::InitializeComponents(HWND* _windowHandle){
 cout<<"AppManager::InitializeComponents"<<endl;

 windowHandle = _windowHandle;

 menubarHandle = CreateMenu();
 fileMenuHandle = CreateMenu();

 AppendMenu(menubarHandle, MF_POPUP, (UINT_PTR)fileMenuHandle, "File");
 AppendMenu(fileMenuHandle, MF_STRING, ID_1MIN, "1 Min");
 AppendMenu(fileMenuHandle, MF_STRING, ID_15MIN, "15 Min");
 AppendMenu(fileMenuHandle, MF_STRING, ID_30MIN, "30 Min");
 AppendMenu(fileMenuHandle, MF_STRING, ID_1H, "1 Hour");
 AppendMenu(fileMenuHandle, MF_STRING, ID_2H, "2 Hours");
 AppendMenu(fileMenuHandle, MF_STRING, ID_ABORT, "Abort timer !");
 AppendMenu(fileMenuHandle, MF_STRING, ID_Exit, "Exit");
 SetMenu(*windowHandle,menubarHandle);

 timer_1=new Timer();
 appInitialized = true;
}

void AppManager::WM_COMMAND_MessageHandler(const WPARAM &wParam, const LPARAM &lParam){
 int a;
 if(!appInitialized) return;
 cout<<"AppManager::WM_COMMAND_MessageHandler "<<LOWORD(wParam)<<endl;
 int temp = LOWORD(wParam);
 if(temp == ID_Exit) exit(0);
 else if(temp == ID_1MIN) 	a=timer_1->SetTimer(PREF_1MIN);
 else if(temp == ID_15MIN) 	a=timer_1->SetTimer(PREF_15MIN);
 else if(temp == ID_30MIN) 	a=timer_1->SetTimer(PREF_30MIN);
 else if(temp == ID_1H) 	a=timer_1->SetTimer(PREF_1H);
 else if(temp == ID_2H) 	a=timer_1->SetTimer(PREF_2H);
 else if(temp == ID_ABORT) 	a=timer_1->CancelTimer();
 else return;

}

