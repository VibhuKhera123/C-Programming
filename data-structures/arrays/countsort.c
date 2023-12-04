#include <stdio.h>


void countingSort(int array[], int size) {
  int output[100];
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max){
        max = array[i];
    }
  }
  int count[100];
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}



void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
    int n,i,fi=0,li=n;
  int array[100];
  printf("Enter the size of the array:\t");
  scanf("%d",&n);
  printf("Number of elements in the array:\t%d",n);
  printf("\nEnter the elements of the array:");
  for (i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  printf("\nUnsorted array:\t");
  printArray(array,n);
  countingSort(array, n);
  printf("Sorted array is:");
  printArray(array, n);

  getch();
  return 0;
}
