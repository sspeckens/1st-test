#include "timer.h"
#include <windows.h>

int Timer::SetTimer(int nbr_sec){
	bool b;
	InitiateSystemShutdown(NULL,NULL,nbr_sec,TRUE,FALSE);

	return 0;
}

int Timer::CancelTimer(){
	bool b;
	b=AbortSystemShutdown(NULL);
	return 0;
}


