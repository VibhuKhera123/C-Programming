//randomised quicksort in c programming?
#include <stdio.h>
#include <stdlib.h>
int partition(int a[],int lo,int hi){
    int pivot=a[hi];
    int i=lo-1;
    for(int j=lo;j<hi;j++){
        if(a[j]<pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[hi];
    a[hi]=temp;
    return i+1;
}

int randNum(int a[],int lo,int hi){
    srand(time(NULL));
    int random=lo+rand()%(hi-lo);
    int temp=a[random];
    a[random]=a[hi];
    a[hi]=temp;
    return partition(a,lo,hi);
}

int randomquicksort(int a[],int lo,int hi){
    if(lo<hi){
        int p=randNum(a,lo,hi);
        randomquicksort(a,lo,p-1);
        randomquicksort(a,p+1,hi);
    }
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    randomquicksort(a,0,n-1);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}