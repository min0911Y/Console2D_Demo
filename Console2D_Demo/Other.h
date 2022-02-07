#include "ALLHEADER.h"
#include "CONSOLE2D.h"
#ifndef Other_h
#define Other_h
namespace Other
{
    bool __rand__(int x);
    Console2D::C2D_Block random_Create_Block(string str, Console2D console);
    void Srand();
    void HideCursor();
    namespace ALG
    {
        namespace Search
        {
            int binarySearch(int arr[], int start, int end, int key);
        };
        namespace Sort
        {
            void quicksort(int arr[], int begin, int end);
            void QSort(int a[], int size);
        };
    };

};

#endif