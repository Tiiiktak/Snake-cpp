/*
	游戏地图类
*/
#pragma once
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std; 

const int H = 8; //地图的高 
const int W = 16; //地图的宽
extern char Map[H][W]; //声明全局数组

class GameMap
{
public:
	GameMap(); 
	void ShowMap(int length = 1); //显示地图
	void CreatFood(); //随机产生食物
	void ShowScore(int x, int len); //显示成绩
};
