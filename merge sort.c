#include <stdio.h>
void merge(int arr[],int lb,int mid,int ub) {
    int i=lb;
    int j=mid+1;
    int k=lb;
    int temp[100];
    while (i<=mid && j<=ub) {
        if (arr[i]<arr[j]) {
            temp[k]=arr[i];
            i++;
        }
        else {
            temp[k]=arr[j];
            j++;

        }
        k++;
    }
    if (i>mid) {
        while (j<=ub) {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    else {
        while (i<=mid) {
            temp[k]=arr[i];
            k++;
            i++;
        }
    }
    for(i = lb; i <= ub; i++) {
        arr[i] = temp[i];
    }

}

void mergesort(int arr[],int lb,int ub) {
    if (lb<ub) {
        int mid=(lb+ub)/2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}



int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, size - 1);
    printf("Sorted array:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}