#include "GameMain.h"
void Console2D::start()
{
	this->initsprite("X"); //����������ò
	this->initspritexy(10, 14); //�������ǳ�ʼλ��
	this->initWorld(20, 40);//���������С
	Other::HideCursor(); //���ع��
}
void Console2D::update()
{
	view_map(); //ˢ�µ�ͼ
}
void Console2D::Thread()
{
}