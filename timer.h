#ifndef TIMER_H
#define TIMER_H

#define PREF_15MIN		 900
#define PREF_30MIN		1800
#define PREF_1H			3600
#define PREF_2H			7200

class Timer
{
 public:
 Timer() {};
 ~Timer();

 int SetTimer(int nbr_sec);
 int CancelTimer();
};

#endif // TIMER_H