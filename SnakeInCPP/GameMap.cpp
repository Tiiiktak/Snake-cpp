#include "pch.h"
#include "GameMap.h"

char Map[H][W]; //游戏地图

GameMap::GameMap() //地图初始化
{
	memset(Map, '.', sizeof(Map)); //全部为空
}

void GameMap::CreatFood()
{
	int foodx, foody; //食物的坐标
	srand((unsigned)time(0)); //随机种子

	while (1)
	{
		foodx = rand() % H;
		foody = rand() % W;
		if (Map[foodx][foody] == '.')
		{
			Map[foodx][foody] = '*';
			break;
		}
	}
}

void GameMap::ShowScore(int x, int len) //显示当前分数(长度-1)
{
	if (x + 1 == H / 2)
		cout << "\tSnake Game"; //在分数上一行输出游戏名

	if (x == H / 2) //当在中间行的时候才输出
		cout << "\tTotalScore: " << len-1; 
}

void GameMap::ShowMap(int length) //显示地图
{
	system("cls"); //清空地图再显示刷新好的地图

	for (int i = 0; i < H; i++)
	{
		cout << "\t"; 
		for (int j = 0; j < W; j++)
		{
			cout << Map[i][j];
		}
		ShowScore(i, length); 
		cout << endl;
	}
	cout << "\nPress any arrow key to play the game" << endl; 
}