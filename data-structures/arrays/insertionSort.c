#include <stdio.h>

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size) {
    int key,i,j;
  for (i = 1; i < size; i++) {
     key = array[i];
     j = i - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void main() {
    int size,i;
    int data[size];
    printf("Enter the number of terms: ");
    scanf("%d",&size);
    printf("Enter the elements: ");
    for ( i = 0; i < size; i++)
    {
        scanf("%d",&data[i]);
    }
    printf("Unsorted array:\n");
    printArray(data,size);
    insertionSort(data, size);
    printf("Sorted array:\n");
    printArray(data, size);
}