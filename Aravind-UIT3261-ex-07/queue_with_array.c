#include <stdio.h>
#define MAX 10
void enqueue(int array[], int *rear, int *front) {
    int x;
    printf("Enter element to insert: ");
    scanf("%d", &x);

    if (*rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }

    if (*front == -1) {
        *front = 0;
    }

    (*rear)++;
    array[*rear] = x;
}

void dequeue(int array[], int *rear, int *front) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", array[*front]);
    (*front)++;
    if (*front > *rear) {
        *front = -1;
        *rear = -1;
    }
}

void display(int array[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("\nQueue (front → rear):\n");

    for (int i = front; i <= rear; i++) {
        printf("| %d |", array[i]);
    }
    printf("\n");
}
void Front(int array[], int *front,int *rear) {
    if (*front == -1) {
        printf("Queue is empty\n");
    }
    printf("%d\n", array[*front]);
}
int isEmpty(int front, int rear) {
    return (front == -1 || front > rear);
}

void Rear(int array[], int *rear,int *front) {
    printf("%d",array[*rear]);

}
int main() {
    int array[MAX];
    int front = -1, rear = -1;
    int choice;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Front\n5.Rear\n6.IsEmpty\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(array, &rear, &front);
                break;

            case 2:
                dequeue(array, &rear, &front);
                break;

            case 3:
                display(array, front, rear);
                break;

            case 4:
                Front(array, &front, &rear);
                break;

            case 5:
                Rear(array, &rear, &front);
                break;

            case 6:
                if (isEmpty(front, rear))
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

}