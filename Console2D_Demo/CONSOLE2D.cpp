#include "CONSOLE2D.h"
int Console2D::initWorld(int width, int height)
{
    nextmes[0] = -1;
    nextmes[1] = -1;
    if (width <= 0 || height <= 0)
    {
        return -1;
    }
    if (width > 100 || height > 100)
    {
        return -1;
    }
    this->width = width;
    this->height = height;
    this->Map[sx][sy] = -1; //-1代表sprite的初始位置
    LOG("initWorld::width:" + to_string(width) + " height:" + to_string(height));
    return 0;
}
void Console2D::Move(int x1)
{
    this->Map[x][y] = 0;
    if (x1 == direction::LEFT)
    {
        if (y > 0 && Map[x][y - 1] != 50)
        {
            LOG("MOVE:MOVE LEFT x " + to_string(x) + " y " + to_string(y) + " TO " + to_string(x) + " " + to_string(y - 1));
            y--;
        }
    }
    if (x1 == direction::RIGHT)
    {
        if (y < height - 1 && Map[x][y + 1] != 50)
        {
            LOG("MOVE:MOVE RIGHT X " + to_string(x) + " Y " + to_string(y) + "TO " + to_string(x) + " " + to_string(y + 1));
            y++;
        }
    }
    if (x1 == direction::UP)
    {
        if (x > 0 && Map[x - 1][y] != 50)
        {
            LOG("MOVE:MOVE UP x" + to_string(x) + " y" + to_string(y) + " TO " + to_string(x - 1) + " y" + to_string(y));
            x--;
        }
    }
    if (x1 == direction::DOWN)
    {
        if (x < width - 1 && Map[x + 1][y] != 50)
        {
            LOG("MOVE:MOVE DOWN x " + to_string(x) + " y" + to_string(y) + "TO x" + to_string(x + 1) + " y" + to_string(y));
            x++;
        }
    }
    this->Map[x][y] = -1;
}
void Console2D::initsprite(string str)
{
    this->sprite = str;
    LOG("initsprite::" + str);
}
void Console2D::initspritexy(int sx, int sy)
{
    Map[this->x][this->y] = 0;
    this->sx = sx;
    this->sy = sy;
    this->x = sx;
    this->y = sy;
    Map[this->x][this->y] = -1;
    LOG("initspritexy::init sprite xy sx=" + to_string(sx) + " sy=" + to_string(sy) + " x=" + to_string(x) + " y=" + to_string(y));
}
void Console2D::gotoxy(int x, int y)
{
    //将光标移动到指定位置
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Console2D::BodyCollisionDetection(int x, int y)
{
    if (this->Map[x][y] != 50)
    {
        this->Map[x][y] = 50;
    }
    LOG("BodyCollisionDetection:ADD BodyCollisionDetection OK");
}
void Console2D::CreateBlock(int x, int y, string str)
{
    this->blockMap[x][y] = count;
    this->block[count] = str;
    this->Map[x][y] = 1;
    count++;
    LOG("CreateBlock:" + to_string(count));
}
void Console2D::view_map()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (Map[i][j] == -1)
            {
                cout << sprite;
                continue;
            }
            if (blockMap[i][j] != 0)
            {
                cout << block[blockMap[i][j]];
                continue;
            }
            if (Map[i][j] == 0 || Map[i][j] == 50)
            {

                cout << " ";
                continue;
            }
            LOG("view_map::NO FOUND BUT OUT SPACES");
            cout << " ";
        }
        cout << endl;
    }
}


void Console2D::game()
{

    this->start();
    while (1)
    {
        this->update();
        gotoxy(0, 0);
    }
    LOG("Console2D::game:start");
}

