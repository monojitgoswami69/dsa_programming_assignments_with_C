# Linked List Variants - Complete Guide

## Table of Contents
- [What is a Linked List?](#what-is-a-linked-list)
- [Linked List Fundamentals](#linked-list-fundamentals)
- [Types of Linked Lists](#types-of-linked-lists)
- [Circular Linked List](#circular-linked-list)
- [Doubly Linked List](#doubly-linked-list)
- [Operations and Complexity](#operations-and-complexity)
- [Memory Management](#memory-management)
- [Advantages and Disadvantages](#advantages-and-disadvantages)
- [Applications](#applications)
- [When to Use Different Types](#when-to-use-different-types)
- [Best Practices](#best-practices)

## What is a Linked List?

A **Linked List** is a linear data structure where elements (called nodes) are not stored in contiguous memory locations. Instead, each node contains:
1. **Data**: The actual value stored
2. **Pointer(s)**: Reference(s) to the next (and possibly previous) node

Unlike arrays, linked lists provide dynamic memory allocation and efficient insertion/deletion operations.

<div align="center">

```
Single Linked List:
[10 | •]-->[20 | •]-->[30 | •]-->[40 | NULL]

Doubly Linked List:
NULL<--[• | 10 | •]<-->[• | 20 | •]<-->[• | 30 | •]-->NULL

Circular Linked List:
    ┌──────────────────────────┐
    ↓                          ↑
[10 | •]-->[20 | •]-->[30 | •]--
```

</div>

### Key Characteristics

| Characteristic | Description | Implication |
|----------------|-------------|-------------|
| **Non-Contiguous** | Nodes stored in scattered memory locations | No memory waste, flexible size |
| **Dynamic** | Size can change during runtime | Efficient memory usage |
| **Sequential Access** | Must traverse from head to reach a node | O(n) access time |
| **Pointer-Based** | Nodes connected via pointers | Extra memory for pointers |
| **Flexible** | Easy insertion and deletion | Better than arrays for frequent modifications |

## Linked List Fundamentals

### Node Structure

```c
// Single Linked List Node
struct Node {
    int data;              // Data field
    struct Node *next;     // Pointer to next node
};

// Doubly Linked List Node
struct DNode {
    int data;              // Data field
    struct DNode *prev;    // Pointer to previous node
    struct DNode *next;    // Pointer to next node
};
```

### Memory Representation

```
For a single linked list with 3 nodes:

Memory:  [1000: data=10, next=2000]  [2000: data=20, next=3000]  [3000: data=30, next=NULL]
         ↑                            ↑                            ↑
Address: 1000                         2000                         3000

head → [1000]
```

### Why Linked Lists Matter

1. **Dynamic Size**: No need to specify size beforehand
2. **Efficient Insertion/Deletion**: O(1) when position is known
3. **Memory Efficiency**: No wasted memory from unused array elements
4. **Implementation Flexibility**: Base for other data structures (stacks, queues, graphs)
5. **No Reallocation**: Unlike arrays, no need to copy entire structure when growing

## Types of Linked Lists

### 1. **Singly Linked List**
- Each node has one pointer to the next node
- Traversal only in forward direction
- Simplest implementation
- Less memory overhead

### 2. **Doubly Linked List**
- Each node has two pointers (prev and next)
- Bidirectional traversal
- More memory overhead
- Easier deletion (no need to track previous node)

### 3. **Circular Linked List**
- Last node points back to the first node
- No NULL termination
- Useful for circular/round-robin applications
- Can start traversal from any node

### 4. **Circular Doubly Linked List**
- Combines circular and doubly linked list properties
- First node's prev points to last node
- Last node's next points to first node

## Circular Linked List

### Structure and Properties

In a circular linked list:
- The last node points back to the first node instead of NULL
- Forms a circular chain
- Can maintain pointer to last node for O(1) insertion at both ends

```c
struct Node {
    int data;
    struct Node *next;
};

// Circular list representation:
// head->next->next->...->next == head
```

### Visual Representation

```
        head
         ↓
    [10 | •]────────┐
         ↑          ↓
    [40 | •]   [20 | •]
         ↑          ↓
         └────[30 | •]
```

### Key Operations

#### **1. Insertion at Position k**

```c
void insertAtK(struct Node **head, int value, int k) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    
    // Empty list
    if (*head == NULL) {
        newNode->next = newNode;  // Point to itself
        *head = newNode;
        return;
    }
    
    // Insert at beginning (k <= 1)
    if (k <= 1) {
        struct Node *last = *head;
        while (last->next != *head)  // Find last node
            last = last->next;
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
        return;
    }
    
    // Insert at position k
    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp->next != *head; i++)
        temp = temp->next;
    
    newNode->next = temp->next;
    temp->next = newNode;
}
```

**Time Complexity:**
- Insert at beginning: O(n) - need to find last node
- Insert at position k: O(k)
- Insert after a given node: O(1)

#### **2. Deletion from Position k**

```c
void deleteFromK(struct Node **head, int k) {
    if (*head == NULL) return;
    
    struct Node *temp = *head;
    
    // Delete first node (k <= 1)
    if (k <= 1) {
        // Only one node
        if (temp->next == temp) {
            free(temp);
            *head = NULL;
            return;
        }
        
        // Find last node
        struct Node *last = *head;
        while (last->next != *head)
            last = last->next;
        
        last->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }
    
    // Find node before kth position
    for (int i = 1; i < k - 1 && temp->next != *head; i++)
        temp = temp->next;
    
    if (temp->next == *head) return;  // Position out of bounds
    
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}
```

#### **3. Display and Search**

```c
// Display all nodes
void display(struct Node *head) {
    if (!head) return;
    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Search for a value
void search(struct Node *head, int value) {
    if (!head) return;
    struct Node *temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Not found\n");
}
```

### Advantages of Circular Linked List

1. ✅ **Round-Robin Scheduling**: Natural fit for circular operations
2. ✅ **Efficient Queue Implementation**: Can access both ends quickly
3. ✅ **No NULL Checks**: No need to check for NULL in traversal
4. ✅ **Symmetric Structure**: Any node can be starting point
5. ✅ **Continuous Traversal**: Can cycle through list indefinitely

### Disadvantages

1. ❌ **Infinite Loop Risk**: Must be careful with termination conditions
2. ❌ **Complex Implementation**: More care needed than simple linked list
3. ❌ **Beginning Insertion Cost**: O(n) to find last node

## Doubly Linked List

### Structure and Properties

A doubly linked list allows bidirectional traversal:
- Each node has **prev** and **next** pointers
- Can traverse forward and backward
- Easier deletion (don't need to track previous node)

```c
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
```

### Visual Representation

```
NULL ← [prev|10|next] ⇄ [prev|20|next] ⇄ [prev|30|next] → NULL
       ↑
      head
```

### Key Operations

#### **1. Insertion at Position k**

```c
void insertAtK(struct Node **head, int value, int k) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;
    
    // Insert at beginning or empty list
    if (k <= 1 || *head == NULL) {
        newNode->next = *head;
        if (*head) 
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    
    // Find position
    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp->next; i++)
        temp = temp->next;
    
    // Insert after temp
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) 
        temp->next->prev = newNode;
    temp->next = newNode;
}
```

**Time Complexity:** O(k) to reach position k

#### **2. Deletion from Position k**

```c
void deleteFromK(struct Node **head, int k) {
    if (*head == NULL) return;
    
    struct Node *temp = *head;
    
    // Delete first node
    if (k <= 1) {
        *head = temp->next;
        if (*head) 
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    
    // Find kth node
    for (int i = 1; i < k && temp; i++)
        temp = temp->next;
    
    if (!temp) return;  // Position out of bounds
    
    // Adjust pointers
    if (temp->prev) 
        temp->prev->next = temp->next;
    if (temp->next) 
        temp->next->prev = temp->prev;
    free(temp);
}
```

**Time Complexity:** O(k) to reach position k

#### **3. Display and Search**

```c
// Display forward
void display(struct Node *head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" ⇄ ");
        head = head->next;
    }
    printf("\n");
}

// Display backward
void displayReverse(struct Node *head) {
    if (!head) return;
    
    // Go to end
    while (head->next)
        head = head->next;
    
    // Print backward
    while (head) {
        printf("%d", head->data);
        if (head->prev) printf(" ⇄ ");
        head = head->prev;
    }
    printf("\n");
}

// Search
void search(struct Node *head, int value) {
    int pos = 1;
    while (head) {
        if (head->data == value) {
            printf("Found at position %d\n", pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Not found\n");
}
```

### Advantages of Doubly Linked List

1. ✅ **Bidirectional Traversal**: Can move forward and backward
2. ✅ **Easier Deletion**: Don't need to track previous node
3. ✅ **Efficient Reverse Operations**: Natural backward movement
4. ✅ **Better for Complex Operations**: Easier to implement certain algorithms
5. ✅ **No Need for Previous Pointer**: Already have prev reference

### Disadvantages

1. ❌ **Extra Memory**: Requires additional pointer per node
2. ❌ **Complex Operations**: More pointer manipulation needed
3. ❌ **Maintenance Overhead**: Must update both prev and next pointers

## Operations and Complexity

| Operation | Singly | Doubly | Circular | Array |
|-----------|--------|--------|----------|-------|
| **Access by Index** | O(n) | O(n) | O(n) | O(1) |
| **Search** | O(n) | O(n) | O(n) | O(n) |
| **Insert at Beginning** | O(1) | O(1) | O(n)* | O(n) |
| **Insert at End** | O(n) | O(n) | O(1)† | O(1) |
| **Insert at Position k** | O(k) | O(k) | O(k) | O(n) |
| **Delete from Beginning** | O(1) | O(1) | O(n)* | O(n) |
| **Delete from End** | O(n) | O(n) | O(n) | O(1) |
| **Delete from Position k** | O(k) | O(k) | O(k) | O(n) |
| **Reverse** | O(n) | O(n) | O(n) | O(n) |

\* O(n) if maintaining pointer to head only; O(1) if maintaining tail pointer  
† O(1) if maintaining pointer to last node

## Memory Management

### Node Creation

```c
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    // For doubly linked list:
    // newNode->prev = NULL;
    return newNode;
}
```

### Memory Deallocation

```c
// Free entire singly linked list
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Free entire doubly linked list (same as singly)
void freeDList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Free circular linked list
void freeCList(struct Node *head) {
    if (!head) return;
    struct Node *current = head;
    struct Node *temp;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}
```

### Memory Comparison

```c
// Singly Linked List Node
sizeof(struct Node) = sizeof(int) + sizeof(struct Node*)
                    = 4 bytes + 8 bytes = 12 bytes (on 64-bit system)

// Doubly Linked List Node
sizeof(struct DNode) = sizeof(int) + 2 * sizeof(struct Node*)
                     = 4 bytes + 16 bytes = 20 bytes (on 64-bit system)

// Array
sizeof(int[10]) = 10 * 4 = 40 bytes (no extra overhead)
```

## Advantages and Disadvantages

### Linked Lists (General)

**Advantages:**
1. ✅ **Dynamic Size**: Grows and shrinks as needed
2. ✅ **Efficient Insertion/Deletion**: O(1) when position known
3. ✅ **No Memory Waste**: Uses exactly what's needed
4. ✅ **Easy Implementation**: Of stacks and queues
5. ✅ **No Reallocation**: No need to copy entire structure

**Disadvantages:**
1. ❌ **Sequential Access**: O(n) to access element by index
2. ❌ **Extra Memory**: Pointers require additional space
3. ❌ **Cache Inefficient**: Non-contiguous memory layout
4. ❌ **No Random Access**: Must traverse from beginning
5. ❌ **Pointer Overhead**: Extra memory per node

### Specific Comparisons

| Aspect | Circular | Doubly | Singly |
|--------|----------|--------|--------|
| **Memory/Node** | 1 pointer | 2 pointers | 1 pointer |
| **Traversal** | Forward (circular) | Both directions | Forward only |
| **Deletion** | Need previous | Easy (have prev) | Need previous |
| **Complexity** | Medium | High | Low |
| **Use Cases** | Round-robin | Navigation | Simple lists |

## Applications

### Circular Linked List Applications

1. **Operating Systems**
   - Round-robin CPU scheduling
   - Process queue management
   - Resource allocation

2. **Multiplayer Games**
   - Turn management
   - Player rotation
   - Game state cycling

3. **Media Players**
   - Playlist looping
   - Continuous playback
   - Shuffle mode

4. **Network Systems**
   - Token ring network
   - Circular buffers
   - Load balancing

### Doubly Linked List Applications

1. **Browser History**
   - Forward and backward navigation
   - Tab management
   - Undo/redo functionality

2. **Text Editors**
   - Cursor movement
   - Line navigation
   - Undo/redo stack

3. **Operating Systems**
   - Process scheduling
   - Memory management (LRU cache)
   - Thread management

4. **Music Players**
   - Previous/next track
   - Playlist navigation
   - History tracking

## When to Use Different Types

### **Use Singly Linked List When:**
- Only forward traversal needed
- Memory is constrained
- Simple implementation sufficient
- Stack/queue implementation

### **Use Doubly Linked List When:**
- Bidirectional traversal needed
- Frequent deletion operations
- Need to move backward efficiently
- Implementing complex data structures (LRU cache, browser history)

### **Use Circular Linked List When:**
- Round-robin operations needed
- No natural end point
- Continuous cycling required
- Queue implementation with quick access to both ends

### **Prefer Arrays When:**
- Frequent random access needed
- Size is known and fixed
- Cache performance critical
- Simple operations only

## Best Practices

### 1. **Always Check for NULL**
```c
if (head == NULL) {
    // Handle empty list case
    return;
}
```

### 2. **Free Memory Properly**
```c
// Always free dynamically allocated nodes
void cleanup(struct Node *head) {
    // Implementation depends on list type
    freeList(head);
}
```

### 3. **Validate Positions**
```c
if (k < 0) {
    printf("Invalid position\n");
    return;
}
```

### 4. **Handle Edge Cases**
- Empty list
- Single node
- Invalid positions
- Memory allocation failures

### 5. **Maintain Invariants**
```c
// Circular list: last->next == head
// Doubly list: node->next->prev == node
// Always maintain these relationships
```

### 6. **Use Helper Functions**
```c
struct Node* createNode(int data);
void freeList(struct Node *head);
int getLength(struct Node *head);
```

### 7. **Avoid Memory Leaks**
- Always free nodes when deleting
- Handle allocation failures
- Clean up before program termination

### 8. **Use Meaningful Names**
```c
struct Node *current, *previous, *next;  // Good
struct Node *p, *q, *r;                  // Avoid
```

---

<div align="center">

**💡 Tip:** Choose the right linked list variant based on your specific use case. Consider access patterns, memory constraints, and operation frequencies.

</div>
