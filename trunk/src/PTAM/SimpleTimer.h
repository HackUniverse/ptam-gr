
#ifndef __SIMPLETIMER_H
#define __SIMPLETIMER_H

//This is Windows timer implementation.

struct TimerStruct
{
	__int64       frequency;						// Ƶ��
	float         resolution;						// ʱ����
	unsigned long mm_timer_start;					// ��ý���ʱ���Ŀ�ʼʱ��
	unsigned long mm_timer_elapsed;				// ��ý���ʱ���Ŀ�ʼʱ��
	bool		performance_timer;					// ʹ��Performance Timer?
	__int64       performance_timer_start;		// Performance Timer��ʱ���Ŀ�ʼʱ��
	__int64       performance_timer_elapsed;		// Performance Timer��ʱ���Ŀ�ʼʱ��
} ;

//TODO: modify this to enable multiple timers
class SimpleTimer{
public:
	void initTimer();									// ��ʼ�����ǵļ�ʱ��
	float getTime();									// ���ؾ�����ʱ�䣬�Ժ���Ϊ��λ

protected:
	TimerStruct mTimerStruct;
};

#endif