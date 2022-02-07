#include "draw_function.h"
extern Console2D::C2D_Block Start_Button[5]; //����Start��ť
void Map::Draw::Welcome_ui::MAIN(Console2D *console)
{
	
	string Msg = "Console 2D Demo V1.0"; //������Ϣ
	for (size_t i = 0; i < Msg.length(); i++)
	{
		if (Msg[i] != ' ') { //�ж��Ƿ�Ϊ�ո�
			string Bmp = "A"; //��ʱ����
			Console2D::C2D_Block Msg_Block; //����ṹ��
			Bmp[0] = Msg[i]; //��Bmp�ĵ�һλ�����Msg������ͬ
			/*���÷���ṹ��*/
			Msg_Block.Block_str = Bmp;
			Msg_Block.Block_x = 5;
			Msg_Block.Block_y = 5 + i;
			console->C2D_Create_Block(&Msg_Block); //���Ʒ���
			console->BlockBodyCollisionDetection(Msg_Block.count); //����������ײ���

			
		}

	}
	//����Start��ť
	string Start_Msg = "START";
	for (size_t i = 0; i < 5; i++)
	{
		string Bmp = "A"; //��ʱ����
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