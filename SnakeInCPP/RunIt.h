/*
	������Ϸ������
*/
#pragma once
#include "GameMap.h"
#include "Snake.h"
#include <conio.h>

const int RFRESHTIME = 600; //��ͼˢ��ʱ��(0-1000)ms

class RunIt
{
public:
	RunIt();
	~RunIt();
	bool GetKey(int &dir); //��ȡ�������жϷ���
	void Show(Snake &s, GameMap & m); //ˢ����ʾ��ͼ
	void RunTheGame(); 
};

