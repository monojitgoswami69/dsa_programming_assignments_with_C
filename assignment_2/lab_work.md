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

1. START
2. Declare dynamic array pointer: `int *stack`
3. Initialize `top = -1` (empty stack indicator)
4. Accept stack size from user and store in `size`
5. Validate size: `size > 0`
6. Allocate memory: `stack = (int *) malloc(size * sizeof(int))`
7. Check if memory allocation successful
8. Display menu with operations and accept user choice
9. **For isEmpty() function**:
   - Check condition: `top == -1`
   - If true, return 1 (stack is empty)
   - Else, return 0 (stack has elements)
10. **For isFull() function**:
    - Check condition: `top == size - 1`
    - If true, return 1 (stack is full)
    - Else, return 0 (stack has space)
11. **For push() operation**:
    - Call `isFull()` to check if stack is full
    - If full, display "Stack Overflow" and return
    - Else:
      * Accept element from user
      * Increment top: `top++`
      * Insert element: `*(stack + top) = element`
      * Display success message
12. **For pop() operation**:
    - Call `isEmpty()` to check if stack is empty
    - If empty, display "Stack Underflow" and return
    - Else:
      * Retrieve and display element: `*(stack + top)`
      * Decrement top: `top--`
13. **For peek() operation**:
    - Call `isEmpty()` to check if stack is empty
    - If empty, display "Stack is empty"
    - Else:
      * Display top element without removing: `*(stack + top)`
14. **For viewStack() operation**:
    - Call `isEmpty()` to check if stack is empty
    - If empty, display "Stack is empty"
    - Else:
      * Display "Stack -"
      * Print top element with marker: `*(stack + top) <- Top`
      * Traverse from `i = top-1` down to `i = 0`:
        - Print each element: `*(stack + i)`
15. **For Exit**:
    - Free allocated memory: `free(stack)`
    - Terminate program
16. Repeat menu until user chooses to exit
17. STOP

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

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 20
Element 20 pushed

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 30
Element 30 pushed

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 1
Stack -
30 <- Top
20
10

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 4
30 <- Top

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 3
Popped: 30

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 1
Stack -
20 <- Top
10

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 40
Element 40 pushed

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 50
Element 50 pushed

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 60
Element 60 pushed

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 70
Stack Overflow

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 1
Stack -
60 <- Top
50
40
20
10

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
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

1. START
2. Define structure `StackStruct` with three members:
   - `int *arr` (dynamic array pointer for stack elements)
   - `int top` (index of top element)
   - `int size` (maximum capacity of stack)
3. Create typedef: `typedef struct StackStruct Stack`
4. Declare global variable: `Stack stack`
5. Accept stack size from user
6. Validate size: `stack.size > 0`
7. Allocate memory for stack array:
   - `stack.arr = (int *) malloc(stack.size * sizeof(int))`
   - Check if memory allocation successful
8. Initialize `stack.top = -1` (empty stack)
9. Display menu with operations and accept user choice
10. **For isEmpty() function**:
    - Check condition: `stack.top == -1`
    - If true, return 1 (stack is empty)
    - Else, return 0 (stack has elements)
11. **For isFull() function**:
    - Check condition: `stack.top == stack.size - 1`
    - If true, return 1 (stack is full)
    - Else, return 0 (stack has space)
12. **For push() operation**:
    - Call `isFull()` to check stack status
    - If full, display "Stack Overflow" and return
    - Else:
      * Accept element from user
      * Increment top: `stack.top++`
      * Insert element: `stack.arr[stack.top] = element`
      * Display success message
13. **For pop() operation**:
    - Call `isEmpty()` to check stack status
    - If empty, display "Stack Underflow" and return
    - Else:
      * Retrieve and display element: `stack.arr[stack.top]`
      * Decrement top: `stack.top--`
14. **For peek() operation**:
    - Call `isEmpty()` to check stack status
    - If empty, display "Stack is empty"
    - Else:
      * Display top element without removing: `stack.arr[stack.top]`
15. **For viewStack() operation**:
    - Call `isEmpty()` to check stack status
    - If empty, display "Stack is empty"
    - Else:
      * Display "Stack -"
      * Print top element with marker: `stack.arr[stack.top] <- Top`
      * Traverse from `i = stack.top - 1` down to `i = 0`:
        - Print each element: `stack.arr[i]`
16. **For Exit**:
    - Free allocated memory: `free(stack.arr)`
    - Terminate program
17. Repeat menu until user chooses to exit
18. STOP

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

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 15
Element 15 pushed

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 25
Element 25 pushed

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 1
Stack -
25 <- Top
15
5

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 4
25 <- Top

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 35
Element 35 pushed

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 1
Stack -
35 <- Top
25
15
5

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 2
Enter element to push: 45
Stack Overflow

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 3
Popped: 35

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 3
Popped: 25

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 1
Stack -
15 <- Top
5

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>
