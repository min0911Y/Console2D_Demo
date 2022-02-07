#ifndef CONSOL2D_H
#define CONSOL2D_H
#include "ALLHEADER.h"

class Console2D
{
public:
    int initWorld(int width, int height);
    void initsprite(string str);
    void initspritexy(int sx, int sy);
    void Move(int x1);
    void gotoxy(int x, int y);
    void CreateBlock(int x, int y, string str);
    void BodyCollisionDetection(int x, int y);
    void BlockBodyCollisionDetection(int count);
    void view_map();
    void start();
    void update();
    void game();
    void clearall();
    void messageBlock(string title, string message);
    void DisablebodyCollisionDetectionXY(int x, int y);
    void DisableBlockBodyCollisionDetectionXY(int count);
    int SetBlockXy(int count, int x, int y);
    void HideBlock(int count);
    bool DetermineCmpiBox(int count);
    string get_block_XY(int x, int y);
    int get_Block_count(int x, int y);
    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }
    int get_width()
    {
        return width;
    }
    int get_height()
    {
        return height;
    }
    int get_worldcount()
    {
        return worldcount;
    }
    void outputFlashingstring(int x1, int y1, string str1);
    bool PlayerChedaceRtainPOS(int x, int y)
    {
        if (this->x == x && this->y == y)
        {
            return true;
        }
        return false;
    }
    void set_sprite_x_y(int x, int y)
    {
        Map[this->x][this->y] = 0;
        this->x = x;
        this->y = y;
        Map[this->x][this->y] = -1;
    }
    void set_sprite(string str)
    {
        this->sprite = str;
    }
    struct C2D_Block
    {
        int Block_x;
        int Block_y;
        string Block_str;
        int count;
    };
    void C2D_Create_Block(C2D_Block* block);
    //构造函数
    Console2D()
    {
        fstream log;
        log.open("log.txt", ios::out | ios::trunc);
        log << "Console2D engin log file\nthe engin version:1.1.0.0" << endl;
        log.close();
        fp1 = fopen("log.txt", "a+");
    }
    //析构函数
    ~Console2D()
    {
        string str = "Exit.";
        time_t now = time(0);
        //fstream log2;
        //log2.open("lastlog.txt", ios::out | ios::trunc);
        // 把 now 转换为字符串形式
        char* dt = ctime(&now);
        string dt1 = dt;
        dt1[dt1.length() - 1] = ' ';
        string log = "[" + dt1 + "INFO /]" + str + "\n";
        string log1 = "[" + dt1 + "INFO /]" + str + "\n";
        fputs(log.c_str(), fp1);
        fclose(fp1);
        //log2 << log1;
    }
    void Thread();

private:
    int width;
    int height;
    int x;
    int y;
    int sx;
    int sy;
    int Map[1000][1000];
    int count = 1;
    string sprite;
    int worldcount = 0; //图层数量
    string block[1000 * 1000];
    int blockMap[1000][1000];
    int nextmes[2];
    FILE* fp1 = NULL;
    void LOG(string str)
    {
        time_t now = time(0);
        //fstream log2;
        //log2.open("lastlog.txt", ios::out | ios::trunc);
        // 把 now 转换为字符串形式
        char* dt = ctime(&now);
        string dt1 = dt;
        dt1[dt1.length() - 1] = ' ';
        string log = "[" + dt1 + "INFO /]" + str + "\n";
        string log1 = "[" + dt1 + "INFO /]" + str + "\n";
        fputs(log.c_str(), fp1);
        //log2 << log1;
    }
};
namespace Console2D_Exit {
    void Over();
};
enum direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

#endif
