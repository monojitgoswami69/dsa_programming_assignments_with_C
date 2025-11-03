<h1 align="center">ASSIGNMENT - 3 (v2): Circular Queue Implementation</h1>

<div align="center" id="index">
  <h2>Table of Contents</h2>
</div>

<div align="center">

| **Implementation** |
|---|
| [**#1** Circular Queue using Array](#implementation1) |
| [**#2** Circular Queue using Structure](#implementation2) |

</div>

---

> **Note:** You can write **any one** of the following implementations for your lab work.

---

<a id="implementation1"></a>
## 1. Circular Queue Implementation - Using Array

### Problem Statement
Write a menu driven program in C to implement a **Circular Queue** using array and perform the following operations.
- (a) `isFull()` function to check whether the Circular Queue is full or not.
- (b) `isEmpty()` function to check whether the Circular Queue is empty or not.
- (c) `enqueue(item)` function to insert an element item in the Circular Queue.
- (d) `dequeue()` function to read and remove an element from the Circular Queue.
- (e) `display()` function to display the entire Circular Queue.

### Algorithm

1. START
2. Declare static array: `int queue[MAX_SIZE]`
3. Initialize `front = -1` and `rear = -1`
4. Accept queue size from user and store in `size`
5. Display menu with operations
6. **For isEmpty() function**:
   - Return `front == -1`
7. **For isFull() function**:
   - Return `(rear + 1) % size == front`
8. **For enqueue(data) operation**:
    - If `isFull()`, display "Queue Overflow" and return
    - If `isEmpty()`, set `front = 0` and `rear = -1`
    - Update rear: `rear = (rear + 1) % size`
    - Insert element: `queue[rear] = data`
9. **For dequeue() operation**:
    - If `isEmpty()`, display "Queue Underflow" and return
    - Retrieve and display element: `queue[front]`
    - If `front == rear` (only one element), reset queue: `front = -1`, `rear = -1`
    - Else, update front: `front = (front + 1) % size`
10. **For display() operation**:
    - If `isEmpty()`, display "Queue is empty"
    - Else:
      * Traverse from `i = front` up to `rear`, handling wraparound.
      * A simple loop from `front` to `rear` will not work if `rear < front`.
      * Correct traversal: `for (int i = front; i != rear; i = (i + 1) % size)` then print `queue[rear]`.
11. Repeat menu until user exits
12. STOP

### Source Code

```c
/*
ASSIGNMENT 3:
Problem Statement: Write a menu driven program in C to implement a Circular Queue using array and perform the following operations.
(a) isFull() function to check whether the Circular Queue is full or not.
(b) isEmpty() function to check whether the Circular Queue is empty or not.
(c) insert(item) function to insert an element item in the Circular Queue.
(d) delete() function to read and remove an element from the Circular Queue.
(e) display() function to display the entire Circular Queue.
*/

#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int size = 0;

int isEmpty() {
    return front == -1;
}

int isFull() {
    if (isEmpty()) return 0;
    return (rear + 1) % size == front;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow - cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = -1;
    }
    rear = (rear + 1) % size;
    queue[rear] = data;
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow - cannot dequeue\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % size;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: Front -> ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % size;
    }
    printf("<- Rear\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty - cannot peek\n");
        return;
    }
    printf("Front: %d\n", queue[front]);
    printf("Rear: %d\n", queue[rear]);
}

int main() {
    int choice, data;
    printf("Enter queue size (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid queue size. Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }
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
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: return 0;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
}
```

### Sample Output

```
Enter queue size (max 100): 4

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 10
Enqueued: 10

Selection: 1

Enter element to enqueue: 20
Enqueued: 20

Selection: 1

Enter element to enqueue: 30
Enqueued: 30

Selection: 1

Enter element to enqueue: 40
Enqueued: 40

Selection: 3

Queue contents: Front -> 10 20 30 40 <- Rear

Selection: 1

Enter element to enqueue: 50
Queue Overflow - cannot enqueue 50

Selection: 2

Dequeued: 10

Selection: 2

Dequeued: 20

Selection: 3

Queue contents: Front -> 30 40 <- Rear

Selection: 1

Enter element to enqueue: 50
Enqueued: 50

Selection: 1

Enter element to enqueue: 60
Enqueued: 60

Selection: 3

Queue contents: Front -> 30 40 50 60 <- Rear

Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>

<a id="implementation2"></a>
## 2. Circular Queue Implementation - Using Structure

### Problem Statement
Write a menu driven program in C to implement a **Circular Queue** using an array encapsulated in a structure and perform the following operations.
- (a) `isFull()` function to check whether the Circular Queue is full or not.
- (b) `isEmpty()` function to check whether the Circular Queue is empty or not.
- (c) `enqueue(item)` function to insert an element item in the Circular Queue.
- (d) `dequeue()` function to read and remove an element from the Circular Queue.
- (e) `display()` function to display the entire Circular Queue.

### Algorithm

1. START
2. Define structure `QueueStruct` with members: `*data`, `front`, `rear`, `capacity`.
3. Create typedef: `typedef struct QueueStruct Queue`.
4. Declare global variable: `Queue queue`.
5. Accept queue capacity from user.
6. Allocate memory for `queue.data` of size `capacity`.
7. Initialize `queue.front = -1`, `queue.rear = -1`, `queue.capacity`.
8. Display menu with operations.
9. **For isEmpty() function**:
   - Return `queue.front == -1`.
10. **For isFull() function**:
    - Return `(queue.rear + 1) % queue.capacity == queue.front`.
11. **For enqueue(data) operation**:
    - If `isFull()`, display "Queue Overflow" and return.
    - If `isEmpty()`, set `queue.front = 0` and `queue.rear = -1`.
    - Update rear: `queue.rear = (queue.rear + 1) % queue.capacity`.
    - Insert element: `queue.data[queue.rear] = data`.
12. **For dequeue() operation**:
    - If `isEmpty()`, display "Queue Underflow" and return.
    - Retrieve and display element: `queue.data[queue.front]`.
    - If `queue.front == queue.rear`, reset queue: `queue.front = -1`, `queue.rear = -1`.
    - Else, update front: `queue.front = (queue.front + 1) % queue.capacity`.
13. **For display() operation**:
    - If `isEmpty()`, display "Queue is empty".
    - Else, traverse from `front` to `rear` handling wraparound and print elements.
14. **For Exit**:
    - Free allocated memory: `free(queue.data)`.
    - Terminate.
15. Repeat menu until user chooses to exit.
16. STOP

### Source Code

```c
/*
ASSIGNMENT 3:
Problem Statement: Write a menu driven program in C to implement a Circular Queue using array and perform the following operations.
(a) isFull() function to check whether the Circular Queue is full or not.
(b) isEmpty() function to check whether the Circular Queue is empty or not.
(c) insert(item) function to insert an element item in the Circular Queue.
(d) delete() function to read and remove an element from the Circular Queue.
(e) display() function to display the entire Circular Queue.
*/

#include <stdio.h>
#include <stdlib.h>

struct QueueStruct {
    int *data;
    int front;
    int rear;
    int capacity;
};

typedef struct QueueStruct Queue;

Queue queue;

int isEmpty() {
    return queue.front == -1;
}

int isFull() {
    if (isEmpty()) return 0;
    return (queue.rear + 1) % queue.capacity == queue.front;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow - cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty()) {
        queue.front = 0;
        queue.rear = -1;
    }
    queue.rear = (queue.rear + 1) % queue.capacity;
    queue.data[queue.rear] = data;
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow - cannot dequeue\n");
        return;
    }
    printf("Dequeued: %d\n", queue.data[queue.front]);
    if (queue.front == queue.rear) {
        queue.front = -1;
        queue.rear = -1;
    } else {
        queue.front = (queue.front + 1) % queue.capacity;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: Front -> ");
    int i = queue.front;
    while (1) {
        printf("%d ", queue.data[i]);
        if (i == queue.rear) {
            break;
        }
        i = (i + 1) % queue.capacity;
    }
    printf("<- Rear\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty - cannot peek\n");
        return;
    }
    printf("Front: %d\n", queue.data[queue.front]);
    printf("Rear: %d\n", queue.data[queue.rear]);
}

int main() {
    int capacity, choice, data;
    
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);
    
    if (capacity <= 0) {
        printf("Invalid queue capacity\n");
        return 1;
    }
    
    queue.data = (int*)malloc(capacity * sizeof(int));
    if (queue.data == NULL) {
        printf("Memory allocation failed for queue data\n");
        return 1;
    }
    
    queue.front = -1;
    queue.rear = -1;
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
                free(queue.data);
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
Enter queue capacity: 4

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 5
Enqueued: 5

Selection: 1

Enter element to enqueue: 15
Enqueued: 15

Selection: 1

Enter element to enqueue: 25
Enqueued: 25

Selection: 1

Enter element to enqueue: 35
Enqueued: 35

Selection: 3

Queue contents: Front -> 5 15 25 35 <- Rear

Selection: 1

Enter element to enqueue: 45
Queue Overflow - cannot enqueue 45

Selection: 2

Dequeued: 5

Selection: 2

Dequeued: 15

Selection: 3

Queue contents: Front -> 25 35 <- Rear

Selection: 1

Enter element to enqueue: 45
Enqueued: 45

Selection: 3

Queue contents: Front -> 25 35 45 <- Rear

Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>
