#pragma once

#ifndef _DOG
#define _DOG

#include <vector>
#include "Marker.h"
using namespace std;

#define PI 3.1415927

enum GoType
{
	By_Walk,
	By_Run
};

enum ActionType
{
	Action_Bored,
	Action_Eating,
	Action_Jumping,
};

class Dog
{
private:
	vector<int> hungry;  //0:food 1:jump

public:
	Dog();
	~Dog();

	float direction[3];	//�������
	float position[3];	//λ�ò���

	float idlemidposp[3]; //idleʱС���˶�����λ��
	float idledir[3]; //idle֮ǰС�����˶�����
	Marker targetmarker; //targetmarker;

};

#endif