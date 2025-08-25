# Stack Data Structure Implementation in C

## Table of Contents
- [What is a Stack?](#what-is-a-stack)
- [Stack Operations](#stack-operations)
- [Uses of Stack](#uses-of-stack)
- [Advantages and Disadvantages](#advantages-and-disadvantages)
- [Methods to Implement Stack in C](#methods-to-implement-stack-in-c)
- [Implementations in this Repository](#implementations-in-this-repository)

## What is a Stack?

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. This means that the last element added to the stack is the first one to be removed. Think of it like a stack of plates - you can only add or remove plates from the top.

<div align="center">
  <img src="stack.png" alt="Stack Data Structure Illustration" />
</div>

## Stack Operations

### Core Operations

1. **Push**: Add an element to the top of the stack
2. **Pop**: Remove and return the top element from the stack
3. **Peek/Top**: View the top element without removing it
4. **isEmpty**: Check if the stack is empty
5. **isFull**: Check if the stack is full (for fixed-size implementations)

### Additional Operations

- **Size**: Get the number of elements in the stack
- **Display/Print**: Show all elements in the stack

## Uses of Stack

### 1. **Function Call Management**
- Managing function calls and local variables
- Handling recursive function calls
- Return address storage

### 2. **Expression Evaluation**
- Infix to postfix conversion
- Postfix expression evaluation
- Parentheses matching and balancing

### 3. **Undo Operations**
- Text editors (Ctrl+Z functionality)
- Browser back button
- Game state management

### 4. **Memory Management**
- Call stack in programming languages
- Activation records
- Local variable storage

### 5. **Parsing and Syntax Analysis**
- Compiler design
- XML/HTML tag matching
- Mathematical expression parsing

### 6. **Backtracking Algorithms**
- Maze solving
- N-Queens problem
- Graph traversal (DFS)



## Advantages and Disadvantages

### ✅ Advantages

| Advantage | Description |
|-----------|-------------|
| **Simple Implementation** | Easy to implement and understand |
| **Memory Efficient** | Uses memory only for stored elements |
| **Fast Operations** | O(1) time complexity for push, pop, peek |
| **No Memory Fragmentation** | Contiguous memory allocation (array-based) |
| **LIFO Access** | Perfect for problems requiring reverse order processing |
| **Function Call Support** | Natural fit for recursive algorithms |

### ❌ Disadvantages

| Disadvantage | Description |
|--------------|-------------|
| **Limited Access** | Can only access the top element |
| **Fixed Size** | Array-based implementations have size limitations |
| **No Random Access** | Cannot access middle elements directly |
| **Stack Overflow** | Risk of overflow in fixed-size implementations |
| **Memory Waste** | Array-based stacks may waste memory |
| **Sequential Access Only** | Must pop elements to access lower ones |



## Methods to Implement Stack in C

There are several ways to implement a stack in C:

### 1. **Array-Based Implementation**
- Uses a fixed-size array
- Simple and memory-efficient
- Limited by array size

### 2. **Dynamic Array Implementation**
- Uses dynamic memory allocation
- Can resize when needed
- More flexible than fixed arrays

### 3. **Linked List Implementation**
- Uses nodes with pointers
- Dynamic size allocation
- No size limitations (except memory)

### 4. **Structure-Based Implementation**
- Encapsulates stack data in structures
- Better organization and modularity
- Can use arrays or linked lists internally

### 5. **Stack Using Two Queues**
- Theoretical implementation
- Demonstrates algorithm concepts
- Not commonly used in practice

### 6. **Stack Using Recursive Functions**
- Uses function call stack
- Implicit stack implementation
- Limited by system stack size



## Implementations in this Repository

This repository contains **three different implementations** of stack data structure, all maintaining identical user interfaces while using different internal data structures:

> Expand to view detailed information about each implementation method.

<details>
<summary><strong>🔹 Array-Based Stack Implementation</strong></summary>

### Overview
This implementation uses a **dynamic array** with global variables to store stack elements. It's the most straightforward approach and demonstrates basic pointer arithmetic.

### Key Features
- **Global Variables**: `int *stack`, `int top`, `int size`
- **Dynamic Memory**: Uses `malloc()` for memory allocation
- **Pointer Arithmetic**: Uses `*(stack + top)` for element access
- **Memory Management**: Proper allocation and deallocation

### How it Works
1. **Initialization**: Allocates memory based on user-specified size
2. **Push Operation**: Increments `top` and adds element at `stack[top]`
3. **Pop Operation**: Returns `stack[top]` and decrements `top`
4. **Memory Access**: Uses pointer arithmetic for element manipulation

### Advantages
- ✅ Simple and fast
- ✅ Contiguous memory allocation
- ✅ O(1) time complexity for all operations
- ✅ Low memory overhead

### Disadvantages
- ❌ Fixed size after initialization
- ❌ Memory waste if not fully utilized
- ❌ Stack overflow possible

### Source Code
```c
#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int size;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == size - 1;
}

void viewStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack -\n%d <- Top\n", *(stack + top));
    for (int i = top - 1; i >= 0; i--)
        printf("%d\n", *(stack + i));
    printf("\n");
}

void push() {
    int x;
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &x);
    top++;
    *(stack + top) = x;
    printf("Element %d pushed\n", x);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", *(stack + top));
    top--;
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d <- Top\n", *(stack + top));
}

int main() {
    int choice;
    printf("Enter stack size(n): ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid stack size. Must be positive.\n");
        return 1;
    }
    stack = (int *) malloc(size * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    while (1) {
        printf("\nSelect operation to perform:\n");
        printf("1. View stack\n2. Push\n3. Pop\n4. Peek\n5. Exit\nSelection: ");
        scanf("%d", &choice);
        while (choice <= 0 || choice >= 6) {
            printf("Invalid selection\nSelection: ");
            scanf("%d", &choice);
        }
        switch (choice) {
            case 1: viewStack(); break;
            case 2: push(); break;
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: 
                free(stack);
                return 0;
        }
    }
}
```

</details>

<details>
<summary><strong>🔹 Structure-Based Stack Implementation</strong></summary>

### Overview
This implementation uses a **custom structure** with typedef to encapsulate stack data. It demonstrates object-oriented principles in C and provides better code organization.

### Key Features
- **Structure Definition**: Separate `struct` declaration and `typedef`
- **Encapsulation**: All stack data contained in a single structure
- **Global Structure**: `Stack stack` declared globally
- **Dot Notation**: Uses `stack.top`, `stack.arr` for member access

### How it Works
1. **Structure Design**: 
   ```c
   struct StackStruct {
       int *arr;    // Array to store elements
       int top;     // Top index
       int size;    // Maximum size
   };
   ```
2. **Initialization**: Allocates memory for the array within the structure
3. **Operations**: All functions work with the global structure instance
4. **Memory Management**: Frees only the internal array, structure is global

### Advantages
- ✅ Better code organization
- ✅ Encapsulated data
- ✅ Clear separation of concerns
- ✅ Reusable structure design
- ✅ Type safety with typedef

### Disadvantages
- ❌ Still limited by initial size
- ❌ Slightly more complex than simple array
- ❌ Additional memory for structure overhead

### Source Code
```c
#include <stdio.h>
#include <stdlib.h>

struct StackStruct {
    int *arr;
    int top;
    int size;
};

typedef struct StackStruct Stack;

Stack stack;

int isEmpty() {
    return stack.top == -1;
}

int isFull() {
    return stack.top == stack.size - 1;
}

void viewStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack -\n%d <- Top\n", stack.arr[stack.top]);
    for (int i = stack.top - 1; i >= 0; i--)
        printf("%d\n", stack.arr[i]);
    printf("\n");
}

void push() {
    int x;
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &x);
    stack.top++;
    stack.arr[stack.top] = x;
    printf("Element %d pushed\n", x);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack.arr[stack.top]);
    stack.top--;
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d <- Top\n", stack.arr[stack.top]);
}

int main() {
    int choice;
    printf("Enter stack size(n): ");
    scanf("%d", &stack.size);
    if (stack.size <= 0) {
        printf("Invalid stack size. Must be positive.\n");
        return 1;
    }
    stack.arr = (int *) malloc(stack.size * sizeof(int));
    if (stack.arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    stack.top = -1;
    
    while (1) {
        printf("\nSelect operation to perform:\n");
        printf("1. View stack\n2. Push\n3. Pop\n4. Peek\n5. Exit\nSelection: ");
        scanf("%d", &choice);
        while (choice <= 0 || choice >= 6) {
            printf("Invalid selection\nSelection: ");
            scanf("%d", &choice);
        }
        switch (choice) {
            case 1: viewStack(); break;
            case 2: push(); break;
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: 
                free(stack.arr);
                return 0;
        }
    }
}
```

</details>

<details>
<summary><strong>🔹 Linked List-Based Stack Implementation</strong></summary>

### Overview
This implementation uses a **linked list** structure where each node contains data and a pointer to the next node. It provides dynamic memory allocation without size limitations.

### Key Features
- **Node Structure**: Each element is stored in a separate node
- **Dynamic Growth**: No fixed size limitations
- **Pointer-based**: Uses `typedef struct stack* stack` for pointer type
- **Top Pointer**: Global `top` pointer points to the topmost node

### How it Works
1. **Node Design**:
   ```c
   struct stack {
       int data;           // Element value
       struct stack *next; // Pointer to next node
   };
   ```
2. **Push Operation**: Creates new node, links to current top, updates top
3. **Pop Operation**: Saves top data, updates top to next node, frees old top
4. **Memory Management**: Allocates/deallocates individual nodes

### Advantages
- ✅ Dynamic size (no fixed limitations)
- ✅ Memory efficient (allocates only what's needed)
- ✅ No stack overflow (except system memory limits)
- ✅ Flexible growth and shrinkage
- ✅ No memory waste

### Disadvantages
- ❌ Extra memory overhead for pointers
- ❌ Non-contiguous memory allocation
- ❌ Slightly slower due to pointer traversal
- ❌ Potential memory fragmentation

### Source Code
```c
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack *next;
};

typedef struct stack* stack;

stack top = NULL;

int isEmpty() {
    return top == NULL;
}

void viewStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack -\n");
    stack current = top;
    int isFirst = 1;
    
    while (current != NULL) {
        if (isFirst) {
            printf("%d <- Top\n", current->data);
            isFirst = 0;
        } else {
            printf("%d\n", current->data);
        }
        current = current->next;
    }
    printf("\n");
}

void push() {
    int x;
    printf("Enter element to push: ");
    scanf("%d", &x);
    
    stack newNode = (stack)malloc(sizeof(struct stack));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("Element %d pushed\n", x);
}

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

void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d <- Top\n", top->data);
}

int main() {
    int choice;
    while (1) {
        printf("\nSelect operation to perform:\n");
        printf("1. View stack\n2. Push\n3. Pop\n4. Peek\n5. Exit\nSelection: ");
        scanf("%d", &choice);
        while (choice <= 0 || choice >= 6) {
            printf("Invalid selection\nSelection: ");
            scanf("%d", &choice);
        }
        switch (choice) {
            case 1: viewStack(); break;
            case 2: push(); break;
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: 
                while (top != NULL) {
                    stack temp = top;
                    top = top->next;
                    free(temp);
                }
                return 0;
        }
    }
}
```

</details>

---

## Performance Comparison

| Operation | Array-Based | Struct-Based | Linked List-Based |
|-----------|-------------|--------------|------------------|
| **Push** | O(1) | O(1) | O(1) |
| **Pop** | O(1) | O(1) | O(1) |
| **Peek** | O(1) | O(1) | O(1) |
| **Space** | O(n) | O(n) | O(n) + pointer overhead |
| **Memory** | Contiguous | Contiguous | Non-contiguous |
| **Size Limit** | Fixed | Fixed | Dynamic |

## Conclusion

Each implementation method has its own advantages and use cases:

- **Array-based**: Best for performance-critical applications with known size limits
- **Structure-based**: Best for organized, maintainable code with clear data encapsulation  
- **Linked List-based**: Best for applications requiring dynamic sizing and memory efficiency

All three implementations in this repository maintain identical user interfaces while demonstrating different approaches to stack data structure implementation in C programming language.
