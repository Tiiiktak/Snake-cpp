/*
	蛇类
*/
#include "pch.h"
#include "Snake.h"
#pragma warning(disable : 4996) 

Snake::Snake()
{
}

Snake::~Snake()
{
}

bool Snake::CheckHead(int x, int y)	//(x,y)是蛇头未移动前节点
{
	snake snakehead = snakebody.front();
	int hx = snakehead.x; 
	int hy = snakehead.y;
	if (Map[hx][hy] == '.') //若蛇头所处点为空
	{
		Map[hx][hy] = '@';
		//ShowSnake(snakehead.x, snakehead.y, 1); 
	}
	else if (Map[hx][hy] == '*') //是食物
	{
		//(x,y)成为蛇身新节点
		IncreaseSnake(x, y);
		Map[hx][hy] = '@';
		//ShowSnake(snakehead.x, snakehead.y, 1);
		GameMap::CreatFood();
	}
	else //是蛇身,游戏结束
	{
		isOVER = true;
		return false;
	}
	if (snakelength > 1) //蛇尾节点在地图中消除
	{
		int lx = snakebody.back().x;
		int ly = snakebody.back().y;
		Map[lx][ly] = '.';
	}
	
	return true;
}

bool Snake::CheckBorder() //检查蛇头是否越界
{
	if (snakebody.front().x < 0 || snakebody.front().x >= H)
		return true;
	if (snakebody.front().y < 0 || snakebody.front().y >= W)
		return true;
	return false;
}

void Snake::MoveSnake() //移动蛇
{
	snake snakehead = snakebody.front();
	int nowlength = snakelength;
	//保存当前蛇头并置为空
	int x = snakehead.x;
	int y = snakehead.y;
	Map[snakehead.x][snakehead.y] = '.';
	//ShowSnake(x, y, 3);
	//移动蛇头
	snakebody.front().x += dx[snakehead.nowdir];
	snakebody.front().y += dy[snakehead.nowdir];
	//wherethesnakehead(); 
	if (CheckBorder())
	{
		isOVER = true;
		return;
	}
	if (!CheckHead(x, y))
		return;

	if (snakelength == nowlength) //当没有吃到食物,移动蛇身
	{
		list<snake>::iterator t = snakebody.end();
		t--;
		while (t != snakebody.begin())
		{
			if (t == snakebody.end()) //尾节点设为空，再移动
				Map[t->x][t->y] = '.';
			//ShowSnake(t->x, t->y, 3); 
			list<snake>::iterator it = t;
			it--;
			if (it == snakebody.begin()) //若为蛇头后面那个节点
			{
				t->x = x;
				t->y = y;
				t->nowdir = snakehead.nowdir;
			}
			else
			{
				*t = *it;
			}
			Map[t->x][t->y] = '#';
			//ShowSnake(t->x, t->y); 
			t--;
		}
	}
}

void Snake::InitialSnake() //初始化
{
	srand((unsigned)time(0)); //随机种子
	snake snakehead;
	snakehead.x = rand() % H;
	snakehead.y = rand() % W;
	snakehead.nowdir = -1; 
	Map[snakehead.x][snakehead.y] = '@';
	snakebody.push_back(snakehead);
	//ShowSnake(snakehead.x, snakehead.y, 1);
}

void Snake::NewNode(int key)
{
	snakebody.begin()->nowdir = key; 
	//cout << "snakebody.begin()->nowdir=" << snakebody.begin()->nowdir << endl;
}

void Snake::IncreaseSnake(int x, int y) //蛇增长
{
	//有蛇身时
	//新增的节点为蛇头后面那个
	snake snakenode;
	list<snake>::iterator t = snakebody.begin();
	if (t != snakebody.end())
		t++;

	snakenode.x = x;
	snakenode.y = y;
	snakenode.nowdir = snakebody.front().nowdir;

	snakebody.insert(t, snakenode);
	Map[snakenode.x][snakenode.y] = '#';
	//ShowSnake(snakenode.x, snakenode.y);
	snakelength++;
}

void Snake::ShowSnake(int x, int y, int i)
{
	if (i == 2)
		Map[x][y] = '#'; //在地图中标记蛇身
	else if (i == 1)
		Map[x][y] = '@'; //标记蛇头
	else
		Map[x][y] = '.';
}
