#pragma once
#include <list>  
#include "GameMap.h"
#include <conio.h>

class Snake :
	public GameMap
{
public:
	int snakelength = 1; //�ߵĳ���
	void InitialSnake(); //�߳�ʼ��
	void NewNode(int key); //��ȡ���̣�������
	void MoveSnake(); //�ƶ���
	bool isOVER = false;
	Snake();
	~Snake();
private:
	int dx[4] = { -1, 1, 0, 0 }; //�ϡ��¡����ҵķ���
	int dy[4] = { 0, 0, -1, 1 };
	friend class GameMap; 
	struct snake {
		int x, y; //�ߵ�ǰ�ڵ�����
		int nowdir; //�ߵ�ǰ�ڵ㷽��
	}; //�ߵ�ǰ�ڵ�
	list<snake> snakebody;
	bool CheckHead(int x, int y); //�����ͷ�Ƿ�Ե�ʳ��
	bool CheckBorder(); //������Ƿ�Խ��
	void IncreaseSnake(int x = 0, int y = 0); //������ (x,y)ΪҪ����������ڵ�
	void ShowSnake(int x, int y, int i = 2); //��ӡ���ڵ�ͼ��
};

