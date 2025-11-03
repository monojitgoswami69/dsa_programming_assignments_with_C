<h1 align="center">ASSIGNMENT - 8: Stack and Queue with Linked Lists</h1>

<div align="center" id="index">
  <h2>Table of Contents</h2>
</div>

<div align="center">

| **Implementation** |
|---|
| [**#1** Stack using Linked List](#implementation1) |
| [**#2** Circular Queue using Linked List](#implementation2) |

</div>

---

> **Note:** You can write **any one** of the following implementations for your lab work.

---

<a id="implementation1"></a>
## 1. Stack Implementation using Linked List

### Problem Statement
Write a menu driven program in C to implement a stack using single linked list and perform the following operations:
- (a) `isEmpty()` - Check whether the stack is empty or not
- (b) `push()` - Insert an item in the stack
- (c) `pop()` - Delete an item from the stack
- (d) `display()` - Show the entire stack

### Algorithm

1. START
2. Define `struct Node` with:
   - `int data` (stores value)
   - `struct Node *next` (points to next node)
3. Initialize `top = NULL`
4. Display menu with operations (push, pop, peek, display, isEmpty)
5. For **push(top, value)**:
   - Create new node with `malloc()`
   - Set `newNode->data = value`
   - Set `newNode->next = top`
   - Set `top = newNode`
6. For **pop(top)**:
   - If stack is empty, display error
   - Else, store pointer to top node
   - Set `top = top->next`
   - Free old top node
7. For **peek(top)**:
   - If stack is empty, display error
   - Else, print `top->data`
8. For **isEmpty(top)**:
   - Return true if `top == NULL`, else false
9. For **display(top)**:
   - If stack is empty, print message
   - Else, traverse from top, print each node's data
10. Repeat menu until user chooses to quit
11. Free all nodes before exit
12. STOP

### Source Code

```c
/*
ASSIGNMENT 8:
Problem Statement: Write a menu driven program in C to implement a stack using single linked list and perform the following operations.
(a) isEmpty() is to check whether the stack is empty or not.
(b) push() is to insert an item in the stack.
(c) pop() is to delete an item from the stack.
(d) display() is to show the entire stack.
*/

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

void push(int x) {
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
### Sample Output

```
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

Selection: 3
Popped: 20

Selection: 3
Popped: 10

Selection: 3
Stack Underflow

Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>

<a id="implementation2"></a>
## 2. Circular Queue Implementation using Linked List

### Problem Statement
Write a menu driven program in C to implement a queue using single linked list and perform the following operations:
- (a) `isEmpty()` - Check whether the queue is empty or not
- (b) `insert()` - Insert an item in the queue
- (c) `del()` - Delete an item from the queue
- (d) `display()` - Show the entire queue

### Algorithm

1. START
2. Define structures:
   - `NodeStruct`: Contains `data` and `next`
   - `QueueStruct`: Contains `rear`, `size`, `capacity`
3. Initialize queue: `rear = NULL`, `size = 0`
4. Accept capacity from user
5. For **isEmpty()**:
   - Return `rear == NULL`
6. For **isFull()**:
   - Return `size == capacity`
7. For **enqueue(data)**:
   - Check if `isFull()` - display "Queue Overflow"
   - Create newNode with `malloc()`
   - **Case 1: Empty queue**
     - Set `newNode->next = newNode` (circular)
     - Set `rear = newNode`
   - **Case 2: Non-empty queue**
     - Set `newNode->next = rear->next` (front)
     - Set `rear->next = newNode`
     - Update `rear = newNode`
   - Increment size
8. For **dequeue()**:
   - Check if `isEmpty()` - display "Queue Underflow"
   - Get front: `front = rear->next`
   - **Case 1: Single element**
     - Free front and set `rear = NULL`
   - **Case 2: Multiple elements**
     - Update `rear->next = front->next`
     - Free front
   - Decrement size
9. For **display()**:
   - Start from front (`rear->next`)
   - Use do-while to traverse circular list
   - Print until back to front
10. For **peek()**:
   - Display front: `rear->next->data`
   - Display rear: `rear->data`
11. On exit, free all nodes
12. STOP

### Source Code

```c
/*
ASSIGNMENT 8:
Problem Statement: Write a menu driven program in C to implement a queue using single linked list and perform the following operations.
(a) isEmpty() is to check whether the queue is empty or not.
(b) insert() is to insert an item in the queue.
(c) del() is to delete an item from the queue.
(d) display() is to show the entire queue.
*/

#include <stdio.h>
#include <stdlib.h>

struct NodeStruct {
    int data;
    struct NodeStruct *next;
};

struct QueueStruct {
    struct NodeStruct *rear;
    int size;
    int capacity;
};

typedef struct NodeStruct Node;
typedef struct QueueStruct Queue;

Queue queue;

int isEmpty() {
    return queue.rear == NULL;
}

int isFull() {
    return queue.size == queue.capacity;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow - cannot enqueue %d\n", data);
        return;
    }
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed - cannot enqueue %d\n", data);
        return;
    }
    
    newNode->data = data;
    
    if (isEmpty()) {
        newNode->next = newNode;
        queue.rear = newNode;
    } else {
        newNode->next = queue.rear->next;
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
    
    queue.size++;
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow - cannot dequeue\n");
        return;
    }
    
    Node *front = queue.rear->next;
    printf("Dequeued: %d\n", front->data);
    
    if (queue.size == 1) {
        free(front);
        queue.rear = NULL;
    } else {
        queue.rear->next = front->next;
        free(front);
    }
    queue.size--;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue contents: Front -> ");
    Node *current = queue.rear->next;
    
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue.rear->next);
    
    printf("<- Rear\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty - cannot peek\n");
        return;
    }
    printf("Front: %d\n", queue.rear->next->data);
    printf("Rear: %d\n", queue.rear->data);
}

int main() {
    int capacity, choice, data;
    
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);
    
    if (capacity <= 0) {
        printf("Invalid queue capacity\n");
        return 1;
    }
    
    queue.rear = NULL;
    queue.size = 0;
    queue.capacity = capacity;
    
    while (1) {
        printf("\n=== Circular Queue Operations ===\n");
        printf("1. Enqueue(Insert)\n");
        printf("2. Dequeue(Remove)\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Selection: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                if (!isEmpty()) {
                    Node *current = queue.rear->next;
                    Node *temp;
                    int count = queue.size;
                    
                    for (int i = 0; i < count; i++) {
                        temp = current;
                        current = current->next;
                        free(temp);
                    }
                    
                    queue.rear = NULL;
                    queue.size = 0;
                }
                return 0;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
    
    return 0;
}
```

### Sample Output

```
Enter queue capacity: 5

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 100
Enqueued: 100

Selection: 1

Enter element to enqueue: 200
Enqueued: 200

Selection: 1

Enter element to enqueue: 300
Enqueued: 300

Selection: 3

Queue contents: Front -> 100 200 300 <- Rear

Selection: 4

Front: 100
Rear: 300

Selection: 2

Dequeued: 100

Selection: 3

Queue contents: Front -> 200 300 <- Rear

Selection: 1

Enter element to enqueue: 400
Enqueued: 400

Selection: 1

Enter element to enqueue: 500
Enqueued: 500

Selection: 1

Enter element to enqueue: 600
Enqueued: 600

Selection: 3

Queue contents: Front -> 200 300 400 500 600 <- Rear

Selection: 1

Enter element to enqueue: 700
Queue Overflow - cannot enqueue 700

Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>
