# Binary Search Tree - Complete Guide

## Table of Contents
- [Introduction to Trees](#introduction-to-trees)
- [Binary Search Tree Concept](#binary-search-tree-concept)
- [BST Operations](#bst-operations)
- [Tree Traversals](#tree-traversals)
- [Complexity Analysis](#complexity-analysis)
- [Applications](#applications)
- [Best Practices](#best-practices)

## Introduction to Trees

A **Tree** is a hierarchical data structure with nodes connected by edges. Unlike linear structures (arrays, lists), trees have a parent-child relationship.

### Tree Terminology

| Term | Definition | Example |
|------|------------|---------|
| **Root** | Top node with no parent | Node 50 in BST |
| **Parent** | Node with children | Node 30 parent of 20,40 |
| **Child** | Node below parent | Node 20 child of 30 |
| **Leaf** | Node with no children | Nodes 20, 40, 60, 80 |
| **Internal Node** | Node with children | Nodes 50, 30, 70 |
| **Height** | Longest path from node to leaf | Height of tree |
| **Depth** | Distance from root to node | Depth of node |
| **Subtree** | Tree formed by node and descendants | Left/right subtree |

### Tree Visualization

```
         50 (root)
        /  \
      30    70
     / \   / \
    20 40 60 80 (leaves)

Height: 2
Nodes: 7
Leaves: 4
```

## Binary Search Tree Concept

A **Binary Search Tree (BST)** is a binary tree with a special property:
- **Left subtree** contains only nodes with values **less than** parent
- **Right subtree** contains only nodes with values **greater than** parent
- Both left and right subtrees are also BSTs

### BST Property

```
For any node N:
• All values in left subtree < N.data
• All values in right subtree > N.data
```

### Example BST

```
         50
        /  \
      30    70
     / \   / \
    20 40 60 80

Valid BST:
• 20 < 30 < 40 (left subtree of 50)
• 60 < 70 < 80 (right subtree of 50)
• 20,30,40 < 50 < 60,70,80 (overall)
```

### NOT a BST

```
         50
        /  \
      30    70
     / \   / \
    20 60 40 80
       ↑  ↑
     WRONG! 60 > 30 but in left subtree
            40 < 70 but in right subtree
```

## BST Operations

### Node Structure

```c
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
```

### 1. Insert Operation

**Algorithm:**
1. Start at root
2. Compare value with current node
3. If value < node: go left
4. If value > node: go right
5. If value == node: duplicate (usually reject)
6. When NULL reached: insert new node

```c
struct Node* insert(struct Node* root, int data) {
    // Base case: empty tree or leaf position
    if (root == NULL) 
        return createNode(data);
    
    // Recursive insertion
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        printf("Duplicate\n");  // Optional: reject duplicates
    
    return root;
}
```

**Example:**
```
Insert 25 into:
     50
    /  \
   30   70

Step 1: 25 < 50, go left
Step 2: 25 < 30, go left
Step 3: NULL, insert here

Result:
     50
    /  \
   30   70
  /
 25
```

### 2. Search Operation

```c
struct Node* search(struct Node* root, int key) {
    // Base cases
    if (root == NULL || root->data == key)
        return root;
    
    // Key in left subtree
    if (key < root->data)
        return search(root->left, key);
    
    // Key in right subtree
    return search(root->right, key);
}
```

**Time Complexity:** O(h) where h = height

### 3. Find Minimum

```c
int findSmallest(struct Node* root) {
    if (root == NULL) return -1;
    
    // Keep going left
    while (root->left != NULL)
        root = root->left;
    
    return root->data;
}
```

**Minimum is leftmost node!**

### 4. Find Maximum

```c
int findLargest(struct Node* root) {
    if (root == NULL) return -1;
    
    // Keep going right
    while (root->right != NULL)
        root = root->right;
    
    return root->data;
}
```

**Maximum is rightmost node!**

### 5. Count Nodes

```c
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```

### 6. Tree Height

```c
int height(struct Node* root) {
    if (root == NULL) return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    return 1 + (lh > rh ? lh : rh);
}
```

### 7. Count Leaf Nodes

```c
int countLeaf(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}
```

## Tree Traversals

### 1. Inorder Traversal (Left-Root-Right)

```c
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
```

**Output:** **Sorted order** for BST!

**Example:**
```
Tree:    50
        /  \
       30   70
      / \   / \
     20 40 60 80

Inorder: 20 30 40 50 60 70 80
```

### 2. Preorder Traversal (Root-Left-Right)

```c
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
```

**Output:** **Root first**, useful for copying tree

**Example:**
```
Preorder: 50 30 20 40 70 60 80
```

### 3. Postorder Traversal (Left-Right-Root)

```c
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
```

**Output:** **Root last**, useful for deleting tree

**Example:**
```
Postorder: 20 40 30 60 80 70 50
```

### Traversal Comparison

| Traversal | Order | Use Case |
|-----------|-------|----------|
| **Inorder** | Left-Root-Right | Get sorted data |
| **Preorder** | Root-Left-Right | Copy tree structure |
| **Postorder** | Left-Right-Root | Delete tree, postfix expressions |

## Complexity Analysis

### Time Complexity

| Operation | Average | Worst Case | Best Case |
|-----------|---------|------------|-----------|
| **Search** | O(log n) | O(n) | O(1) |
| **Insert** | O(log n) | O(n) | O(1) |
| **Delete** | O(log n) | O(n) | O(1) |
| **Find Min/Max** | O(log n) | O(n) | O(1) |
| **Traversal** | O(n) | O(n) | O(n) |

**Note:** Worst case O(n) occurs when tree becomes skewed (like linked list)

### Tree Shapes

**Balanced BST:**
```
     50         Height = log₂(n)
    /  \        Operations: O(log n)
   30   70
  / \   / \
 20 40 60 80
```

**Skewed BST (Worst Case):**
```
50              Height = n
 \              Operations: O(n)
  70            Like a linked list!
   \
    80
     \
      90
```

### Space Complexity

- **Storage**: O(n) for n nodes
- **Recursion Stack**: O(h) where h = height
  - Balanced: O(log n)
  - Skewed: O(n)

## Applications

### 1. **Databases and File Systems**
- Index structures
- Directory hierarchies
- B-trees (generalized BST)

### 2. **Symbol Tables**
- Compiler symbol tables
- Variable lookup
- Function name resolution

### 3. **Priority Queues**
- Heap data structure (special tree)
- Task scheduling
- Event management

### 4. **Expression Trees**
- Mathematical expressions
- Parse trees in compilers
- Syntax trees

### 5. **Sorted Data Maintenance**
- Dynamic sorted sets
- Range queries
- Quick min/max access

### 6. **Routing Tables**
- Network routing
- IP address lookup
- Prefix trees (tries)

## Best Practices

### 1. **Balance the Tree**
```c
// For better performance, use self-balancing trees:
// - AVL Tree
// - Red-Black Tree
// - B-Tree
```

### 2. **Handle Duplicates**
```c
// Option 1: Reject
if (data == root->data) return root;

// Option 2: Allow (count field)
if (data == root->data) {
    root->count++;
    return root;
}
```

### 3. **Validate BST Property**
```c
int isBST(struct Node* root, int min, int max) {
    if (root == NULL) return 1;
    if (root->data <= min || root->data >= max) return 0;
    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}
```

### 4. **Free Memory Properly**
```c
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);   // Free left subtree
        freeTree(root->right);  // Free right subtree
        free(root);             // Free current node
    }
}
// Use postorder for safe deletion
```

### 5. **Iterative vs Recursive**
```c
// Recursive: Cleaner code but uses stack
// Iterative: More complex but no stack overflow risk

// Iterative insert (for large trees):
struct Node* insertIterative(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) return newNode;
    
    struct Node* current = root;
    struct Node* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    
    return root;
}
```

---

<div align="center">

**💡 Tip:** BST is efficient only when balanced. For guaranteed O(log n) operations, use self-balancing trees like AVL or Red-Black trees in production code.

</div>
