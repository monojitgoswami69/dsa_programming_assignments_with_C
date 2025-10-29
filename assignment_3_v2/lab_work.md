<h1 align="center">ASSIGNMENT - 3 (V2): Circular Queue Implementation</h1>

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
Write a menu driven program in C to implement a Circular Queue using array and perform the following operations.
- (a) `isFull()` function to check whether the Circular Queue is full or not.
- (b) `isEmpty()` function to check whether the Circular Queue is empty or not.
- (c) `insert(item)` function to insert an element item in the Circular Queue.
- (d) `delete()` function to read and remove an element from the Circular Queue.
- (e) `display()` function to display the entire Circular Queue.

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
   - If `isEmpty()` returns 1 (queue empty), return 0 (not full)
   - Else, check condition: `(rear + 1) % size == front % size`
   - This detects if next position after rear wraps around to front
   - If true, return 1 (queue is full)
   - Else, return 0 (queue has space)
10. **For enqueue(data) operation**:
    - Call `isFull()` to check queue status
    - If full, display "Queue Overflow" and return
    - Else:
      * Call `isEmpty()` to check if queue is empty
      * If empty (`front == -1`):
        - Initialize: `front = 0`, `rear = -1`
      * Increment rear: `rear++`
      * Insert element with wraparound: `queue[rear % size] = data`
      * The modulo operation wraps index when `rear >= size`
      * Display success message
11. **For dequeue() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue Underflow" and return
    - Else:
      * Retrieve element with wraparound: `element = queue[front % size]`
      * Display element
      * Check if this is the last element: `front == rear`
        - If yes, reset queue: `front = -1`, `rear = -1`
        - Else, increment front: `front++`
      * Note: Modulo in future accesses handles wraparound
12. **For display() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue is empty"
    - Else:
      * Display "Queue contents: Front -> "
      * Traverse from `i = front` to `i = rear`:
        - Print element with wraparound: `queue[i % size]`
      * Display " <- Rear"
      * Modulo ensures correct index even when front/rear > size
13. **For peek() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue is empty - cannot peek"
    - Else:
      * Display front element: `queue[front % size]`
      * Display rear element: `queue[rear % size]`
14. Repeat menu until user chooses to exit
15. STOP

**Key Circular Queue Concepts:**
- **Wraparound**: Using modulo operator (`% size`) allows indices to wrap to beginning
- **No Space Wastage**: Unlike linear queue, freed positions can be reused
- **Full Condition**: `(rear + 1) % size == front % size` (not `rear == size - 1`)
- **Empty Condition**: `front == -1` (both front and rear are -1 initially)
- **Circular Nature**: After dequeue, freed space at front can be used later
- **Example**: In size 5, after rear reaches 4, next insertion goes to index 0

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
    return (rear + 1) % size == front % size;
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
    rear++;
    queue[rear % size] = data;
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow - cannot dequeue\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front % size]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
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
        printf("%d ", queue[i % size]);
    }
    printf("<- Rear\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty - cannot peek\n");
        return;
    }
    printf("Front: %d\n", queue[front % size]);
    printf("Rear: %d\n", queue[rear % size]);
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
Enter queue size (max 100): 5

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 10
Enqueued: 10

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 20
Enqueued: 20

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 30
Enqueued: 30

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 40
Enqueued: 40

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 50
Enqueued: 50

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 10 20 30 40 50 <- Rear

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 60
Queue Overflow - cannot enqueue 60

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 2

Dequeued: 10

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 2

Dequeued: 20

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 30 40 50 <- Rear

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 60
Enqueued: 60

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 70
Enqueued: 70

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 30 40 50 60 70 <- Rear

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 4

Front: 30
Rear: 70

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 5
```

**Demonstration of Circular Behavior:**
```
Initial State (Size = 5):
Indices: [0] [1] [2] [3] [4]
Queue:   [ ] [ ] [ ] [ ] [ ]
front = -1, rear = -1

After enqueuing 10, 20, 30, 40, 50:
Indices: [0]  [1]  [2]  [3]  [4]
Queue:   [10] [20] [30] [40] [50]
         ↑                    ↑
       front                rear
front = 0, rear = 4 (FULL)

After dequeuing 10, 20:
Indices: [0] [1] [2]  [3]  [4]
Queue:   [ ] [ ] [30] [40] [50]
                  ↑         ↑
                front     rear
front = 2, rear = 4

After enqueuing 60, 70 (Wraparound!):
Indices: [0]  [1]  [2]  [3]  [4]
Queue:   [60] [70] [30] [40] [50]
          ↑         ↑         
        (wrapped)  front    rear=6 → 6%5=1 (wrapped)
front = 2, rear = 6
Actual positions: front=2, rear wraps to index 1

