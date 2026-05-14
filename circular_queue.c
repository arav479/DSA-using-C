#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (front == NULL) {
        front = rear = newnode;
        newnode->next = front;
    } else {
        newnode->next = front;
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    printf("Deleted: %d\n", temp->data);
    free(temp);
}


void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;

    do {
        printf("|%d| ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}
void Front() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}
int isEmpty() {
    if (front == NULL)
        return 1;
    return 0;
}

int isFull() {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
        return 1;
    free(temp);
    return 0;
}
int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Is Empty\n");
        printf("6. Is Full\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: Front(); break;
            case 5: printf("%d\n", isEmpty()); break;
            case 6: printf("%d\n", isFull()); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}