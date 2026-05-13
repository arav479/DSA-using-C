#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void display(struct node **head) {
    if(*head==NULL) {
        printf("queue is empty\n");
    }
    else {
        printf("queue is:\n");
        struct node *temp=*head;
        while(temp!=NULL) {
            printf("%d\t",temp->data);
            temp=temp->next;
                    }
    }
}
void enqueue(struct node **tail){
    struct node *node;
    node=(struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&node->data);
    node->next=NULL;
    *tail=node;
    }
void dequeue(struct node **head){
    if(*head==NULL){
        printf("the queue is empty\n");
        return;
    }
    struct node *temp=*head;
    *head=temp->next;
    *head=temp;
}
void is_empty(struct node **head) {
    if(*head==NULL) {
        printf("queue is empty\n");
    }
}
int front(struct node **head) {

    if(*head==NULL) {
        printf("queue is empty\n");
    }
    *head=(*head)->next;
    return (*head)->data;
}
int main() {
    int n;
    struct node *head = NULL;
    struct node *tail = NULL;
    printf("enter number of elements in the queue initially:");
    scanf("%d",&n);
    struct node *node = (struct node *)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&node->data);
    node->next=NULL;
    head=node;
    tail=node;
    for(int i=1;i<n;i++){
        node=(struct node *)malloc(sizeof(struct node));
        printf("enter data:");
        scanf("%d",&node->data);
        node->next=NULL;
        tail->next=node;
        tail=node;
    }
    int choice;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display\n");
        printf("5. Is Empty\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(&head); break;
            case 2: dequeue(&head); break;
            case 3: front(&head); break;
            case 4: is_empty(&head); break;
            case 5: display(&head); break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
