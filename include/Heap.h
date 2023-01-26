#ifndef CLRS_CPP_HEAP_H
#define CLRS_CPP_HEAP_H

unsigned int Parent(const unsigned int idx){
    return idx / 2;
}
unsigned int LeftChild(const unsigned int idx){
    return 2 * idx;
}
unsigned int RightChild(const unsigned int idx){
    return 2 * idx + 1;
}

#include <cstdlib>
#include <utility>

template<typename T>
void MaxHeapify(T* array, const unsigned int idx, std::size_t size){
    unsigned int l = LeftChild(idx);
    unsigned int r = RightChild(idx);
    unsigned int largest;
    if(l < size && array[l] > array[idx])
        largest = l;
    else
        largest = idx;
    if(r < size && array[r] > array[largest])
        largest = r;
    if(largest != idx){
        std::swap(array[idx], array[largest]);
        MaxHeapify(array, largest, size);
    }
}
template<typename T>
void BuildMaxHeap(T* array, std::size_t size){
    for(int i = size / 2; i >= 0; i--){
        MaxHeapify(array, i, size);
    }
}

template<typename T>
void MaxHeapMaximum(T* array, std::size_t size) {
    if (size < 1){
        printf("Error: Heap underflow!\n");
        return;
    }
    return array[0];
}
template<typename T>
void MaxHeapExtractMax(T* array, std::size_t& size){
    T max = MaxHeapMaximum(array, size);
    array[0] = array[size - 1];
    size--;
    MaxHeapify(array, 0);
    return max;
}

template<typename T>
void MaxHeapIncreaseKey(T* array, T x, T k){
    if(k < x){
        printf("Error: New key is smaller than current key!\n");
        return;
    }
    x = k;
    int i, parent;
    while(i > 0 && array[Parent(i)] < array[i]){
        parent = Parent(i);
        std::swap(array[i], array[parent]);
        i = parent;
    }
}
template<typename T>
void MaxHeapInsert(T* array, T x, T inf, std::size_t& size){
    T k = x;
    x = -inf;
    array[size++] = x;
    MaxHeapIncreaseKey(array, x, k);
}


#endif //CLRS_CPP_HEAP_H
