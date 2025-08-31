# Stack Data Structure - Complete Guide

## Table of Contents
- [What is a Stack?](#what-is-a-stack)
- [Stack Operations](#stack-operations)
- [Memory Management Approaches](#memory-management-approaches)
- [Implementations in this Repository](#implementations-in-this-repository)
- [Performance Analysis](#performance-analysis)
- [Applications](#applications)
- [When to Use Stacks](#when-to-use-stacks)
- [Best Practices](#best-practices)

## What is a Stack?

A **Stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. This means that the last element added to the stack is the first one to be removed.

<div align="center">
  <img src="stack.png" alt="Stack Data Structure Visualization" />
</div>

### Key Characteristics

| Characteristic | Description | Implication |
|----------------|-------------|-------------|
| **LIFO Ordering** | Last element in is first element out | Reverse order processing |
| **Top Access Only** | Only the top element is accessible | Limited but predictable access |
| **Dynamic Size** | Can grow and shrink during execution | Flexible memory usage |
| **Push/Pop Operations** | Primary operations for adding/removing | Simple interface |

### Memory Layout

```
Stack Memory (Top to Bottom):
    ↓ Push Direction
[  30  ] ← Top (index: 2)
[  20  ] ← Middle (index: 1)  
[  10  ] ← Bottom (index: 0)
    ↑ Pop Direction
```

## Stack Operations

### Core Operations

| Operation | Description | Time Complexity | Space Complexity | Error Condition |
|-----------|-------------|-----------------|------------------|-----------------|
| **Push** | Add element to top | O(1) | O(1) | Stack Overflow |
| **Pop** | Remove and return top element | O(1) | O(1) | Stack Underflow |
| **Peek** | View top element without removing | O(1) | O(1) | Empty stack |
| **isEmpty** | Check if stack is empty | O(1) | O(1) | None |
| **isFull** | Check if stack is full | O(1) | O(1) | Fixed-size only |

### Operation Examples

```
Initial Stack: []
push(10): [10]           // top = 0
push(20): [10, 20]       // top = 1  
push(30): [10, 20, 30]   // top = 2
peek(): returns 30       // Stack unchanged
pop(): returns 30        // Stack: [10, 20]
pop(): returns 20        // Stack: [10]
```

### Detailed Operation Analysis

#### 1. **Push Operation**
```c
void push(int element) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = element;
}
```

**Process:**
1. **Check Capacity**: Verify if stack has space for new element
2. **Increment Pointer**: Move top pointer to next available position
3. **Insert Element**: Place new element at the top position
4. **Update State**: Stack size effectively increases by 1

**Time Complexity**: O(1) - Direct array access or pointer manipulation
**Space Complexity**: O(1) - No additional space required

#### 2. **Pop Operation**
```c
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;  // Error value
    }
    return stack[top--];
}
```

**Process:**
1. **Check Availability**: Verify stack is not empty
2. **Retrieve Element**: Get value at current top position
3. **Decrement Pointer**: Move top pointer to previous position
4. **Return Value**: Provide popped element to caller

**Time Complexity**: O(1) - Direct array access
**Space Complexity**: O(1) - No additional space needed

#### 3. **Peek/Top Operation**
```c
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;  // Error value
    }
    return stack[top];
}
```

**Process:**
1. **Validate State**: Check if stack contains elements
2. **Access Element**: Read value at top position
3. **Preserve State**: No modification to stack structure
4. **Return Copy**: Provide element value without removal

**Time Complexity**: O(1) - Single array access
**Space Complexity**: O(1) - Read-only operation

#### 4. **isEmpty Check**
```c
int isEmpty() {
    return top == -1;  // For array implementation
    return top == NULL; // For linked list implementation
}
```

**Process:**
1. **Compare State**: Check top pointer against empty condition
2. **Return Boolean**: Immediate true/false result

**Why O(1)**: Single comparison operation regardless of stack size

#### 5. **isFull Check (Array-based only)**
```c
int isFull() {
    return top == size - 1;
}
```

**Process:**
1. **Compare Capacity**: Check if top reached maximum index
2. **Return Status**: Boolean result for capacity check

**Note**: Not applicable for linked list implementations (dynamic size)

### Error Handling Analysis

| Operation | Error Condition | Detection Method | Recovery Action |
|-----------|----------------|------------------|-----------------|
| **Push** | Stack Overflow | `top >= size-1` | Return error, reject operation |
| **Pop** | Stack Underflow | `top < 0` | Return error value, maintain state |
| **Peek** | Empty Stack | `top < 0` | Return error value, no change |
| **Access** | Invalid Index | Bounds checking | Prevent undefined behavior |

## Memory Management Approaches

### 1. **Array-Based Implementation**
- **Memory**: Fixed-size array with dynamic allocation
- **Advantages**: Fast O(1) operations, contiguous memory
- **Disadvantages**: Fixed size after initialization

### 2. **Linked List Implementation**
- **Memory**: Dynamic node allocation
- **Advantages**: No size limits, memory efficient
- **Disadvantages**: Pointer overhead, non-contiguous memory

### 3. **Structure-Based Implementation**
- **Memory**: Organized data encapsulation
- **Advantages**: Better code organization, reusable design
- **Disadvantages**: Slight overhead for structure management

## Implementations in this Repository

> Expand to view detailed information about each implementation approach.

<details>
<summary><strong>🔹 Array-Based Stack Implementation</strong></summary>

### Overview
Uses a dynamic array with global variables for stack management.

### Key Features
- Global variables: `int *stack`, `int top`, `int size`
- Dynamic memory allocation with `malloc()`
- Pointer arithmetic for element access

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
        switch (choice) {
            case 1: viewStack(); break;
            case 2: push(); break;
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: 
                free(stack);
                return 0;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
}
```

</details>

<details>
<summary><strong>🔹 Structure-Based Stack Implementation</strong></summary>

### Overview
Uses a custom structure with typedef for better code organization.

### Key Features
- Structure encapsulation: `struct StackStruct`
- Global structure instance: `Stack stack`
- Dot notation for member access

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
        switch (choice) {
            case 1: viewStack(); break;
            case 2: push(); break;
            case 3: pop(); break;
            case 4: peek(); break;
            case 5: 
                free(stack.arr);
                return 0;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
}
```

</details>

<details>
<summary><strong>🔹 Linked List-Based Stack Implementation</strong></summary>

### Overview
Uses a linked list structure for dynamic memory allocation without size limitations.

### Key Features
- Node structure with data and next pointer
- Dynamic growth with no fixed size limits
- Efficient memory usage

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
            default:
                printf("Invalid selection\n");
                break;
        }
    }
}
```

</details>

## Performance Analysis

### Time Complexity Comparison

| Implementation | Push | Pop | Peek | Space |
|----------------|------|-----|------|-------|
| **Array-based** | O(1) | O(1) | O(1) | O(n) |
| **Linked List** | O(1) | O(1) | O(1) | O(n) + pointer overhead |
| **Structure-based** | O(1) | O(1) | O(1) | O(n) |

### Memory Usage Analysis

```c
// Memory footprint comparison
Array-based:     size * sizeof(int) + overhead
Linked List:     n * (sizeof(int) + sizeof(pointer))
Structure-based: size * sizeof(int) + struct overhead
```

### Performance Benchmarks

- **Array-based**: Fastest due to contiguous memory and cache efficiency
- **Linked List**: Slightly slower due to dynamic allocation overhead
- **Structure-based**: Similar to array-based with minimal overhead

## Applications

### System Programming
- **Function Call Management**: Storing return addresses and local variables
- **Memory Management**: Automatic variable allocation in program stack
- **Interrupt Handling**: Saving processor state during interrupts

### Algorithm Implementation
- **Graph Traversal**: Depth-First Search implementation
- **Backtracking**: N-Queens, Sudoku solving, maze navigation
- **Expression Parsing**: Compiler design and mathematical evaluation

### Application Development
- **Undo Operations**: Text editors, graphics software
- **Browser History**: Back button functionality
- **Game Development**: State management and AI decision trees

## When to Use Stacks

### **Ideal Use Cases**
- **Function call management** and recursion simulation
- **Expression evaluation** and syntax parsing
- **Undo/Redo operations** in user interfaces
- **Backtracking algorithms** and state exploration
- **Memory management** with automatic cleanup

### **Avoid When**
- **Random access** to elements is needed
- **FIFO processing** is required (use queues)
- **Sorting or searching** operations are primary
- **Multiple access points** are needed

## Best Practices

### Implementation Guidelines
- **Always validate bounds**: Check for overflow and underflow
- **Initialize properly**: Set top to -1 for array implementations
- **Handle memory carefully**: Free allocated memory in linked implementations
- **Use meaningful names**: Clear function and variable naming

### Error Handling
- **Graceful error handling**: Never crash on invalid operations
- **Clear error messages**: Provide specific feedback for failures
- **Boundary validation**: Check all input parameters
- **Memory allocation checks**: Verify malloc() success

### Performance Optimization
- **Choose appropriate implementation**: Based on size requirements
- **Minimize dynamic allocation**: Reuse memory where possible
- **Consider cache performance**: Array-based for better locality
- **Profile memory usage**: Monitor stack depth in recursive algorithms

### Code Organization
- **Encapsulate data**: Use structures for better organization
- **Separate concerns**: Keep stack operations independent
- **Document interfaces**: Provide clear function documentation
- **Test thoroughly**: Include edge cases and error conditions
