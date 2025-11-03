/*
ASSIGNMENT 11:
Problem Statement: Write a menu driven program in C to perform the following operations on Binary Search Tree.
(a) insert a node.
(b) inorder traversal.
(c) preorder traversal.
(d) search a given key.
(e) Find the smallest element.
(f) Count the total number of nodes.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data){
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    else printf("Duplicate value %d not inserted\n", data);
    return root;
}

void inorder(struct Node* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root){
    if (root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct Node* search(struct Node* root, int key){
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int findSmallest(struct Node* root){
    if (root == NULL){
        printf("Tree is empty\n");
        return -1;
    }
    while (root->left != NULL) root = root->left;
    return root->data;
}

int countNodes(struct Node* root){
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){
    struct Node* root = NULL;
    int choice, val, key;
    struct Node* result;
    
    while (1){
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Search\n5. Find Smallest\n6. Count Nodes\n7. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("Inserted %d\n", val);
                break;
            case 2:
                printf("Inorder: ");
                if (root == NULL) printf("Tree is empty");
                else inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                if (root == NULL) printf("Tree is empty");
                else preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter key: ");
                scanf("%d", &key);
                result = search(root, key);
                if (result != NULL) printf("Found %d\n", key);
                else printf("%d not found\n", key);
                break;
            case 5:
                val = findSmallest(root);
                if (val != -1) printf("Smallest: %d\n", val);
                break;
            case 6:
                printf("Total nodes: %d\n", countNodes(root));
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
