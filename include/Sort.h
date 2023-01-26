#ifndef CLRS_CPP_SORT_H
#define CLRS_CPP_SORT_H

#include <cstdlib>
#include <utility>

template<typename T>
void InsertionSort(T* array, std::size_t size){
    T key;
    int j;
    for(int i = 1; i < size; i++){
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

#include "Merge.h"
template<typename T>
void MergeSort(T* array, const unsigned int start_idx, const unsigned int end_idx){
    if(start_idx >= end_idx)
        return;
    unsigned int q = (start_idx + end_idx) / 2;
    MergeSort(array, start_idx, q);
    MergeSort(array, q + 1, end_idx);
    Merge(array, start_idx, q, end_idx);
}

template<typename T>
void BubbleSort(T* array, std::size_t size){
    int i, j;
    for(i = 0; i < size; i++){
        for(j = size - 1; j > i; j--){
            if(array[j] < array[j - 1]){
                std::swap(array[j], array[j-1]);
            }
        }
    }
}

#include "Heap.h"
template<typename T>
void HeapSort(T* array, std::size_t size){
    BuildMaxHeap(array, size);
    for(int i = size - 1; i > 0; i--){
        std::swap(array[0], array[i]);
        size--;
        MaxHeapify(array, 0, size);
    }
}


template<typename T>
const unsigned int Partition(T* array, const unsigned int start_idx, const unsigned int end_idx){
    T pivot = array[end_idx];
    int i = start_idx - 1;
    for(int j = start_idx; j < end_idx; j++){
        if(array[j] <= pivot){
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[end_idx]);
    return i + 1;
}
template<typename T>
const unsigned int HoarePartition(T* array, const unsigned int start_idx, const unsigned int end_idx){
    T pivot = array[start_idx];
    int i = start_idx - 1, j = end_idx + 1;
    while(true){
        while(array[--j] > pivot);
        while(array[++i] < pivot);
        if(i < j)
            std::swap(array[i], array[j]);
        else
            return j;
    }
}
template<typename T>
void QuickSort(T* array, const int start_idx, const int end_idx){
    if(start_idx < end_idx){
        const int q = HoarePartition(array, start_idx, end_idx);
        QuickSort(array, start_idx, q); /* When use HoarePartition: q, normal Paritition: q-1 */
        QuickSort(array, q + 1, end_idx);
    }
}
/* Stooge sort, tre-quicksort page 202*/

#endif //CLRS_CPP_SORT_H
