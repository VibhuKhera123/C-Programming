#include <stdio.h>

int main(){
    int n=5,a[n],b[n];
    int key,i,j;
    for (i=0;i<5;i++){
        printf("Enter the element to be inserted:");
        scanf("%d",&b[i]);
    }
    printf("unsorted array:\t");
    for (i=0;i<5;i++){
        printf("%d ",b[i]);
    }
    for(i=0;i<n;i++){
        key = b[i];
        j=i-1;
        while(key < a[j] && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("\nSorted array:\t");
    for (j=0;j<n;j++){
        printf("%d ",a[j]);
    }
    return 0;
}
