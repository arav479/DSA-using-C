#include<stdio.h>

int partition(int arr[],int lb,int ub) {
    int temp;
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end) {
        while (arr[start]<=pivot) {
            start++;
        }
        while (arr[end]>pivot) {
            end--;
        }
        if (start<end) {
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;
    return end;
}
void quicksort(int arr[],int lb, int ub) {
    if (lb<ub) {
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);
    printf("Sorted array:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;

}