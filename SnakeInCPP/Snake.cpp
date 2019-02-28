/*
	����
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

bool Snake::CheckHead(int x, int y)	//(x,y)����ͷδ�ƶ�ǰ�ڵ�
{
	snake snakehead = snakebody.front();
	int hx = snakehead.x; 
	int hy = snakehead.y;
	if (Map[hx][hy] == '.') //����ͷ������Ϊ��
	{
		Map[hx][hy] = '@';
		//ShowSnake(snakehead.x, snakehead.y, 1); 
	}
	else if (Map[hx][hy] == '*') //��ʳ��
	{
		//(x,y)��Ϊ�����½ڵ�
		IncreaseSnake(x, y);
		Map[hx][hy] = '@';
		//ShowSnake(snakehead.x, snakehead.y, 1);
		GameMap::CreatFood();
	}
	else //������,��Ϸ����
	{
		isOVER = true;
		return false;
	}
	if (snakelength > 1) //��β�ڵ��ڵ�ͼ������
	{
		int lx = snakebody.back().x;
		int ly = snakebody.back().y;
		Map[lx][ly] = '.';
	}
	
	return true;
}

bool Snake::CheckBorder() //�����ͷ�Ƿ�Խ��
{
	if (snakebody.front().x < 0 || snakebody.front().x >= H)
		return true;
	if (snakebody.front().y < 0 || snakebody.front().y >= W)
		return true;
	return false;
}

void Snake::MoveSnake() //�ƶ���
{
	snake snakehead = snakebody.front();
	int nowlength = snakelength;
	//���浱ǰ��ͷ����Ϊ��
	int x = snakehead.x;
	int y = snakehead.y;
	Map[snakehead.x][snakehead.y] = '.';
	//ShowSnake(x, y, 3);
	//�ƶ���ͷ
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

	if (snakelength == nowlength) //��û�гԵ�ʳ��,�ƶ�����
	{
		list<snake>::iterator t = snakebody.end();
		t--;
		while (t != snakebody.begin())
		{
			if (t == snakebody.end()) //β�ڵ���Ϊ�գ����ƶ�
				Map[t->x][t->y] = '.';
			//ShowSnake(t->x, t->y, 3); 
			list<snake>::iterator it = t;
			it--;
			if (it == snakebody.begin()) //��Ϊ��ͷ�����Ǹ��ڵ�
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

void Snake::InitialSnake() //��ʼ��
{
	srand((unsigned)time(0)); //�������
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

void Snake::IncreaseSnake(int x, int y) //������
{
	//������ʱ
	//�����Ľڵ�Ϊ��ͷ�����Ǹ�
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
		Map[x][y] = '#'; //�ڵ�ͼ�б������
	else if (i == 1)
		Map[x][y] = '@'; //�����ͷ
	else
		Map[x][y] = '.';
}
