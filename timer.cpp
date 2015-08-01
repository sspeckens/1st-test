#include "timer.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int Timer::SetTimer(int nbr_sec){
	// shutdown -t xxsecond -s 	=>shutdown
	string s1("shutdown -t ");
	string s2;
	s2=std::to_string(nbr_sec);
	string s3(" -s >log_exe.txt 2>&1");
	string s ;
	s= s1+s2+s3;
	system (s.c_str());
	//system ("pause");
	return 0;
}

int Timer::CancelTimer(){
	// shutdown -a 				=> abort previous shutdown command
	string s("shutdown -a >log_exe.txt 2>&1");
	system (s.c_str());
	//system ("pause");	
	return 0;
}


