#ifndef CLRS_CPP_MERGE_H
#define CLRS_CPP_MERGE_H

template<typename T>
void Merge(T* array, const unsigned int p, const unsigned int q, const unsigned int r){
    unsigned int length_left = q - p + 1;
    unsigned int length_right = r - q;
    T left[length_left], right[length_right];
    int i,j;
    for(i = 0; i < length_left; i++){
        left[i] = array[p + i];
    }
    for(j = 0; j < length_right; j++){
        right[j] = array[q + 1 + j];
    }
    i = j = 0;
    int k = p;
    while(i < length_left && j < length_right){
        if(left[i] <= right[j]){
            array[k] = left[i++];
        }
        else{
            array[k] = right[j++];
        }
        k++;
    }
    while(i < length_left){
        array[k++] = left[i++];
    }
    while(j < length_right){
        array[k++] = right[j++];
    }
}

#endif //CLRS_CPP_MERGE_H
