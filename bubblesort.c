#include<stdio.h>
int main() {
    int t;
    int arr[]={3,4,8,5,3,2,9,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    for (int i=0;i<size-1;i++) {
        for (int j=0;j<size-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}