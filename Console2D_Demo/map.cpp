#include "draw_function.h"
extern Console2D::C2D_Block Start_Button[5]; //声明Start按钮
void Map::Draw::Welcome_ui::MAIN(Console2D *console)
{
	
	string Msg = "Console 2D Demo V1.0"; //定义信息
	for (size_t i = 0; i < Msg.length(); i++)
	{
		if (Msg[i] != ' ') { //判断是否为空格
			string Bmp = "A"; //临时变量
			Console2D::C2D_Block Msg_Block; //方块结构体
			Bmp[0] = Msg[i]; //将Bmp的第一位变成与Msg变量相同
			/*配置方块结构体*/
			Msg_Block.Block_str = Bmp;
			Msg_Block.Block_x = 5;
			Msg_Block.Block_y = 5 + i;
			console->C2D_Create_Block(&Msg_Block); //绘制方块
			console->BlockBodyCollisionDetection(Msg_Block.count); //创建方块碰撞检测

			
		}

	}
	//绘制Start按钮
	string Start_Msg = "START";
	for (size_t i = 0; i < 5; i++)
	{
		string Bmp = "A"; //临时变量
		Bmp[0] = Start_Msg[i];
		Start_Button[i].Block_str = Bmp;
		Start_Button[i].Block_x = 6;
		Start_Button[i].Block_y = 12 + i;
	}
	for (size_t i = 0; i < 5; i++)
	{
		console->C2D_Create_Block(&Start_Button[i]);
		console->BlockBodyCollisionDetection(Start_Button[i].count);
	}
}