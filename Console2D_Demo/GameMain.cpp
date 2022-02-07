#include "GameMain.h"
void Console2D::start()
{
	this->initsprite("X"); //设置主角样貌
	this->initspritexy(10, 14); //设置主角初始位置
	this->initWorld(20, 40);//设置世界大小
	Other::HideCursor(); //隐藏光标
}
void Console2D::update()
{
	view_map(); //刷新地图
}
void Console2D::Thread()
{
}