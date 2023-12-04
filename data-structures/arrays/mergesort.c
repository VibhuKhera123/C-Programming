#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int mid, int fi, int li)
{
    int i, j, k;
    int *b;
    b=(int *)calloc(li,sizeof(int));
    i = fi;
    j = mid + 1;
    k = fi;
    while (i <= mid && j <= li)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;         
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if(j > li){
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    else{
        while (j <= li)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    for (int i = fi; i <= li; i++)
    {
        a[i] = b[i];
    }
}

void mergesort(int arr[], int fi, int li)
{
    int mid;
    if (fi < li)
    {
        mid = (fi + li) / 2;
        mergesort(arr, fi, mid);
        mergesort(arr, mid + 1, li);
        merge(arr, mid,fi,li);
    }
}
int main()
{
    int n,i;
    int *a;
    printf("Enter the nunmber of elements in the array:");
    scanf("%d",&n);
    a=(int *)calloc(n,sizeof(int)); 
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("unsorted Array:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t ", a[i]);
    }
    printf("\n\n");
    mergesort(a, 0, (n-1));
    printf("Sorted Array:\t");
    for (i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}