#include<stdio.h>
#include<stdlib.h>
void display(int *array,int *top) {
    int i;
    if (*top == -1) {
        printf("Stack is empty.");
        return;
    }
    printf("\n\n");
    for (i = *top; i >= 0; i--) {

        printf("| %d |\n", array[i]);
        printf("-----\n");
    }
}
void create(int *array,int *top){
    int n,i;
    printf("enter the no of elements in the stack in initial->");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("enter element %d:",i+1);
        scanf("%d",&array[i]);
        (*top)++;
    }
}
void push(int *array,int *top){

    if (*top==sizeof(*array)-1){
        printf("the stack is full!!");
        return;
    }

    printf("enter the element to add in :")	;
    int x;
    scanf("%d",&x);
    array[(*top)+1]=x;
    (*top)++;
}
void pop(int *array,int *top){

    if((*top)==-1){
        printf("stack is empty!!");
        return;
    }
    (*top)--;
}
int main(){
    int array[10];
    int top=-1;
    int choice;

    while (1) {
        printf("\n\n--- STACK MENU ---");
        printf("\n1. Push\n2. Pop\n3. Create\n4. Display\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(array,&top);
                break;
            case 2:
                pop(array,&top);
                break;
            case 3:
                create(array,&top);
                break;
            case 4:
                display(array,&top);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;


}

