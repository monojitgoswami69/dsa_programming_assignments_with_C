<h1 align="center">ASSIGNMENT - 11: Binary Search Tree Operations</h1>

---

### Problem Statement
Write a menu driven program in C to perform the following operations on Binary Search Tree:
- (a) Insert a node
- (b) Inorder traversal
- (c) Preorder traversal
- (d) Search a given key
- (e) Find the smallest element
- (f) Count the total number of nodes


### Algorithm

1. START
2. Define `struct Node` with:
    - `int data`
    - `struct Node *left`
    - `struct Node *right`
3. Initialize `root = NULL`
4. Display menu with options:
    - **Insert**
    - **Inorder**
    - **Preorder**
    - **Search**
    - **Find Smallest**
    - **Count Nodes**
    - **Exit**
5. For **Insert**:
    - Input `value`
    - If `root == NULL`, create new node and set as `root`
    - Else, traverse tree:
      - If `value < node->data`, go left
      - If `value > node->data`, go right
      - If `value == node->data`, do not insert (no duplicates)
      - Repeat until correct position found, insert node
6. For **Inorder**:
    - Recursively traverse `left` subtree
    - Print `node->data`
    - Recursively traverse `right` subtree
7. For **Preorder**:
    - Print `node->data`
    - Recursively traverse `left` subtree
    - Recursively traverse `right` subtree
8. For **Search**:
    - Input `key`
    - Traverse tree:
      - If `key == node->data`, found
      - If `key < node->data`, go left
      - If `key > node->data`, go right
      - If `node == NULL`, not found
9. For **Find Smallest**:
    - Start at `root`, go left until `left == NULL`
    - Print `node->data`
10. For **Count Nodes**:
     - Recursively count `left` and `right` subtrees, add `1` for current node
11. STOP

### Source Code

```c
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
```


### Sample Output

```
1. Insert
2. Inorder
3. Preorder
4. Search
5. Find Smallest
6. Count Nodes
7. Exit
Choice: 1
Enter value: 50
Inserted 50

Choice: 1
Enter value: 30
Inserted 30

Choice: 1
Enter value: 70
Inserted 70

Choice: 1
Enter value: 20
Inserted 20

Choice: 1
Enter value: 40
Inserted 40

Choice: 1
Enter value: 60
Inserted 60

Choice: 1
Enter value: 80
Inserted 80

Choice: 2
Inorder: 20 30 40 50 60 70 80

Choice: 3
Preorder: 50 30 20 40 70 60 80

Choice: 4
Enter key: 40
Found 40

Choice: 4
Enter key: 100
100 not found

Choice: 5
Smallest: 20

Choice: 6
Total nodes: 7

Choice: 7
```

