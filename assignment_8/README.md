# Stack and Queue with Linked Lists - Complete Guide

## Table of Contents
- [Introduction](#introduction)
- [Stack Implementation with Linked List](#stack-implementation-with-linked-list)
- [Queue Implementation with Linked List](#queue-implementation-with-linked-list)
- [Circular Queue with Linked List](#circular-queue-with-linked-list)
- [Operations and Complexity](#operations-and-complexity)
- [Memory Management](#memory-management)
- [Implementations in this Repository](#implementations-in-this-repository)
- [Advantages and Disadvantages](#advantages-and-disadvantages)
- [Applications](#applications)
- [Best Practices](#best-practices)

## Introduction

This assignment demonstrates implementing fundamental data structures **Stack** and **Queue** using **Linked Lists** instead of arrays. Linked list implementations provide dynamic sizing and eliminate the overflow conditions that plague array-based implementations.

### Why Linked List Implementations?

**Array-Based Problems:**
- ❌ Fixed size determined at compile/initialization time
- ❌ Wastes memory if underutilized
- ❌ Stack/Queue overflow if full
- ❌ Queue: Space wastage in linear queue

**Linked List Solutions:**
- ✅ Dynamic size - grows and shrinks as needed
- ✅ No memory waste - uses exactly what's required
- ✅ No overflow condition (only limited by system memory)
- ✅ Efficient insertion and deletion at ends

## Stack Implementation with Linked List

### What is a Stack?

A **Stack** is a linear data structure following **LIFO (Last In, First Out)** principle. Elements are added and removed from the same end called the **top**.

```
Top → [30]     ← Last inserted, first to be removed
      [20]
      [10]     ← First inserted, last to be removed
```

### Structure Definition

```c
struct stack {
    int data;
    struct stack *next;
};

typedef struct stack* stack;
stack top = NULL;  // Points to top element
```

### Core Operations

#### 1. **isEmpty()**
```c
int isEmpty() {
    return top == NULL;
}
```
- **Time Complexity:** O(1)
- **Purpose:** Check if stack is empty

#### 2. **push(data)**
```c
void push(int data) {
    stack newNode = (stack)malloc(sizeof(struct stack));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
```
- **Time Complexity:** O(1)
- **Steps:**
  1. Create new node
  2. Set new node's data
  3. Make new node point to current top
  4. Update top to new node

#### 3. **pop()**
```c
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    stack temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}
```
- **Time Complexity:** O(1)
- **Steps:**
  1. Check if stack is empty
  2. Store top node
  3. Move top to next node
  4. Free old top node

#### 4. **peek()**
```c
void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top: %d\n", top->data);
}
```
- **Time Complexity:** O(1)
- **Purpose:** View top element without removing

### Visual Representation

```
Initial: top = NULL

After push(10):
top → [10|NULL]

After push(20):
top → [20|•] → [10|NULL]

After push(30):
top → [30|•] → [20|•] → [10|NULL]

After pop():
top → [20|•] → [10|NULL]
      (30 removed)
```

### Advantages over Array-Based Stack

1. ✅ **No Size Limitation**: Grows dynamically
2. ✅ **No Overflow**: Only limited by heap memory
3. ✅ **Memory Efficient**: Uses exactly what's needed
4. ✅ **O(1) Operations**: All operations constant time

### Disadvantages

1. ❌ **Extra Memory**: Pointer overhead per node
2. ❌ **Cache Performance**: Non-contiguous memory
3. ❌ **Slightly Slower**: Dynamic allocation overhead

## Queue Implementation with Linked List

### What is a Queue?

A **Queue** is a linear data structure following **FIFO (First In, First Out)** principle. Elements are added at the **rear** and removed from the **front**.

```
Front → [10] → [20] → [30] ← Rear
        ↑               ↑
    Remove here     Insert here
```

### Structure Definition

```c
struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};
```

### Core Operations

#### 1. **isEmpty()**
```c
int isEmpty() {
    return front == NULL;
}
```

#### 2. **enqueue(data)**
```c
void enqueue(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}
```
- **Time Complexity:** O(1)
- **Advantage:** No need to shift elements (unlike array)

#### 3. **dequeue()**
```c
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node *temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->next;
    if (front == NULL)  // Queue became empty
        rear = NULL;
    free(temp);
}
```
- **Time Complexity:** O(1)

## Circular Queue with Linked List

### Why Circular Queue?

**Problem with Linear Queue:**
- Space at beginning cannot be reused
- False overflow condition

**Circular Queue Solution:**
- Rear connects back to front
- Efficient space utilization
- No false overflow

### Implementation Details

This implementation uses a **circular singly linked list** where:
- Last node points to first node
- Maintain pointer to `rear` (not front)
- `rear->next` gives front element

```c
struct QueueStruct {
    struct NodeStruct *rear;
    int size;
    int capacity;
};
```

### Visual Representation

```
        rear
         ↓
    [30|•]←──┐
     ↑       │
     │   [20|•]
     │    ↑
     └─[10|•]
        ↑
    rear->next (front)
```

### Key Operations

#### **enqueue(data)**
```c
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    
    if (isEmpty()) {
        newNode->next = newNode;  // Points to itself
        queue.rear = newNode;
    } else {
        newNode->next = queue.rear->next;  // Point to front
        queue.rear->next = newNode;         // Old rear → new node
        queue.rear = newNode;               // Update rear
    }
    queue.size++;
}
```

#### **dequeue()**
```c
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }
    
    Node *front = queue.rear->next;
    
    if (queue.size == 1) {
        free(front);
        queue.rear = NULL;
    } else {
        queue.rear->next = front->next;
        free(front);
    }
    queue.size--;
}
```

### Advantages of Circular Queue

1. ✅ **Efficient Space**: All positions can be used
2. ✅ **O(1) Operations**: Enqueue and dequeue both O(1)
3. ✅ **No False Overflow**: Unlike linear queue
4. ✅ **Access to Both Ends**: rear and rear->next (front)

## Operations and Complexity

### Stack with Linked List

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| **push()** | O(1) | O(1) |
| **pop()** | O(1) | O(1) |
| **peek()** | O(1) | O(1) |
| **isEmpty()** | O(1) | O(1) |
| **display()** | O(n) | O(1) |

### Queue with Linked List

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| **enqueue()** | O(1) | O(1) |
| **dequeue()** | O(1) | O(1) |
| **peek()** | O(1) | O(1) |
| **isEmpty()** | O(1) | O(1) |
| **isFull()** | O(1) | O(1) |
| **display()** | O(n) | O(1) |

### Comparison with Array-Based

| Aspect | Array-Based | Linked List |
|--------|-------------|-------------|
| **Size** | Fixed | Dynamic |
| **Memory** | Contiguous | Scattered |
| **Overflow** | Yes | Only heap limit |
| **Memory Overhead** | Minimal | Pointer per node |
| **Cache Performance** | Better | Worse |
| **Implementation** | Simpler | More complex |

## Memory Management

### Allocation

```c
// Stack node
stack newNode = (stack)malloc(sizeof(struct stack));
if (newNode == NULL) {
    // Handle allocation failure
}

// Queue node
struct Node *newNode = malloc(sizeof(struct Node));
if (!newNode) {
    // Handle allocation failure
}
```

### Deallocation

```c
// Free stack
while (top != NULL) {
    stack temp = top;
    top = top->next;
    free(temp);
}

// Free queue
while (front != NULL) {
    struct Node *temp = front;
    front = front->next;
    free(temp);
}

// Free circular queue
if (!isEmpty()) {
    Node *current = queue.rear->next;
    Node *temp;
    int count = queue.size;
    
    for (int i = 0; i < count; i++) {
        temp = current;
        current = current->next;
        free(temp);
    }
}
```

### Memory Overhead

```
Array-based:
- Stack: size * sizeof(datatype) bytes
- Queue: capacity * sizeof(datatype) bytes

Linked List:
- Stack: n * (sizeof(datatype) + sizeof(pointer))
- Queue: n * (sizeof(datatype) + sizeof(pointer))

Example with int (4 bytes) and pointer (8 bytes):
- Array: 10 * 4 = 40 bytes
- Linked List: 10 * (4 + 8) = 120 bytes (3x more)
```

## Implementations in this Repository

### 1. **Stack with Linked List** (`stack_with_linkedlist.c`)
- push() - Insert element at top
- pop() - Remove element from top
- peek() - View top element
- isEmpty() - Check if empty
- display() - Show entire stack

### 2. **Circular Queue with Linked List** (`circular_queue_with_linkedlist.c`)
- enqueue() - Insert at rear
- dequeue() - Remove from front
- display() - Show all elements
- peek() - View front and rear
- isFull() - Check capacity limit
- isEmpty() - Check if empty

Both implementations feature:
- ✅ Menu-driven interface
- ✅ Complete error handling
- ✅ Memory management
- ✅ Input validation

## Advantages and Disadvantages

### Stack with Linked List

**Advantages:**
1. ✅ Dynamic size - no fixed limit
2. ✅ No stack overflow (except heap exhaustion)
3. ✅ O(1) push and pop operations
4. ✅ Memory efficient - uses only what's needed

**Disadvantages:**
1. ❌ Extra memory for pointers
2. ❌ Slower than array (dynamic allocation overhead)
3. ❌ Poor cache locality
4. ❌ No random access

### Queue with Linked List

**Advantages:**
1. ✅ Dynamic size
2. ✅ No queue overflow
3. ✅ O(1) enqueue and dequeue
4. ✅ No wasted space (unlike linear queue)

**Disadvantages:**
1. ❌ Extra memory overhead
2. ❌ Slower allocation/deallocation
3. ❌ Poor cache performance
4. ❌ More complex implementation

## Applications

### Stack Applications

1. **Function Call Management**
   - Call stack in programming languages
   - Local variable storage
   - Return address tracking

2. **Expression Evaluation**
   - Infix to postfix conversion
   - Postfix expression evaluation
   - Parenthesis matching

3. **Browser History**
   - Back button functionality
   - Navigation stack

4. **Undo/Redo Operations**
   - Text editors
   - Graphics software
   - Command history

### Queue Applications

1. **Operating Systems**
   - Process scheduling
   - Job queue management
   - Print spooler

2. **Networking**
   - Packet buffering
   - Request handling
   - Message queues

3. **Real-World Systems**
   - Customer service lines
   - Call center systems
   - Ticket booking

4. **Data Streaming**
   - Video buffering
   - Audio playback
   - Data transfer

### Circular Queue Applications

1. **CPU Scheduling**
   - Round-robin scheduling
   - Time-sliced systems

2. **Resource Allocation**
   - Printer queue
   - Disk scheduling

3. **Multiplayer Games**
   - Turn management
   - Player rotation

## Best Practices

### 1. **Always Check Allocation**
```c
Node *newNode = malloc(sizeof(Node));
if (newNode == NULL) {
    printf("Memory allocation failed\n");
    return;
}
```

### 2. **Handle Empty Cases**
```c
if (isEmpty()) {
    printf("Stack/Queue is empty\n");
    return;
}
```

### 3. **Free Memory on Exit**
```c
// Clean up all nodes before program termination
while (top != NULL) {
    pop();
}
```

### 4. **Use Typedef for Readability**
```c
typedef struct Node* NodePtr;
NodePtr top = NULL;
```

### 5. **Validate Operations**
```c
// For bounded queue
if (isFull()) {
    printf("Queue is full\n");
    return;
}
```

### 6. **Maintain Invariants**
```c
// Queue: if front == NULL, rear must also be NULL
// Circular: rear->next must always point to front
```

### 7. **Document Edge Cases**
```c
// Handle single element case specially
if (queue.size == 1) {
    // Special cleanup
}
```

---

<div align="center">

**💡 Tip:** Choose linked list implementations when you need dynamic sizing and don't know the maximum size in advance. Use array-based implementations for better cache performance when size is known.

</div>
