#pragma once
#include <list>  
#include "GameMap.h"
#include <conio.h>

class Snake :
	public GameMap
{
public:
	int snakelength = 1; //蛇的长度
	void InitialSnake(); //蛇初始化
	void NewNode(int key); //读取键盘，增长蛇
	void MoveSnake(); //移动蛇
	bool isOVER = false;
	Snake();
	~Snake();
private:
	int dx[4] = { -1, 1, 0, 0 }; //上、下、左、右的方向
	int dy[4] = { 0, 0, -1, 1 };
	friend class GameMap; 
	struct snake {
		int x, y; //蛇当前节点坐标
		int nowdir; //蛇当前节点方向
	}; //蛇当前节点
	list<snake> snakebody;
	bool CheckHead(int x, int y); //检查蛇头是否吃到食物
	bool CheckBorder(); //检查设是否越界
	void IncreaseSnake(int x = 0, int y = 0); //蛇增长 (x,y)为要新增的蛇身节点
	void ShowSnake(int x, int y, int i = 2); //打印蛇在地图中
};

