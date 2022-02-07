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
    //���ֲ���
    /*
        * arr:����
        * start:��ʼ�±�
        * end:�����±�
        * key:Ҫ���ҵ�Ԫ��
        * return:����Ԫ�ص��±�
        * ע�⣺���ݱ����������
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
    int mid = arr[begin]; //��׼��
    int i = begin;
    int j = end;
    while (i != j) {

        while (arr[j] >= mid && j > i) {
            j--;//������
        }
        while (arr[i] <= mid && j > i) {
            i++;//������
        }
        //���н��� 
        int bmp;
        bmp = arr[i];
        arr[i] = arr[j];
        arr[j] = bmp;
    }
    //����
    arr[begin] = arr[i];
    arr[i] = mid;
    quicksort(arr, begin, i - 1);//��һ�� 
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