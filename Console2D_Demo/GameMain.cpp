#include "GameMain.h"
Console2D::C2D_Block RB[800];
int I = 0;
int hp = 100;
void Console2D::start()
{
	this->initsprite("X"); //设置主角样貌
	this->initspritexy(10, 14); //设置主角初始位置
	this->initWorld(20, 40);//设置世界大小
	Other::HideCursor(); //隐藏光标
	Map::Draw::Welcome_ui::MAIN(this); //绘制地图
}
void Console2D::update()
{
	view_map(); //刷新地图
	/*键盘动作的处理*/
	if (!hp)
	{
		system("cls");
		printf("Game Over");
		LOG("END");
		Console2D_Exit::Over();
	}
	if (_kbhit()) //检测到键盘动作
	{
		this->messageBlock("", ""); //清空信息
		char ch = _getch(); //获取键盘
		//移动（WASD）
		if (ch == 'w' || ch == 'W')
		{
			this->Move(direction::UP); //值为0（方向枚举-》上）主角向上方移动
		}
		else if (ch == 'a' || ch == 'A')
		{
			this->Move(direction::LEFT); //向左移动
		}
		else if (ch == 's' || ch == 'S')
		{
			this->Move(direction::DOWN); //向下移动
		}
		else if (ch == 'd' || ch == 'D')
		{
			this->Move(direction::RIGHT); //向右移动
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