<h1 align="center">ASSIGNMENT - 3: Queue Implementation</h1>

<div align="center" id="index">
  <h2>Table of Contents</h2>
</div>

<div align="center">

| **Implementation** |
|---|
| [**#1** Queue using Array](#implementation1) |
| [**#2** Queue using Structure](#implementation2) |

</div>

---

> ### **Note** 
> - All programs include problem statement, algorithm, source code, and sample outputs
> - **You can write any one of the following implementations** for your lab work

<hr>

<a id="implementation1"></a>
## 1. Queue Implementation - Using Array

### Problem Statement
Write a menu driven program in C to implement a Queue using array and perform the following operations.
- (a) `isFull()` function to check whether the Queue is full or not.
- (b) `isEmpty()` function to check whether the Queue is empty or not.
- (c) `insert(item)` function to insert an element item in the Queue.
- (d) `delete()` function to read and remove an element from the Queue.
- (e) `display()` function to display the entire Queue.

### Algorithm

1. START
2. Declare static array: `int queue[MAX_SIZE]` where MAX_SIZE = 100
3. Initialize `front = -1` (indicates empty queue)
4. Initialize `rear = -1` (indicates empty queue)
5. Accept queue size from user and store in `size`
6. Validate size: `0 < size <= MAX_SIZE`
7. Display menu with operations and accept user choice
8. **For isEmpty() function**:
   - Check condition: `front == -1`
   - If true, return 1 (queue is empty)
   - Else, return 0 (queue has elements)
9. **For isFull() function**:
   - Check condition: `rear == size - 1`
   - If true, return 1 (queue is full)
   - Else, return 0 (queue has space)
10. **For enqueue(data) operation**:
    - Call `isFull()` to check queue status
    - If full, display "Queue Overflow" and return
    - Else:
      * If queue is empty (`front == -1`):
        - Initialize front: `front = 0`
      * Increment rear: `rear++`
      * Insert element: `queue[rear] = data`
      * Display success message
11. **For dequeue() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue Underflow" and return
    - Else:
      * Retrieve and display element: `queue[front]`
      * Check if queue has only one element: `front == rear`
        - If yes, reset queue: `front = -1`, `rear = -1`
        - Else, increment front: `front++`
12. **For display() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue is empty"
    - Else:
      * Display "Queue contents: Front -> "
      * Traverse from `i = front` to `i = rear`:
        - Print each element: `queue[i]`
      * Display " <- Rear"
13. **For peek() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue is empty - cannot peek"
    - Else:
      * Display front element: `queue[front]`
      * Display rear element: `queue[rear]`
14. Repeat menu until user chooses to exit
15. STOP

**Key Points:**
- `front = -1` AND `rear = -1` indicates empty queue
- `rear = size - 1` indicates full queue
- First insertion sets `front = 0`
- When last element removed, reset `front = -1` and `rear = -1`
- Elements are removed from front and added at rear (FIFO)

### Source Code

```c
/*
ASSIGNMENT 3:
Problem Statement: Write a menu driven program in C to implement a Queue using array and perform the following operations.
(a) isFull() function to check whether the Queue is full or not.
(b) isEmpty() function to check whether the Queue is empty or not.
(c) insert(item) function to insert an element item in the Queue.
(d) delete() function to read and remove an element from the Queue.
(e) display() function to display the entire Queue.
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
    return rear == size - 1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow - cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty()) {
        front = 0; 
    }
    rear++;
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
    } 
    else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: Front -> ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
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
        printf("\n=== Queue Operations ===\n");
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
Enter queue size (max 100): 5

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 10
Enqueued: 10

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 20
Enqueued: 20

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 30
Enqueued: 30

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 10 20 30 <- Rear

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 4

Front: 10
Rear: 30

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 2

Dequeued: 10

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 20 30 <- Rear

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 40
Enqueued: 40

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 50
Enqueued: 50

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 60
Enqueued: 60

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 70
Queue Overflow - cannot enqueue 70

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 20 30 40 50 60 <- Rear

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>

<a id="implementation2"></a>
## 2. Queue Implementation - Using Structure

### Problem Statement
Write a menu driven program in C to implement a Queue using array encapsulated in a structure and perform the following operations.
- (a) `isFull()` function to check whether the Queue is full or not.
- (b) `isEmpty()` function to check whether the Queue is empty or not.
- (c) `insert(item)` function to insert an element item in the Queue.
- (d) `delete()` function to read and remove an element from the Queue.
- (e) `display()` function to display the entire Queue.

### Algorithm

1. START
2. Define structure `QueueStruct` with five members:
   - `int *data` (dynamic array pointer for queue elements)
   - `int front` (index of front element)
   - `int rear` (index of rear element)
   - `int size` (current number of elements in queue)
   - `int capacity` (maximum capacity of queue)
3. Create typedef: `typedef struct QueueStruct Queue`
4. Declare global variable: `Queue queue`
5. Accept queue capacity from user
6. Validate capacity: `queue.capacity > 0`
7. Allocate memory for queue array:
   - `queue.data = (int *) malloc(queue.capacity * sizeof(int))`
   - Check if memory allocation successful
8. Initialize queue members:
   - `queue.front = -1` (no front element yet)
   - `queue.rear = -1` (no rear element yet)
   - `queue.size = 0` (no elements in queue)
9. Display menu with operations and accept user choice
10. **For isEmpty() function**:
    - Check condition: `queue.size == 0`
    - If true, return 1 (queue is empty)
    - Else, return 0 (queue has elements)
11. **For isFull() function**:
    - Check condition: `queue.size == queue.capacity`
    - If true, return 1 (queue is full)
    - Else, return 0 (queue has space)
12. **For enqueue(data) operation**:
    - Call `isFull()` to check queue status
    - If full, display "Queue Overflow" and return
    - Else:
      * If queue is empty (`queue.size == 0`):
        - Initialize: `queue.front = 0`, `queue.rear = -1`
      * Increment rear: `queue.rear++`
      * Insert element: `queue.data[queue.rear] = data`
      * Increment size: `queue.size++`
      * Display success message
13. **For dequeue() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue Underflow" and return
    - Else:
      * Retrieve and display element: `queue.data[queue.front]`
      * Increment front: `queue.front++`
      * Decrement size: `queue.size--`
      * If `queue.size == 0` (last element removed):
        - Reset: `queue.front = -1`, `queue.rear = -1`
14. **For display() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue is empty"
    - Else:
      * Display "Queue contents: Front -> "
      * Traverse from `i = queue.front` to `i = queue.rear`:
        - Print each element: `queue.data[i]`
      * Display " <- Rear"
15. **For peek() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue is empty - cannot peek"
    - Else:
      * Display front element: `queue.data[queue.front]`
      * Display rear element: `queue.data[queue.rear]`
16. **For Exit**:
    - Free allocated memory: `free(queue.data)`
    - Terminate program
17. Repeat menu until user chooses to exit
18. STOP

**Advantages of Structure Approach:**
- Tracks size explicitly for accurate isEmpty/isFull checks
- Encapsulates all queue data in one structure
- Can create multiple queue instances easily
- Clear separation between capacity (max) and size (current)
- Better memory management with dynamic allocation

### Source Code

```c
/*
ASSIGNMENT 3:
Problem Statement: Write a menu driven program in C to implement a Queue using array and perform the following operations.
(a) isFull() function to check whether the Queue is full or not.
(b) isEmpty() function to check whether the Queue is empty or not.
(c) insert(item) function to insert an element item in the Queue.
(d) delete() function to read and remove an element from the Queue.
(e) display() function to display the entire Queue.
*/

#include <stdio.h>
#include <stdlib.h>

struct QueueStruct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
};

typedef struct QueueStruct Queue;

Queue queue;

int isEmpty() {
    return queue.size == 0;
}

int isFull() {
    return queue.size == queue.capacity;
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
    queue.rear++;
    queue.data[queue.rear] = data;
    queue.size++;
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow - cannot dequeue\n");
        return;
    }
    printf("Dequeued: %d\n", queue.data[queue.front]);
    queue.front++;
    queue.size--;
    
    if (queue.size == 0) {
        queue.front = -1;
        queue.rear = -1;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: Front -> ");
    for (int i = queue.front; i <= queue.rear; i++) {
        printf("%d ", queue.data[i]);
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
    queue.size = 0;
    queue.capacity = capacity;
    
    while (1) {
        printf("\n=== Queue Operations ===\n");
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

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 5
Enqueued: 5

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 15
Enqueued: 15

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 25
Enqueued: 25

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 5 15 25 <- Rear

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 4

Front: 5
Rear: 25

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 35
Enqueued: 35

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 45
Queue Overflow - cannot enqueue 45

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 5 15 25 35 <- Rear

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 2

Dequeued: 5

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 2

Dequeued: 15

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 25 35 <- Rear

=== Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>
