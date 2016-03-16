/*
 * Timer.h
 *
 *  Created on: Feb 16, 2016
 *      Author: jker3169
 */

#ifndef MODEL_TIMER_H_
#define MODEL_TIMER_H_

#include <time.h>

class Timer
{
public:
	Timer();
	virtual ~Timer();
	void startTimer();
	void stopTimer();
	void resetTimer();
	void displayTimerInformation();
	long getExecutionTimeInMicrosecounds();
private:
	clock_t executionTime;
};

#endif /* MODEL_TIMER_H_ */
