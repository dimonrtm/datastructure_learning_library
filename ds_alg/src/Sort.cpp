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

void ds_alg::merge(int *array, int begin, int middle, int end){
   int sizeArray1 = middle - begin + 1;
   int sizeArray2 = end - middle;
   int *left = new int[sizeArray1 + 1];
   int *right = new int[sizeArray2 + 1];
   for(int i = 0; i < sizeArray1; i++){
    left[i] = array[begin + i];
   }
   for(int j = 0; j < sizeArray2; j++){
    right[j] = array[middle + j + 1];
   }
   left[sizeArray1] = INT_MAX;
   right[sizeArray2] = INT_MAX;
   int i = 0;
   int j = 0;
   for(int k = begin; k <= end; k ++){
       if(left[i] <= right[j]){
           array[k] = left[i];
           i++;
       } else{
           array[k] = right[j];
           j++;
       }
   }
}

void ds_alg::mergeWithoutSignals(int *array, int begin, int middle, int end){
    int sizeArray1 = middle - begin + 1;
    int sizeArray2 = end - middle;
    int *left = new int[sizeArray1];
    int *right = new int[sizeArray2];
    for(int i = 0; i < sizeArray1; i++){
       left[i] = array[begin + i];
   }
   for(int j = 0; j < sizeArray2; j++){
       right[j] = array[middle + j + 1];
   }
   int i = 0;
   int j = 0;
   int k = begin;
   while((i < sizeArray1) && (j < sizeArray2)){
        if(left[i] <= right[j]){
           array[k] = left[i];
           i++;
           k++;
       } else{
           array[k] = right[j];
           j++;
           k++;
       }
   }
   if(i < sizeArray1){
      while(i < sizeArray1){
         array[k] = left[i];
         i++;
         k++;
      }
   } else{
      while(j < sizeArray2){
        array[k] = right[j];
        j++;
        k++;
      }
   }
}

void ds_alg::mergeSort(int *array, int begin, int end){
   if(begin < end){
       int middle = (begin + end) / 2;
       ds_alg::mergeSort(array, begin, middle);
       ds_alg::mergeSort(array, middle + 1, end);
       ds_alg::merge(array, begin, middle, end);
   }
}

void ds_alg::mergeSortWithoutSignals(int *array, int begin, int end){
    if(begin < end){
        int middle = (begin + end) / 2;
        ds_alg::mergeSortWithoutSignals(array, begin, middle);
        ds_alg::mergeSortWithoutSignals(array, middle + 1, end);
        ds_alg::mergeWithoutSignals(array, begin, middle, end);
    }
}
