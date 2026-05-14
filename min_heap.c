#include <stdio.h>

int n=5;
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void insert(int arr[]) {
    int value;
    printf("enter the element to insert:");
    scanf("%d", &value);
    arr[n] = value;
    int parent;
    int i=n;
    while (i>0){
        parent=(i-1)/2;
        if(arr[parent]>arr[i]){
            swap(&arr[parent],&arr[i]);
            i=parent;
        }
        else{
            break;
        }
    }
    n++;
}
void delete(int arr[]) {

    if(n == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", arr[0]);
    arr[0] = arr[n - 1];
    n--;
    int parent = 0;

    while(1) {

        int left = 2 * parent + 1;
        int right = 2 * parent + 2;
        int smallest = parent;

        if(left < n && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if(right < n && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if(smallest != parent) {
            swap(&arr[parent], &arr[smallest]);
            parent = smallest;
        }
        else {
            break;
        }
    }
}
void display(int arr[]){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
    int arr[20]={1,4,5,6,10};
    int choice;

    while(1) {
        printf("\n----- MIN HEAP MENU -----\n");

        printf("1. Insert\n");
        printf("2. Delete Min\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insert(arr);
                break;
            case 2:
                delete(arr);
                break;
            case 3:
                display(arr);
                break;
            case 4:
                printf("Exiting Program...\n");
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}