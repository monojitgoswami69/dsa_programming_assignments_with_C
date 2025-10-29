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

**INSERT:**
1. If tree is empty (root == NULL):
   - Create new node
   - Return as root
2. If data < root->data:
   - Recursively insert in left subtree
3. Else if data > root->data:
   - Recursively insert in right subtree
4. Else (data == root->data):
   - Reject duplicate
5. Return root

**INORDER (Left-Root-Right):**
1. If root is NULL: return
2. Traverse left subtree
3. Print root->data
4. Traverse right subtree

**PREORDER (Root-Left-Right):**
1. If root is NULL: return
2. Print root->data
3. Traverse left subtree
4. Traverse right subtree

**POSTORDER (Left-Right-Root):**
1. If root is NULL: return
2. Traverse left subtree
3. Traverse right subtree
4. Print root->data

**SEARCH:**
1. If root is NULL or root->data == key: return root
2. If key < root->data:
   - Search in left subtree
3. Else:
   - Search in right subtree

**FIND SMALLEST:**
1. If root is NULL: return -1
2. While root->left != NULL:
   - Move to left child
3. Return root->data

**FIND LARGEST:**
1. If root is NULL: return -1
2. While root->right != NULL:
   - Move to right child
3. Return root->data

**COUNT NODES:**
1. If root is NULL: return 0
2. Return 1 + countNodes(left) + countNodes(right)

**HEIGHT:**
1. If root is NULL: return 0
2. Get left height
3. Get right height
4. Return 1 + max(left height, right height)

**COUNT LEAF NODES:**
1. If root is NULL: return 0
2. If both left and right are NULL: return 1 (leaf)
3. Return countLeaf(left) + countLeaf(right)

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

void postorder(struct Node* root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
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

int findLargest(struct Node* root){
    if (root == NULL){
        printf("Tree is empty\n");
        return -1;
    }
    while (root->right != NULL) root = root->right;
    return root->data;
}

int countNodes(struct Node* root){
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(struct Node* root){
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int countLeaf(struct Node* root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

void freeTree(struct Node* root){
    if (root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    struct Node* root = NULL;
    int choice, val, key;
    struct Node* result;
    
    while (1){
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Find Smallest\n7. Find Largest\n8. Count Nodes\n9. Height\n10. Count Leaf Nodes\n11. Exit\nChoice: ");
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
                printf("Postorder: ");
                if (root == NULL) printf("Tree is empty");
                else postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter key: ");
                scanf("%d", &key);
                result = search(root, key);
                if (result != NULL) printf("Found %d\n", key);
                else printf("%d not found\n", key);
                break;
            case 6:
                val = findSmallest(root);
                if (val != -1) printf("Smallest: %d\n", val);
                break;
            case 7:
                val = findLargest(root);
                if (val != -1) printf("Largest: %d\n", val);
                break;
            case 8:
                printf("Total nodes: %d\n", countNodes(root));
                break;
            case 9:
                printf("Height: %d\n", height(root));
                break;
            case 10:
                printf("Leaf nodes: %d\n", countLeaf(root));
                break;
            case 11:
                freeTree(root);
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
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 1
Enter value: 50
Inserted 50

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 1
Enter value: 30
Inserted 30

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 1
Enter value: 70
Inserted 70

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 1
Enter value: 20
Inserted 20

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 1
Enter value: 40
Inserted 40

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 1
Enter value: 60
Inserted 60

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 1
Enter value: 80
Inserted 80

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 2
Inorder: 20 30 40 50 60 70 80

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 3
Preorder: 50 30 20 40 70 60 80

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 4
Postorder: 20 40 30 60 80 70 50

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 5
Enter key: 40
Found 40

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 5
Enter key: 100
100 not found

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 6
Smallest: 20

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 7
Largest: 80

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 8
Total nodes: 7

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 9
Height: 3

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 10
Leaf nodes: 4

1. Insert
2. Inorder
3. Preorder
4. Postorder
5. Search
6. Find Smallest
7. Find Largest
8. Count Nodes
9. Height
10. Count Leaf Nodes
11. Exit
Choice: 11
```

**Visual Tree Structure:**

```
After all insertions: 50, 30, 70, 20, 40, 60, 80

         50 (root)
        /  \
      30    70
     / \   / \
    20 40 60 80

Structure:
• Root: 50
• Left subtree of 50: {30, 20, 40}
• Right subtree of 50: {70, 60, 80}
• Internal nodes: 50, 30, 70
• Leaf nodes: 20, 40, 60, 80
• Height: 3 (path: 50→30→20)
• Total nodes: 7
```

**Traversal Outputs Explained:**

```
Inorder (Left-Root-Right): 20 30 40 50 60 70 80
→ SORTED ORDER! This is the key property.

Preorder (Root-Left-Right): 50 30 20 40 70 60 80
→ Root first, then left subtree, then right subtree
→ Useful for copying tree structure

Postorder (Left-Right-Root): 20 40 30 60 80 70 50
→ Children first, then root
→ Useful for deleting tree safely
```

**Step-by-Step Insertion:**

```
Insert 50:
    50

Insert 30 (30 < 50, go left):
    50
   /
  30

Insert 70 (70 > 50, go right):
    50
   /  \
  30   70

Insert 20 (20 < 50, go left; 20 < 30, go left):
    50
   /  \
  30   70
 /
20

Insert 40 (40 < 50, go left; 40 > 30, go right):
    50
   /  \
  30   70
 / \
20 40

Insert 60 (60 > 50, go right; 60 < 70, go left):
    50
   /  \
  30   70
 / \   /
20 40 60

Insert 80 (80 > 50, go right; 80 > 70, go right):
    50
   /  \
  30   70
 / \   / \
20 40 60 80
```

**Search Example (Search for 40):**

```
Step 1: Start at root (50)
        40 < 50, go left

Step 2: At node 30
        40 > 30, go right

Step 3: At node 40
        40 == 40, FOUND!

Comparisons: 3 (O(h) where h=height)
```

**Find Smallest:**
```
Start: 50 → left exists
Go to: 30 → left exists
Go to: 20 → left is NULL
Result: 20 (leftmost node)
```

**Find Largest:**
```
Start: 50 → right exists
Go to: 70 → right exists
Go to: 80 → right is NULL
Result: 80 (rightmost node)
```

**Key Properties:**
1. ✅ Inorder traversal gives sorted output
2. ✅ Search, insert, delete: O(h) time
3. ✅ Minimum is leftmost, maximum is rightmost
4. ✅ All nodes in left subtree < root < all nodes in right subtree
5. ✅ Height determines efficiency (balanced tree is best)

---
