#ifndef CLRS_CPP_MATRIX_H
#define CLRS_CPP_MATRIX_H

#include <cstdlib>

template<typename T>
void MatrixMultiply(T& a, T& b, T& result, std::size_t size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                result[i][j] = result[i][j] + a[i][k] * b[k][j];
            }
        }
    }
}

template<typename T>
void MatrixMultplyRecursive(T& a, T& b, T& result, std::size_t size){
    if(size == 1){
        result[0][0] = result[0][0] + a[0][0] * b[0][0];
        return;
    }
    /* divide Matrix by quater */
    /* page 83 */
}

#endif //CLRS_CPP_MATRIX_H
