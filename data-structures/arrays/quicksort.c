#include <stdio.h>


int partition(int array[], int firstindex, int lastindex) {
  int temp;
  int p = array[lastindex];
  int i = (firstindex - 1);
  for (int j = firstindex; j < lastindex; j++) {
    if (array[j] <= p) {
      i++;
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  temp = array[i+1];
  array[i+1]  = array[lastindex];
  array[lastindex] = temp;
  return (i + 1);
}

void quickSort(int array[], int fi, int li) {
  if (fi < li) {
    int pi = partition(array, fi, li);
    quickSort(array, fi, pi - 1);
    quickSort(array, pi + 1, li);
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int a[100];
  int n,i;
  printf("Enter the number of elements of array: ");
  scanf("%d",&n);
  printf("Enter the elements of array: ");
  for (i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("Unsorted Array\n");
  printArray(a, n);
  quickSort(a, 0, n - 1);
  printf("Sorted array: \n");
  printArray(a, n);
  return 0;
}