#include <stdio.h>

int main() {

    int arr[] = {2,76,4,3,6,90,56,32,12,5};

    int size = sizeof(arr)/sizeof(arr[0]);

    int i, j, min, temp;

    for(i = 0; i < size - 1; i++) {

        min = i;

        for(j = i + 1; j < size; j++) {

            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}