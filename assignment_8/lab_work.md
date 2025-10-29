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

> ### **Note** 
> - All programs include problem statement, algorithm, source code, and sample outputs
> - **You can write any one of the following implementations** for your lab work
> - Linked list implementations eliminate fixed-size limitations

<hr>

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
2. Define `struct stack` with members:
   - `int data`
   - `struct stack *next`
3. Declare `top = NULL` (points to top of stack)
4. For **isEmpty()**:
   - Return `top == NULL`
5. For **push()**:
   - Create newNode using `malloc()`
   - If allocation fails, display "Stack Overflow"
   - Set `newNode->data = value`
   - Set `newNode->next = top`
   - Update `top = newNode`
6. For **pop()**:
   - Check if `isEmpty()` - display "Stack Underflow"
   - Store `temp = top`
   - Update `top = top->next`
   - Display popped value
   - Free temp node
7. For **peek()**:
   - Check if `isEmpty()`
   - Display `top->data`
8. For **display()**:
   - Start from top
   - Traverse and print each node
   - Mark first element as "Top"
9. On exit, free all remaining nodes
10. STOP

**Time Complexity:**
- push(): O(1)
- pop(): O(1)  
- peek(): O(1)
- display(): O(n)

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
Selection: 3
Popped: 20

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 3
Popped: 10

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 3
Stack Underflow

Select operation to perform:
1. View stack
2. Push
3. Pop
4. Peek
5. Exit
Selection: 5
```

**Visual Representation:**
```
Initial: top = NULL

After push(10):
top → [10|NULL]

After push(20):
top → [20|•] → [10|NULL]

After push(30):
top → [30|•] → [20|•] → [10|NULL]
      ↑
     Top

After pop():
top → [20|•] → [10|NULL]
      ↑
     Top
(30 removed)

After pop():
top → [10|NULL]
      ↑
     Top
(20 removed)

After pop():
top = NULL
(10 removed, stack empty)
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

**Key Concept:** Using circular linked list with rear pointer allows O(1) access to both front (rear->next) and rear.

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

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 200
Enqueued: 200

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 300
Enqueued: 300

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 100 200 300 <- Rear

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 4

Front: 100
Rear: 300

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 2

Dequeued: 100

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 200 300 <- Rear

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 400
Enqueued: 400

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 500
Enqueued: 500

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 600
Enqueued: 600

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 200 300 400 500 600 <- Rear

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 700
Queue Overflow - cannot enqueue 700

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 5
```

**Visual Representation:**
```
Initial: rear = NULL

After enqueue(100):
    ┌────┐
    ↓    ↑
[100|•]──┘
    ↑
  rear
(rear->next points to itself, this is the front)

After enqueue(200):
    ┌─────────┐
    ↓         ↑
[100|•]──>[200|•]
  ↑         ↑
front     rear

After enqueue(300):
    ┌──────────────┐
    ↓              ↑
[100|•]─>[200|•]─>[300|•]
  ↑                 ↑
front             rear

After dequeue(): (removed 100)
    ┌─────────┐
    ↓         ↑
[200|•]──>[300|•]
  ↑         ↑
front     rear

After enqueue(400):
    ┌──────────────┐
    ↓              ↑
[200|•]─>[300|•]─>[400|•]
  ↑                 ↑
front             rear

Key: 
- rear pointer maintained
- rear->next gives front
- Last node always points back to first (circular)
```

**Advantages of this Implementation:**
1. ✅ **O(1) Enqueue/Dequeue**: Both operations constant time
2. ✅ **No False Overflow**: Unlike linear queue
3. ✅ **Dynamic Size**: Grows as needed (up to capacity)
4. ✅ **Efficient Space**: Uses only needed memory
5. ✅ **Simple Front Access**: rear->next always gives front

<div align="right"><a href="#index">return to index</a></div><hr>
