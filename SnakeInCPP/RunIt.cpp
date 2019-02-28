#include "pch.h"
#include "RunIt.h"
#pragma warning(disable : 4996 4390 6031) 

RunIt::RunIt()
{
}

RunIt::~RunIt()
{
}

bool RunIt::GetKey(int &dir) //获取按键并判断方向
{
	int key = -1; //键盘输入

	if (kbhit()!=0) //检查当前键盘是否有输入
	{
		while (kbhit()!=0)
			key = getch();
		switch (key)
		{
		case 72:
			dir = 0; break; //上
		case 80:
			dir = 1; break; //下
		case 75:
			dir = 2; break; //左
		case 77:
			dir = 3; break; //右
		}
		return true; 
	}
	return false; 
}

void RunIt::Show(Snake &s, GameMap &m) //刷新显示地图
{
	while (1)
	{
		int k;
		_sleep(RFRESHTIME); //延迟半秒刷新
		if (GetKey(k))
			s.NewNode(k);
		s.MoveSnake();

		if (s.isOVER)
		{
			cout << "\t\n**Game Over**\n";
			cout << " >_< " << endl;
			getchar(); 
			break; //游戏结束,回到Snake-cpp.cpp
		}	
		m.ShowMap(s.snakelength);
	}
}

void RunIt::RunTheGame()
{
	system("title Snake"); //控制台标题
	//初始化地图
	GameMap newgame;
	
	//初始化蛇
	Snake newsnake;
	newsnake.InitialSnake();
	newgame.CreatFood(); 
	//显示地图
	newgame.ShowMap();
	//读按键,蛇头开始运动
	int k; 
	getch(); 
	GetKey(k); 
	newsnake.NewNode(k); 
	//刷新地图
	newgame.ShowMap(); 
	//进入循环
	Show(newsnake, newgame);
}

