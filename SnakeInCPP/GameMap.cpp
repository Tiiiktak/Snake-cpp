#include "pch.h"
#include "GameMap.h"

char Map[H][W]; //��Ϸ��ͼ

GameMap::GameMap() //��ͼ��ʼ��
{
	memset(Map, '.', sizeof(Map)); //ȫ��Ϊ��
}

void GameMap::CreatFood()
{
	int foodx, foody; //ʳ�������
	srand((unsigned)time(0)); //�������

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

void GameMap::ShowScore(int x, int len) //��ʾ��ǰ����(����-1)
{
	if (x + 1 == H / 2)
		cout << "\tSnake Game"; //�ڷ�����һ�������Ϸ��

	if (x == H / 2) //�����м��е�ʱ������
		cout << "\tTotalScore: " << len-1; 
}

void GameMap::ShowMap(int length) //��ʾ��ͼ
{
	system("cls"); //��յ�ͼ����ʾˢ�ºõĵ�ͼ

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