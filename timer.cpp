#include "timer.h"
#include <windows.h>
#include <stdio.h>

int Timer::SetTimer(int nbr_sec){
	bool b;
	b=TimerSystemShutdown(INITIATESHUTDOWN,nbr_sec);
	if (!b)
	{
		DWORD retcode;
		retcode=GetLastError();
		char retcodbuff[15];
		sprintf(retcodbuff, "%lu", retcode);		
	    int msgboxID = MessageBox(
        NULL,
        retcodbuff,
        "Problem Return code received",
        MB_ICONWARNING | MB_OK);
	}
	return 0;
}

int Timer::CancelTimer(){
	bool b;
	b=TimerSystemShutdown(ABORTSHUTDOWN,0);
	if (!b)
	{
		DWORD retcode;
		retcode=GetLastError();
		char retcodbuff[15];
		sprintf(retcodbuff, "%lu", retcode);		
	    int msgboxID = MessageBox(
        NULL,
        retcodbuff,
        "Problem Return code received",
        MB_ICONWARNING | MB_OK);
	}
	return 0;
}


bool Timer::TimerSystemShutdown(int action_code,int nbr_sec)
{
   HANDLE hToken;              // handle to process token 
   TOKEN_PRIVILEGES tkp;       // pointer to token structure 
 
   BOOL fResult;               // system shutdown flag 
 
   // Get the current process token handle so we can get shutdown 
   // privilege. 
 
   if (!OpenProcessToken(GetCurrentProcess(), 
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)) 
      return FALSE; 
 
   // Get the LUID for shutdown privilege. 
 
   LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, 
        &tkp.Privileges[0].Luid); 
 
   tkp.PrivilegeCount = 1;  // one privilege to set    
   tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 
 
   // Get shutdown privilege for this process. 
 
   AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, 
      (PTOKEN_PRIVILEGES) NULL, 0); 
 
   // Cannot test the return value of AdjustTokenPrivileges. 
 
   if (GetLastError() != ERROR_SUCCESS) 
      return FALSE; 
 
   // Action according to the type
 if (action_code==INITIATESHUTDOWN)
   fResult = InitiateSystemShutdown( 
      NULL,    // shut down local computer 
      NULL,   
      nbr_sec,      // time-out period, in seconds 
      TRUE,   
      FALSE);   
 else if(action_code==ABORTSHUTDOWN) 
	fResult = AbortSystemShutdown(NULL);
 
   if (!fResult) 
      return FALSE; 
 
   // Disable shutdown privilege. 
 
   tkp.Privileges[0].Attributes = 0; 
   AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, 
        (PTOKEN_PRIVILEGES) NULL, 0); 
 
   return TRUE; 
}
