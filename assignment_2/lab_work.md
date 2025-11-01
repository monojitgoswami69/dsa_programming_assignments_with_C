<h1 align="center">ASSIGNMENT - 2: Stack Implementation</h1>

<div align="center" id="index">
  <h2>Table of Contents</h2>
</div>

<div align="center">

| **Implementation** |
|---|
| [**#1** Stack using Array](#implementation1) |
| [**#2** Stack using Structure](#implementation2) |

</div>

---

> **Note:** You can write **any one** of the following implementations for your lab work.

---

<a id="implementation1"></a>
## 1. Stack Implementation - Using Array

### Problem Statement
Write a menu driven program in C to implement a Stack using array and perform the following operations.
- (a) `isFull()` function to check whether the Stack is full or not.
- (b) `isEmpty()` function to check whether the Stack is empty or not.
- (c) `peek()` function to read the stack top element without deleting it.
- (d) `push(item)` function to insert an element item in the Stack.
- (e) `pop()` function to read and remove an element from the Stack.
- (f) `display()` function to display the entire stack.

### Algorithm

1. **Start**
2. **Initialize**:
   - Declare a dynamic array `stack` for storing elements.
   - Set `top = -1` (indicating an empty stack).
   - Accept the stack size from the user and store it in `size`.
3. **Define Helper Functions**:
   - **isEmpty()**:
     - Check if `top == -1`.
     - If true, return `true` (stack is empty).
     - Otherwise, return `false` (stack has elements).
   - **isFull()**:
     - Check if `top == size - 1`.
     - If true, return `true` (stack is full).
     - Otherwise, return `false` (stack has space).
4. **Display Menu**:
   - Present the user with the following options:
     1. View Stack
     2. Push Element
     3. Pop Element
     4. Peek Top Element
     5. Exit
5. **Perform Operations Based on User Choice**:
   - **View Stack**:
     - Check if the stack is empty using `isEmpty()`.
     - If empty, display "Stack is empty."
     - Otherwise, display all elements from `top` to `0`.
   - **Push Element**:
     - Check if the stack is full using `isFull()`.
     - If full, display "Stack Overflow."
     - Otherwise:
       - Increment `top`.
       - Insert the new element at `stack[top]`.
       - Display a success message.
   - **Pop Element**:
     - Check if the stack is empty using `isEmpty()`.
     - If empty, display "Stack Underflow."
     - Otherwise:
       - Retrieve the element at `stack[top]`.
       - Decrement `top`.
       - Display the popped element.
   - **Peek Top Element**:
     - Check if the stack is empty using `isEmpty()`.
     - If empty, display "Stack is empty."
     - Otherwise, display the element at `stack[top]`.
   - **Exit**:
     - Free the allocated memory for the stack.
     - Terminate the program.
6. **Repeat** until the user chooses to exit.
7. **Stop**

### Source Code

```c
/*
ASSIGNMENT 2:
Problem Statement: Write a menu driven program in C to implement a Stack using array and perform the following operations.
(a) isFull() function to check whether the Stack is full or not.
(b) isEmpty() function to check whether the Stack is empty or not.
(c) peek() function to read the stack top element without deleting it.
(d) push(item) function to insert an element item in the Stack.
(e) pop() function to read and remove an element from the Stack.
(f) display() function to display the entire stack.
*/

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

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
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
            case 2: {
                int data;
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            }
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

### Sample Output

```
Enter stack size(n): 5

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 10
Element 10 pushed

Selection: 2
Enter element to push: 20
Element 20 pushed

Selection: 2
Enter element to push: 30
Element 30 pushed

Selection: 1
Stack -
30 <- Top
20
10

Selection: 4
30 <- Top

Selection: 3
Popped: 30

Selection: 1
Stack -
20 <- Top
10

Selection: 2
Enter element to push: 40
Element 40 pushed

Selection: 2
Enter element to push: 50
Element 50 pushed

Selection: 2
Enter element to push: 60
Element 60 pushed

Selection: 2
Enter element to push: 70
Stack Overflow

Selection: 1
Stack -
60 <- Top
50
40
20
10

Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>

<a id="implementation2"></a>
## 2. Stack Implementation - Using Structure

### Problem Statement
Write a menu driven program in C to implement a Stack using array encapsulated in a structure and perform the following operations.
- (a) `isFull()` function to check whether the Stack is full or not.
- (b) `isEmpty()` function to check whether the Stack is empty or not.
- (c) `peek()` function to read the stack top element without deleting it.
- (d) `push(item)` function to insert an element item in the Stack.
- (e) `pop()` function to read and remove an element from the Stack.
- (f) `display()` function to display the entire stack.

### Algorithm

1. **Start**
2. **Define Structure**:
   - Create a structure `StackStruct` with the following members:
     - `int *arr`: A dynamic array pointer for stack elements.
     - `int top`: An index indicating the top element.
     - `int size`: The maximum capacity of the stack.
3. **Declare Global Variable**:
   - Declare a variable `stack` of type `StackStruct`.
4. **Initialize**:
   - Accept the stack size from the user.
   - Validate the size: `stack.size > 0`.
   - Allocate memory for the stack array: `stack.arr = (int *) malloc(stack.size * sizeof(int))`.
   - Check if memory allocation was successful.
   - Set `stack.top = -1` (indicating an empty stack).
5. **Display Menu**:
   - Present the user with the following options:
     1. View Stack
     2. Push Element
     3. Pop Element
     4. Peek Top Element
     5. Exit
6. **Perform Operations Based on User Choice**:
   - **View Stack**:
     - Check if the stack is empty using `isEmpty()`.
     - If empty, display "Stack is empty."
     - Otherwise, display all elements from `top` to `0`.
   - **Push Element**:
     - Check if the stack is full using `isFull()`.
     - If full, display "Stack Overflow."
     - Otherwise:
       - Increment `stack.top`.
       - Insert the new element at `stack.arr[stack.top]`.
       - Display a success message.
   - **Pop Element**:
     - Check if the stack is empty using `isEmpty()`.
     - If empty, display "Stack Underflow."
     - Otherwise:
       - Retrieve the element at `stack.arr[stack.top]`.
       - Decrement `stack.top`.
       - Display the popped element.
   - **Peek Top Element**:
     - Check if the stack is empty using `isEmpty()`.
     - If empty, display "Stack is empty."
     - Otherwise, display the element at `stack.arr[stack.top]`.
   - **Exit**:
     - Free the allocated memory for the stack.
     - Terminate the program.
7. **Repeat** until the user chooses to exit.
8. **Stop**

### Source Code

```c
/*
ASSIGNMENT 2:
Problem Statement: Write a menu driven program in C to implement a Stack using array and perform the following operations.
(a) isFull() function to check whether the Stack is full or not.
(b) isEmpty() function to check whether the Stack is empty or not.
(c) peek() function to read the stack top element without deleting it.
(d) push(item) function to insert an element item in the Stack.
(e) pop() function to read and remove an element from the Stack.
(f) display() function to display the entire stack.
*/

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

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
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
            case 2: {
                int data;
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            }
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

### Sample Output

```
Enter stack size(n): 4

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 5
Element 5 pushed

Selection: 2
Enter element to push: 15
Element 15 pushed

Selection: 2
Enter element to push: 25
Element 25 pushed

Selection: 1
Stack -
25 <- Top
15
5

Selection: 4
25 <- Top

Selection: 2
Enter element to push: 35
Element 35 pushed

Selection: 1
Stack -
35 <- Top
25
15
5

Selection: 2
Enter element to push: 45
Stack Overflow

Selection: 3
Popped: 35

Selection: 3
Popped: 25

Selection: 1
Stack -
15 <- Top
5

Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>
