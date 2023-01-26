#include <iostream>

#include "include/Sort.h"

int main() {
    int *a = new int[5];
    a[0] = -2, a[1] = 3, a[2] = -6, a[3] = 0, a[4] = -2;
//    int a[5] = {-1,2,-3,4,-5};

    QuickSort(a, 0, 4);

    for(int i = 0; i < 5; i++){
        std::cout << a[i] << std::endl;
    }
    return 0;
}
