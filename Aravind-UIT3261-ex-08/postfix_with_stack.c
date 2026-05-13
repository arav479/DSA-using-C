#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void pop(struct node **head) {
    struct node *temp = *head;
    if(*head==NULL) {
        printf("Stack is empty");
        return;
    }
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("now the stack become empty");
    }
    struct node *freepanra=*head;
    temp=temp->next;
    *head=temp;
    free(freepanra);
}
int peek(struct node **head) {
    if(*head==NULL) {
        printf("Stack is empty");
        return;
    }
    struct node *temp=*head;
    return temp->data;
}
void isEmpty(struct node **head) {
    if(*head==NULL) {
        printf("Stack is empty");
        return;
    }
}

void push(struct node **head, int new_data) {

    if (*head==NULL) {
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=new_data;
        *head=newnode;
        newnode->next=NULL;
        return;
    }

    struct node *temp=*head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = new_data;
    newnode->next=temp;
    *head=newnode;
}
void display(struct node **head){
    struct node *temp=*head;
    printf("\n\n");
    while(temp!= NULL){
        printf("| %d |\n",temp->data);
        printf("------\n");
        temp=temp->next;
    }
}

int main() {
    struct node *head = NULL;
    struct node *temp = head;
    struct node *node = NULL;
    int n;
    printf("enter number of elements present in stack initially:");
    scanf("%d", &n);

    node=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d", &node->data);
    head=node;
    node->next = NULL;
    temp=node;
    for(int i=1;i<n;i++){
        node=(struct node*)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d",&node->data);
        head=node;
        node->next=temp;
        temp=node;

    }
    int choice;
    int newdata;
    while (1) {
        printf("\n\n--- STACK MENU ---");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("enter data:");
                scanf("%d", &newdata);
                push(&head,newdata);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                display(&head);
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid choice! Please try again.");
        }

    }
}