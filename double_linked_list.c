#include<stdio.h>
#include<stdlib.h>
struct node *head,*temp,*node;
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
void display(struct node *head) {
    if(head==NULL) {
        printf("list is empty");
    }
    temp=head;
    while (temp!=NULL) {
        printf("|%d|<=>",temp->data);
        temp=temp->next;
    }
}
void insert(struct node *head) {
    if(head==NULL) {
        node=(struct node *)malloc(sizeof(struct node));
        printf("enter element to be inserted-");
        scanf("%d",&node->data);
        head=node;
        node->prev=NULL;
        node->next=NULL;
    }
    temp=head;
    int i=1;
    node=(struct node *)malloc(sizeof(struct node));
    printf("enter element to be inserted-");
    scanf("%d",&node->data);
    int pos;
    printf("enter position where to be inserted-");
    scanf("%d",&pos);
    while (i<pos) {
        temp=temp->next;
        i++;
    }

    node->next=temp->next;
    node->prev=temp;
    temp->next=node;



}
int main() {
    int n;
    printf("enter number of elements in the list initially-");
    scanf("%d",&n);
    node=(struct node *)malloc(sizeof(struct node));
    head=node;
    node->prev=NULL;
    node->next=NULL;
    printf("enter element to be inserted-");
    scanf("%d",&node->data);
    temp=node;
    for (int i=1;i<n;i++) {
        node=(struct node *)malloc(sizeof(struct node));
        printf("enter element to be inserted-");
        scanf("%d",&node->data);
        node->prev=temp;
        node->next=NULL;
        temp->next=node;
        temp=temp->next;
    }
    display(head);
    insert(head);
    display(head);
}