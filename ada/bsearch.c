#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the terms: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }    
    int x;
    printf("Enter the number to be searched: ");
    scanf("%d", &x);

    int index = binarySearch(arr, 0, n - 1, x);
    if (index == -1) {
        printf("Element Not Found");
    } else {
        printf("Element %d found at index %d.\n", x, index);
    }

    return 0;
}
