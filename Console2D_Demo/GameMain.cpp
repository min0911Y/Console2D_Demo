#include "GameMain.h"
Console2D::C2D_Block RB[800];
int I = 0;
int hp = 100;
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
	if (!hp)
	{
		system("cls");
		printf("Game Over");
		LOG("END");
		Console2D_Exit::Over();
	}
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
	if (this->get_worldcount() == 0) {
		for (int i = 0; i < 5; i++)
		{
			if (this->DetermineCmpiBox(Start_Button[i].count))
			{
				clearall();
				break;
			}
		}
	}
	if (this->get_worldcount() == 1)
	{
		for (int i = 0; i < I; i++)
		{
			if (DetermineCmpiBox(RB[i].count))
			{
				hp--;
				break;
			}
		}
		this->messageBlock("HP:", to_string(hp));
	}
}
void Console2D::Thread()
{
	Other::Srand();

	while (1)
	{
		if (this->get_worldcount() == 1)
		{
			if (I < 800) {
				RB[I] = Other::random_Create_Block("#", *this);
				this->C2D_Create_Block(&RB[I]);
				this->BlockBodyCollisionDetection(RB[I].count);
				I++;
			}
			else {
				system("cls && echo YOU R WIN && PAUSE");
				Console2D_Exit::Over();
			}

		}

	}
}