Display shows: 30 40 50 60 70
(Logically from front=2 to rear=6, using modulo for wraparound)
```

<div align="right"><a href="#index">return to index</a></div><hr>

<a id="implementation2"></a>
## 2. Circular Queue Implementation - Using Structure

### Problem Statement
Write a menu driven program in C to implement a Circular Queue using array encapsulated in a structure and perform the following operations.
- (a) `isFull()` function to check whether the Circular Queue is full or not.
- (b) `isEmpty()` function to check whether the Circular Queue is empty or not.
- (c) `insert(item)` function to insert an element item in the Circular Queue.
- (d) `delete()` function to read and remove an element from the Circular Queue.
- (e) `display()` function to display the entire Circular Queue.

### Algorithm

1. START
2. Define structure `QueueStruct` with four members:
   - `int *data` (dynamic array pointer for queue elements)
   - `int front` (index of front element)
   - `int rear` (index of rear element)
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
9. Display menu with operations and accept user choice
10. **For isEmpty() function**:
    - Check condition: `queue.front == -1`
    - If true, return 1 (queue is empty)
    - Else, return 0 (queue has elements)
11. **For isFull() function**:
    - If `isEmpty()` returns 1, return 0 (empty queue cannot be full)
    - Else, calculate: `(queue.rear + 1) % queue.capacity`
    - Compare with: `queue.front % queue.capacity`
    - If equal, return 1 (queue is full - next position would overwrite front)
    - Else, return 0 (queue has space)
12. **For enqueue(data) operation**:
    - Call `isFull()` to check queue status
    - If full, display "Queue Overflow" and return
    - Else:
      * Call `isEmpty()` to check if queue is empty
      * If empty:
        - Initialize: `queue.front = 0`, `queue.rear = -1`
      * Increment rear: `queue.rear++`
      * Insert element with wraparound: `queue.data[queue.rear % queue.capacity] = data`
      * Modulo ensures index wraps: if rear=4 and capacity=4, (rear+1)%4=0
      * Display success message
13. **For dequeue() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue Underflow" and return
    - Else:
      * Retrieve element: `element = queue.data[queue.front % queue.capacity]`
      * Display element
      * Check if last element: `queue.front == queue.rear`
        - If yes, reset: `queue.front = -1`, `queue.rear = -1`
        - Else, increment: `queue.front++`
      * Modulo in next access handles wraparound automatically
14. **For display() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue is empty"
    - Else:
      * Display "Queue contents: Front -> "
      * Traverse from `i = queue.front` to `i = queue.rear`:
        - Calculate actual index: `actualIndex = i % queue.capacity`
        - Print element: `queue.data[actualIndex]`
      * Display " <- Rear"
15. **For peek() operation**:
    - Call `isEmpty()` to check queue status
    - If empty, display "Queue is empty - cannot peek"
    - Else:
      * Display front: `queue.data[queue.front % queue.capacity]`
      * Display rear: `queue.data[queue.rear % queue.capacity]`
16. **For Exit**:
    - Free allocated memory: `free(queue.data)`
    - Terminate program
17. Repeat menu until user chooses to exit
18. STOP

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
    return (queue.rear + 1) % queue.capacity == queue.front % queue.capacity;
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
    queue.data[queue.rear % queue.capacity] = data;
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow - cannot dequeue\n");
        return;
    }
    printf("Dequeued: %d\n", queue.data[queue.front % queue.capacity]);
    if (queue.front == queue.rear) {
        queue.front = -1;
        queue.rear = -1;
    } else {
        queue.front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: Front -> ");
    for (int i = queue.front; i <= queue.rear; i++) {
        printf("%d ", queue.data[i % queue.capacity]);
    }
    printf("<- Rear\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty - cannot peek\n");
        return;
    }
    printf("Front: %d\n", queue.data[queue.front % queue.capacity]);
    printf("Rear: %d\n", queue.data[queue.rear % queue.capacity]);
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

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 15
Enqueued: 15

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 25
Enqueued: 25

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 35
Enqueued: 35

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 5 15 25 35 <- Rear

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 45
Queue Overflow - cannot enqueue 45

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 2

Dequeued: 5

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 2

Dequeued: 15

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 45
Enqueued: 45

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 55
Enqueued: 55

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 3

Queue contents: Front -> 25 35 45 55 <- Rear

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 4

Front: 25
Rear: 55

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 1

Enter element to enqueue: 65
Queue Overflow - cannot enqueue 65

=== Circular Queue Operations ===
1. Enqueue(Insert)
2. Dequeue(Remove)
3. Display
4. Peek
5. Exit
Selection: 5
```

<div align="right"><a href="#index">return to index</a></div><hr>
