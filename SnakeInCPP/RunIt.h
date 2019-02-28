/*
	控制游戏进程类
*/
#pragma once
#include "GameMap.h"
#include "Snake.h"
#include <conio.h>

const int RFRESHTIME = 600; //地图刷新时间(0-1000)ms

class RunIt
{
public:
	RunIt();
	~RunIt();
	bool GetKey(int &dir); //获取按键并判断方向
	void Show(Snake &s, GameMap & m); //刷新显示地图
	void RunTheGame(); 
};

