#include "Search.h"

int ds_alg::linearSearch(int *array, int size, int key){
   for(int i = 0; i < size; i++){
      if(array[i] == key){
        return i;
      }
   }
   return -1;
}