void Console2D::clearall()
{
    //Map
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (Map[i][j] == -1)
            {
                continue;
            }
            Map[i][j] = 0;
        }
    }
    //blockMap
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            blockMap[i][j] = 0;
        }
    }
    count = 1;
    //block
    for (int i = 0; i < 100 * 100; i++)
    {
        block[i] = "\0";
    }
    worldcount++;
    LOG("clearall:ok");
}
void Console2D::outputFlashingstring(int x1, int y1, string str1)
{
    LOG("outputFlashingstring:" + str1);
    for (int i = 0; i < 5; i++)
    {
        gotoxy(x1, y1);
        cout << str1;
        Sleep(500);
        gotoxy(x1, y1);
        for (int j = 0; j < str1.length(); j++)
        {
            cout << " ";
        }
        Sleep(500);
    }
}
//显示消息
void Console2D::messageBlock(string title, string message)
{
    LOG("messageBlock::title:" + title + " message:" + message);
    if (nextmes[0] == -1)
    {
        nextmes[0] = title.length();
        nextmes[1] = message.length();
        int BY = 3;
        gotoxy(height + 10, BY);
        for (int i = 0; i < title.length(); i++)
        {

            cout << title[i];
        }
        gotoxy(height + 10, BY + 1);
        for (int i = 0; i < message.length(); i++)
        {

            cout << message[i];
        }
        return;
    }
    int BY = 3;
    gotoxy(height + 10, 3);
    for (int i = 0; i < nextmes[0]; i++)
    {
        cout << " ";
    }
    gotoxy(height + 10, BY + 1);
    for (int i = 0; i < nextmes[1]; i++)
    {

        cout << " ";
    }
    BY = 3;
    gotoxy(height + 10, BY);
    for (int i = 0; i < title.length(); i++)
    {

        cout << title[i];
    }
    gotoxy(height + 10, BY + 1);
    for (int i = 0; i < message.length(); i++)
    {

        cout << message[i];
    }
    nextmes[0] = title.length();
    nextmes[1] = message.length();
}
void Console2D::DisablebodyCollisionDetectionXY(int x, int y)
{
    this->Map[x][y] = 0;
    LOG("DisablebodyCollisionDetectionXY:DisablebodyCollisionDetectionXY RUN OK");
}
void Console2D::HideBlock(int count)
{
    int x = -1, y = -1;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (blockMap[i][j] == count)
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    if (x == -1 || y == -1)
    {
        LOG("HideBlock:found error");
        return;
    }
    LOG("HideBlock:Hide OK x=" + to_string(x) + " y=" + to_string(y));
    this->blockMap[x][y] = 0;
    this->block[count] = "\0";
}
int Console2D::SetBlockXy(int count, int x, int y)
{
    //查找原来方块的位置
    bool FindOK = false;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (blockMap[i][j] == count)
            {
                blockMap[i][j] = 0;
                FindOK = true;
                break;
            }
        }
    }
    if (!FindOK)
    {
        LOG("SetBlockXy:Not Find");
        return -1;
    }
    LOG("SetBlockXy:Find and set OK");
    this->blockMap[x][y] = count;
}
void Console2D::C2D_Create_Block(C2D_Block* block)
{
    block->count = count;
    LOG("C2D_Create_Block:" + to_string(count) + " " + to_string(block->Block_x) + " " + to_string(block->Block_y));
    this->CreateBlock(block->Block_x, block->Block_y, block->Block_str);
}
bool Console2D::DetermineCmpiBox(int count)
{
    int x = -1, y = -1;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (blockMap[i][j] == count)
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    if (x == -1 || y == -1)
    {
        LOG("Console2D::DetermineCmpiBox:NO FOUND BLOCK");
        return false;
    }
    LOG("Console2D::DetermineCmpiBox:FOUND X=" + to_string(x) + " Y=" + to_string(y));
    if (this->x == x && this->y == y - 1)
    {
        LOG("DetermineCmpiBox:true");
        return true;
    }
    if (this->x == x && this->y == y + 1)
    {
        LOG("DetermineCmpiBox:true");
        return true;
    }
    if (this->y == y && this->x == x - 1)
    {
        LOG("DetermineCmpiBox:true");
        return true;
    }
    if (this->y == y && this->x == x + 1)
    {
        LOG("DetermineCmpiBox:true");
        return true;
    }
    LOG("DetermineCmpiBox:false");
    return false;
}
string Console2D::get_block_XY(int x, int y)
{
    if (blockMap[x][y] == 0)
    {
        return "\0";
    }
    return block[blockMap[x][y]];
}
int Console2D::get_Block_count(int x, int y)
{
    /*
            此函数是为了获取某个位置的方块的编号
            也是为了不小心使用了CreateBlock函数的朋友准备的

    */
    if (blockMap[x][y] == 0)
    {
        return -1;
    }
    return blockMap[x][y];
}
void Console2D::DisableBlockBodyCollisionDetectionXY(int count)
{
    int x = -1, y = -1;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (blockMap[i][j] == count)
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    if (x == -1 || y == -1)
    {
        LOG("Console2D::DisableBlockBodyCollisionDetectionXY:No This Block : count=" + to_string(count));
   
        return;
    }
    this->DisablebodyCollisionDetectionXY(x, y);
}
void Console2D::BlockBodyCollisionDetection(int count)
{
    int x = -1, y = -1;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (blockMap[i][j] == count)
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    if (x == -1 || y == -1)
    {
        LOG("Console2D::BlockBodyCollisionDetectionXY:No This Block : count=" + to_string(count));

        return;
    }
    this->BodyCollisionDetection(x, y);
}
void Console2D_Exit::Over()
{
    exit(0);
}