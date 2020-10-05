#include "Sort.h"
#include <bits/stdc++.h>

void ds_alg::insertionSort(int *array, int n){
    for(int j = 1; j < n; j++){
        int key = array[j];
        int i = j - 1;
        while((i > -1) && (array[i] > key)){
            array[i+1] = array[i];
            i--;
        }
        array[i+1] = key;
     }
}

void ds_alg::selectionSort(int *array, int n){
   for(int i = 0; i < n-1; i++){
        int key = INT_MAX;
        int index_key = 0;
        for(int j = i; j < n; j++){
            if(array[j] < key){
                key = array[j];
                index_key = j;
            }
        }
        array[index_key] = array[i];
        array[i] = key;
   }
}
