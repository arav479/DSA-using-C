#include<stdio.h>
#include<stdlib.h>
struct node {
      int data;
      struct node *next;
};
void add_at_pos(struct node **list_ptr,int pos) {
      struct node *newnode;
      newnode=(struct node *) malloc(sizeof(struct node));
      printf("enter data:");
      scanf("%d",&newnode->data);
      struct node *temp=*list_ptr;
      for(int i=1;i<pos-1;i++) {
            temp=temp->next;
      }
      newnode->next=temp->next;
      temp->next=newnode;
}
void add_at_beginning(struct node **list_ptr) {
      struct node *newnode;
      newnode=(struct node *) malloc(sizeof(struct node));
      printf("enter data:");
      scanf("%d",&newnode->data);
      struct node *temp=*list_ptr;
      newnode->next=temp;
      temp=newnode;
      *list_ptr=newnode;
}
void add_at_end(struct node **list_ptr) {
      struct node *newnode;
      struct node *temp=*list_ptr;
      newnode=(struct node *) malloc(sizeof(struct node));
      printf("enter data:");
      scanf("%d",&newnode->data);

      while( temp->next != NULL) {
            temp=temp->next;
      }
      if (temp->next == NULL) {
            newnode->next=NULL;
            temp->next=newnode;
      }
}
void delete_at_pos(struct node **list_ptr,int pos) {
      struct node *temp=*list_ptr;
      int i=1;
      while (i<pos-1) {
            temp=temp->next;
            i++;
      }
      struct node *delete_next=temp->next->next;
      struct node *freepanra=temp->next;
      temp->next=delete_next;
      free(freepanra);
}
void delete_at_beginning(struct node **list_ptr) {
      struct node *temp=*list_ptr;
      struct node *freepanra=temp;
      temp=temp->next;
      free(freepanra);
      *list_ptr=temp;
}
void delete_at_end(struct node **list_ptr) {
      struct node *temp=*list_ptr;
      if (temp->next == NULL) {
            free(temp);
            *list_ptr = NULL;
            return;
      }
      while (temp->next->next != NULL) {
            temp=temp->next;
      }
      struct node *freepanra=temp->next;
      temp->next=NULL;
      free(freepanra);

}
struct node* search_element(struct node **list_ptr,int element) {
      struct node *temp=*list_ptr;
      int i=0;
      while (1) {
            if (temp->data==element) {
                  printf("index: %d\n",i);
                  return temp;
            }
            temp=temp->next;
            i++;
      }


}
int find_kth_element(struct node **list_ptr,int pos) {
      struct node *temp=*list_ptr;
      int i=1;
      while (i<pos) {
            temp=temp->next;
            i++;
      }
      return temp->data;
}
void check_empty(struct node **list_ptr) {
      if (*list_ptr==NULL) {
            printf("list is empty\n");
      }

}
void display(struct node **list_ptr) {
      struct node *temp=*list_ptr;
      while (temp!=NULL) {
            printf("|%d|",temp->data);
            temp=temp->next;
      }

}
void delete_list(struct node **list_ptr) {
      struct node *temp;
      while ((*list_ptr)!=NULL) {
            temp=(*list_ptr);
            (*list_ptr)=(*list_ptr)->next;
            free(temp);
      }
}
int main() {
      struct node *node;
      struct node *list_ptr,*temp;
      int n;
      printf("enter the number of  nodes to be created-->");
      scanf("%d",&n);

      node=  (struct node *)malloc(sizeof(struct node));
      printf("enter data:");
      scanf("%d",&node->data);
      node->next=NULL;
      list_ptr=node;
      temp=node;

      for(int i=1;i<n;i++) {
            node=(struct node *) malloc(sizeof(struct node));
            printf("enter data:");
            scanf("%d",&node->data);
            node->next=NULL;
            temp->next=node;
            temp=node;


      }
      int choice, pos, key;

      while (1) {
            printf("\n--- MENU ---\n");
            printf("1. Insert at beginning\n");
            printf("2. Insert at end\n");
            printf("3. Insert at position\n");
            printf("4. Delete at beginning\n");
            printf("5. Delete at end\n");
            printf("6. Delete at position\n");
            printf("7. Search\n");
            printf("8. Display\n");
            printf("9. Delete entire list\n");
            printf("0. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                  case 1:
                        add_at_beginning(&list_ptr);
                        break;
                  case 2:
                        add_at_end(&list_ptr);
                        break;
                  case 3:
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        add_at_pos(&list_ptr, pos);
                        break;
                  case 4:
                        delete_at_beginning(&list_ptr);
                        break;
                  case 5:
                        delete_at_end(&list_ptr);
                        break;
                  case 6:
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        delete_at_pos(&list_ptr, pos);
                        break;
                  case 7:
                        printf("Enter element to search: ");
                        scanf("%d", &key);
                        search_element(&list_ptr, key);
                        break;
                  case 8:
                        display(&list_ptr);
                        break;
                  case 9:
                        delete_list(&list_ptr);
                        printf("List deleted\n");
                        break;
                  case 0:
                        return 0;
                  default:
                        printf("Invalid choice\n");
            }
      }
}


