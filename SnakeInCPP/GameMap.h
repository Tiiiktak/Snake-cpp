/*
	��Ϸ��ͼ��
*/
#pragma once
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std; 

const int H = 8; //��ͼ�ĸ� 
const int W = 16; //��ͼ�Ŀ�
extern char Map[H][W]; //����ȫ������

class GameMap
{
public:
	GameMap(); 
	void ShowMap(int length = 1); //��ʾ��ͼ
	void CreatFood(); //�������ʳ��
	void ShowScore(int x, int len); //��ʾ�ɼ�
};
