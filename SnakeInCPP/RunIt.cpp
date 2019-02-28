#include "pch.h"
#include "RunIt.h"
#pragma warning(disable : 4996 4390 6031) 

RunIt::RunIt()
{
}

RunIt::~RunIt()
{
}

bool RunIt::GetKey(int &dir) //��ȡ�������жϷ���
{
	int key = -1; //��������

	if (kbhit()!=0) //��鵱ǰ�����Ƿ�������
	{
		while (kbhit()!=0)
			key = getch();
		switch (key)
		{
		case 72:
			dir = 0; break; //��
		case 80:
			dir = 1; break; //��
		case 75:
			dir = 2; break; //��
		case 77:
			dir = 3; break; //��
		}
		return true; 
	}
	return false; 
}

void RunIt::Show(Snake &s, GameMap &m) //ˢ����ʾ��ͼ
{
	while (1)
	{
		int k;
		_sleep(RFRESHTIME); //�ӳٰ���ˢ��
		if (GetKey(k))
			s.NewNode(k);
		s.MoveSnake();

		if (s.isOVER)
		{
			cout << "\t\n**Game Over**\n";
			cout << " >_< " << endl;
			getchar(); 
			break; //��Ϸ����,�ص�Snake-cpp.cpp
		}	
		m.ShowMap(s.snakelength);
	}
}

void RunIt::RunTheGame()
{
	system("title Snake"); //����̨����
	//��ʼ����ͼ
	GameMap newgame;
	
	//��ʼ����
	Snake newsnake;
	newsnake.InitialSnake();
	newgame.CreatFood(); 
	//��ʾ��ͼ
	newgame.ShowMap();
	//������,��ͷ��ʼ�˶�
	int k; 
	getch(); 
	GetKey(k); 
	newsnake.NewNode(k); 
	//ˢ�µ�ͼ
	newgame.ShowMap(); 
	//����ѭ��
	Show(newsnake, newgame);
}

