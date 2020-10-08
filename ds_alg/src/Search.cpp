#include "Search.h"

int ds_alg::linearSearch(int *array, int size, int key){
   for(int i = 0; i < size; i++){
      if(array[i] == key){
        return i;
      }
   }
   return -1;
}

int ds_alg::binarySearch(int *array, int size, int key){
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int middle = (low + high) / 2;
        if(key == array[middle]){
            return middle;
        }
        if(key > array[middle]){
            low = middle + 1;
        } else{
            high = middle - 1;
        }
    }
    return -1;
}
