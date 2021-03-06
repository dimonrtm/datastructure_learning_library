#ifndef SORT_H
#define SORT_H
namespace ds_alg{
  void insertionSort(int *array, int n);
  void selectionSort(int *array, int n);
  void mergeSort(int *array, int begin, int end);
  void merge(int *array, int begin, int middle, int end);
  void mergeWithoutSignals(int *array, int begin, int middle, int end);
  void mergeSortWithoutSignals(int *array, int begin, int end);
  void bubbleSort(int *array, int n);
  long long inversionCount(int *array, int begin, int end);
  long long inversionMerge(int *array, int begin, int middle, int end);
}
#endif // SORT_H
