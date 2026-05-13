#include <stdio.h>

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int i, j, key;

    for(i = 1; i < size; i++) {
        key = arr[i];
        for (j = i-1; j >=0 && key<arr[j]; j--) {
            if (arr[i]<arr[j]) {
                arr[j+1]=arr[j];
            }
        }
        arr[j+1]=key;

    }
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}