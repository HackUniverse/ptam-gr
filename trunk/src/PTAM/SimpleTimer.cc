

#include "SimpleTimer.h"
#include <Windows.h>
#include  <MMSystem.h>



void SimpleTimer::initTimer()									// ��ʼ�����ǵļ�ʱ��
{
	memset(&mTimerStruct, 0, sizeof(mTimerStruct));					// ��ռ�ʱ���ṹ

	// ���Performance Counter�Ƿ���ã������򴴽�
	if (!QueryPerformanceFrequency((LARGE_INTEGER *) &mTimerStruct.frequency))
	{
		// ���������
		mTimerStruct.performance_timer	= FALSE;				// ����Performance TimerΪfalse
		mTimerStruct.mm_timer_start	= timeGetTime();		// ʹ����ͨ�ļ�ʱ��
		mTimerStruct.resolution	= 1.0f/1000.0f;				// ���õ�λΪ����
		mTimerStruct.frequency		= 1000;						// ����Ƶ��Ϊ1000
		mTimerStruct.mm_timer_elapsed	= mTimerStruct.mm_timer_start;	// ������ʧ��ʱ��Ϊ��ǰ��ʱ��
	}
	else
	{
		// ʹ��Performance Counter��ʱ��
		QueryPerformanceCounter((LARGE_INTEGER *) &mTimerStruct.performance_timer_start);
		mTimerStruct.performance_timer		= TRUE;				// ����Performance TimerΪTRUE
		// �����ʱ�ľ�ȷ��
		mTimerStruct.resolution		= (float) (((double)1.0f)/((double)mTimerStruct.frequency));
		// ������ʧ��ʱ��Ϊ��ǰ��ʱ��
		mTimerStruct.performance_timer_elapsed	= mTimerStruct.performance_timer_start;
	}
}

float SimpleTimer::getTime()									// ���ؾ�����ʱ�䣬�Ժ���Ϊ��λ
{
	__int64 time;										// ʹ��64λ������

	if (mTimerStruct.performance_timer)						// �Ƿ�ʹ��Performance Timer��ʱ��?
	{
		QueryPerformanceCounter((LARGE_INTEGER *) &time);		// ���ص�ǰ��ʱ��
		// ����ʱ���
		return ( (float) ( time - mTimerStruct.performance_timer_start) * mTimerStruct.resolution)*1000.0f;
	}
	else
	{
		// ʹ����ͨ�ļ�ʱ��������ʱ���
		return( (float) ( timeGetTime() - mTimerStruct.mm_timer_start) * mTimerStruct.resolution)*1000.0f;
	}
}