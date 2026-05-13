#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
    };

void inorder(struct node *root) {

    inorder(root->left);
    printf("|%d|",root->data);
    inorder(root->right);
}

void preorder(struct node *root) {
    if(root ==NULL){
        return;
    }
    printf("|%d|",root->data);
    preorder(root->left);
    preorder(root->right);


}
void postorder(struct node *root) {
    if(root ==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("|%d|",root->data);


}
bool search(struct node *root,int target){
    if(root ==NULL){
        return 0;
    }
    if(target==root->data){
        return 1;
    }
    if(target<root->data){
        return search(root->left,target);
    }
    else{
        return search(root->right,target);
    }

}
void display(struct node *root, int space) {
    if (root == NULL) {
        return;
    }

    space += 5; // controls spacing between levels

    // print right subtree first
    display(root->right, space);

    // print current node
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // print left subtree
    display(root->left, space);
}
struct node* Delete(struct node *root,int target){
    struct node *temp=NULL;
    if(root ==NULL){
        return NULL;
    }
    if(target>root->data){
        root->right=Delete(root->right,target);
        return root;
    }
    else if(target<root->data){
        root->left=Delete(root->left,target);
        return root;
    }
    if(root->right==NULL && root->left==NULL){ //nothing exist as child to the deletion node
        free(root);
        return NULL;
    }
    else if(root->right==NULL){ //left alone exist
        temp=root->left;
        free(root);
        return temp;
    }
    else if(root->left==NULL){ //right alone exist
        temp=root->right;
        free(root);
        return temp;
    }
    else {
        //if both left and right node exists
        //find greatest
        struct node *child=root->left;
        struct node *parent=root;

        while( child->right !=NULL){
            parent=child;
            child=child->right;
        }
        if(root !=parent){
            parent->right=child->left;
            child->left=root->left;
            child->right=root->right;
            return child;
        }
        else{
            child->right=root->right;
            free(root);
            return child;
        }
        free(root);
    }

}
struct node* insert(struct node *root,int target){
    if(!root){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        if (!newnode) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        newnode->data=target;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if (target < root->data) {
        root->left = insert(root->left, target);
    } else {
        root->right = insert(root->right, target);
    }
    return root;
}
int main() {
    struct node *root = NULL;
    int choice, value, result;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Display Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(root, value);
                if (result)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = Delete(root, value);
                break;
            case 7:
                display(root,0);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}