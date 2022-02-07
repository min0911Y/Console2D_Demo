#include "GameMain.h"
void Console2D::start()
{
	this->initsprite("X"); //����������ò
	this->initspritexy(10, 14); //�������ǳ�ʼλ��
	this->initWorld(20, 40);//���������С
	Other::HideCursor(); //���ع��
	Map::Draw::Welcome_ui::MAIN(this); //���Ƶ�ͼ
}
void Console2D::update()
{
	view_map(); //ˢ�µ�ͼ
	/*���̶����Ĵ���*/
	if (_kbhit()) //��⵽���̶���
	{
		this->messageBlock("", ""); //�����Ϣ
		char ch = _getch(); //��ȡ����
		//�ƶ���WASD��
		if (ch == 'w' || ch == 'W')
		{
			this->Move(direction::UP); //ֵΪ0������ö��-���ϣ��������Ϸ��ƶ�
		}
		else if (ch == 'a' || ch == 'A')
		{
			this->Move(direction::LEFT); //�����ƶ�
		}
		else if (ch == 's' || ch == 'S')
		{
			this->Move(direction::DOWN); //�����ƶ�
		}
		else if (ch == 'd' || ch == 'D')
		{
			this->Move(direction::RIGHT); //�����ƶ�
		}
	}
}
void Console2D::Thread()
{
}