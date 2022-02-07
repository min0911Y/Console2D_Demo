#include "Other.h"
bool Other::__rand__(int x)
{
    srand((unsigned)time(NULL));
    int a = rand() % x;
    if (a == 0)
        return true;
    else
        return false;
}
Console2D::C2D_Block Other::random_Create_Block(string str, Console2D console)
{
re:
    srand((unsigned)time(NULL));
    Console2D::C2D_Block block;
    block.Block_str = str;
    block.Block_x = rand() % console.get_width();
    block.Block_y = rand() % console.get_height();
    if (console.get_block_XY(block.Block_x, block.Block_y) != "\0")
    {
        goto re;
    }
    return block;
}
int Other::ALG::Search::binarySearch(int arr[], int start, int end, int key)
{
    //二分查找
    /*
        * arr:数组
        * start:开始下标
        * end:结束下标
        * key:要查找的元素
        * return:返回元素的下标
        * 注意：数据必须是有序的
    */
    int max_num = end;
    int min_num = start;
    int mid;
    while (min_num <= max_num)
    {
        mid = (min_num + max_num) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            max_num = mid - 1;
        else
            min_num = mid + 1;
    }
}
void Other::ALG::Sort::quicksort(int arr[], int begin, int end) {
    if (begin > end) {
        return;
    }
    int mid = arr[begin]; //基准数
    int i = begin;
    int j = end;
    while (i != j) {

        while (arr[j] >= mid && j > i) {
            j--;//向左走
        }
        while (arr[i] <= mid && j > i) {
            i++;//向右走
        }
        //进行交换 
        int bmp;
        bmp = arr[i];
        arr[i] = arr[j];
        arr[j] = bmp;
    }
    //交换
    arr[begin] = arr[i];
    arr[i] = mid;
    quicksort(arr, begin, i - 1);//下一步 
    quicksort(arr, i + 1, end);
}
void Other::ALG::Sort::QSort(int a[], int size) {
    Other::ALG::Sort::quicksort(a, 0, size / 4 - 1);
}
void Other::Srand() {
    srand((unsigned)time(NULL));
}
void Other::HideCursor()
{
    CONSOLE_CURSOR_INFO cinfo = { 1,0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cinfo);
}