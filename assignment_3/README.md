# Queue Data Structure - Complete Guide

## Table of Contents
- [What is a Queue?](#what-is-a-queue)
- [Types of Queue](#types-of-queue)
- [Queue Operations](#queue-operations)
- [Memory Management Approaches](#memory-management-approaches)
- [Implementations in this Repository](#implementations-in-this-repository)
- [Applications](#applications)
- [When to Use Queues](#when-to-use-queues)
- [Best Practices](#best-practices)

## What is a Queue?

A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. This means that the first element added to the queue is the first one to be removed.

<div align="center">
  <img src="queue.png" alt="Queue Data Structure Visualization" />
</div>

### Key Characteristics

| Characteristic | Description | Implication |
|----------------|-------------|-------------|
| **FIFO Ordering** | First element in is first element out | Sequential order processing |
| **Front/Rear Access** | Elements added at rear, removed from front | Controlled access points |
| **Dynamic Size** | Can grow and shrink during execution | Flexible memory usage |
| **Enqueue/Dequeue Operations** | Primary operations for adding/removing | Simple interface |

### Memory Layout

```
Queue Memory (Front to Rear):

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 10  | 20  | 30  |     |     |
        +-----+-----+-----+-----+-----+
          ↑           ↑
        Front       Rear
       (Index 0)   (Index 2)
```

## Types of Queue

Understanding different types of queues is crucial for selecting the right implementation based on your specific requirements and constraints.

### 1. **Linear Queue**

A **Linear Queue** is the simplest form of queue implementation using a static array with front and rear pointers that move in one direction only.

#### Characteristics
- **Fixed Size**: Uses a static array with predetermined maximum capacity
- **Sequential Access**: Elements are added at the rear and removed from the front
- **Simple Implementation**: Straightforward pointer management with basic increment operations
- **One-Direction Movement**: Front and rear pointers only move forward, never backward

#### How Linear Queue Works

**Initial State:**
```
Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  |     |     |     |     |     |
        +-----+-----+-----+-----+-----+
        ↑
    Front/Rear = -1 (Empty)
```

**After Enqueue Operations (10, 20, 30):**
```
Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 10  | 20  | 30  |     |     |
        +-----+-----+-----+-----+-----+
          ↑            ↑
        Front         Rear
```

#### **Fundamental problem with Linear Queue**

Let's trace through an example with **Queue Size = 5** to demonstrate the problem with linear queues:

**Step 1: Enqueue 3 elements (10, 20, 30)**
```
Mathematical State:
- front = 0, rear = 2
- Elements in queue = rear - front + 1 = 2 - 0 + 1 = 3
- Available space = size - (rear + 1) = 5 - (2 + 1) = 2

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 10  | 20  | 30  |     |     |
        +-----+-----+-----+-----+-----+
          ↑            ↑
        Front         Rear
```

**Step 2: Dequeue 2 elements (remove 10, 20)**
```
Mathematical State After 1st Dequeue:
- front = 1, rear = 2
- Elements in queue = 2 - 1 + 1 = 2

Mathematical State After 2nd Dequeue:
- front = 2, rear = 2  
- Elements in queue = 2 - 2 + 1 = 1

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | XX  | XX  | 30  |     |     |
        +-----+-----+-----+-----+-----+
                       ↑     
                   Front/Rear
```

**Step 3: Attempt to Enqueue 2 more elements (40, 50)**

**Enqueue 40:**
```
- Check: rear + 1 < size → 2 + 1 < 5 → 3 < 5 ✓ (Success)
- rear = rear + 1 = 2 + 1 = 3
- queue[3] = 40

Mathematical State:
- front = 2, rear = 3
- Elements in queue = 3 - 2 + 1 = 2

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | XX  | XX  | 30  | 40  |     |
        +-----+-----+-----+-----+-----+
                      ↑      ↑
                    Front   Rear
```

**Enqueue 50:**
```
- Check: rear + 1 < size → 3 + 1 < 5 → 4 < 5 ✓ (Success)
- rear = rear + 1 = 3 + 1 = 4
- queue[4] = 50

Mathematical State:
- front = 2, rear = 4
- Elements in queue = 4 - 2 + 1 = 3
- Available space = 0

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | XX  | XX  | 30  | 40  | 50  |
        +-----+-----+-----+-----+-----+
                       ↑           ↑
                     Front        Rear
```

**Step 4: Attempt to Enqueue 60 (FALSE OVERFLOW CONDITION)**
```
Enqueue 60:
- Check: rear + 1 < size → 4 + 1 < 5 → 5 < 5 ✗ (FAIL - Queue Full!)

Mathematical Analysis:
- Actual elements in queue = 3 (only 30, 40, 50)
- Wasted space = 2 positions (indices 0, 1)
- Utilization = 3/5 = 60% (40% space wasted!)
- False overflow occurs despite having only 3/5 positions used

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | XX  | XX  | 30  | 40  | 50  |
        +-----+-----+-----+-----+-----+
                        ↑           ↑
                      Front       Rear

[ERROR: Queue reports "FULL" but only 60% utilized!]
```

#### **The Space Wastage Problem**

The mathematical analysis reveals the fundamental flaw in linear queues:

**Mathematical Formula for Space Wastage:**
```
Wasted Space = front (number of dequeued positions)
Effective Capacity = size - front
Space Utilization = (rear - front + 1) / size * 100%
Waste Percentage = (front / size) * 100%
```

**In our example:**
- Wasted Space = 2 positions
- Effective Capacity = 5 - 2 = 3 positions  
- Space Utilization = (4 - 2 + 1) / 5 = 60%
- Waste Percentage = (2 / 5) = 40%

This leads to:
- **False Overflow**: Queue reports "full" when `rear == size-1`, regardless of actual utilization
- **Memory Inefficiency**: Up to `(size-1)/size * 100%` space can be wasted
- **Reduced Capacity**: Effective queue size becomes `size - front` after operations

### 2. **Potential Solutions Analysis**

Now we need to think: **How can we fix this space wastage problem?**

#### Solution 1: **Shift Elements Left (Modified Linear Queue)**

One approach is to shift all remaining elements to the left every time we perform a dequeue operation.

#### **Mathematical Step-by-Step Analysis**

Let's trace through the same example with **Queue Size = 5** using the shifting approach:

**Step 1: Initial State - Empty Queue**
```
Mathematical State:
- front = -1, rear = -1 (empty queue)
- Elements in queue = 0
- Shift operations performed = 0

Visual State:
Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  |     |     |     |     |     |
        +-----+-----+-----+-----+-----+
```

**Step 2: Enqueue 4 elements (10, 20, 30, 40)**
```
Mathematical State:
- front = 0, rear = 3
- Elements in queue = rear - front + 1 = 3 - 0 + 1 = 4
- Total enqueue operations = 4

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 10  | 20  | 30  | 40  |     |
        +-----+-----+-----+-----+-----+
          ↑                 ↑
        Front              Rear
```

**Step 3: Dequeue 1st element (remove 10) + Shift Left**
```
Mathematical Dequeue Process:
1. Remove element at front: queue[0] = 10 (removed)
2. Shift all remaining elements left by 1 position:
   - queue[0] = queue[1] = 20
   - queue[1] = queue[2] = 30  
   - queue[2] = queue[3] = 40
3. Update pointers: rear = rear - 1 = 3 - 1 = 2

Shift Cost Analysis:
- Elements to shift = rear - front = 3 - 0 = 3 elements
- Shift operations = 3 (each element moved once)
- Time complexity for this dequeue = O(3) = O(n)

Mathematical State After Shift:
- front = 0, rear = 2
- Elements in queue = 2 - 0 + 1 = 3
- Total shift operations performed = 3

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 20  | 30  | 40  |     |     |
        +-----+-----+-----+-----+-----+
          ↑           ↑
        Front        Rear
                   
[All elements shifted left - No space wastage]
```

**Step 4: Dequeue 2nd element (remove 20) + Shift Left**
```
Mathematical Dequeue Process:
1. Remove element at front: queue[0] = 20 (removed)
2. Shift remaining elements left:
   - queue[0] = queue[1] = 30
   - queue[1] = queue[2] = 40
3. Update pointers: rear = rear - 1 = 2 - 1 = 1

Shift Cost Analysis:
- Elements to shift = rear - front = 2 - 0 = 2 elements
- Shift operations = 2
- Time complexity for this dequeue = O(2) = O(n)

Mathematical State:
- front = 0, rear = 1
- Elements in queue = 1 - 0 + 1 = 2
- Total shift operations performed = 3 + 2 = 5

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 30  | 40  |     |     |     |
        +-----+-----+-----+-----+-----+
          ↑     ↑
        Front Rear
```

**Step 5: Enqueue 3 more elements (50, 60, 70)**
```
Enqueue 50:
- rear = rear + 1 = 1 + 1 = 2
- queue[2] = 50

Enqueue 60:
- rear = rear + 1 = 2 + 1 = 3
- queue[3] = 60

Enqueue 70:
- rear = rear + 1 = 3 + 1 = 4
- queue[4] = 70

Mathematical State:
- front = 0, rear = 4
- Elements in queue = 4 - 0 + 1 = 5 (Queue Full!)
- Available space = 0

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 30  | 40  | 50  | 60  | 70  |
        +-----+-----+-----+-----+-----+
          ↑                       ↑
        Front                   Rear

[Queue Full - 100% space utilization achieved!]
```


#### **Performance Analysis - Modified Linear Queue**

**Mathematical Formulas:**
```
For each dequeue operation:
- Elements to shift = current_size - 1
- Time complexity = O(current_size) = O(n)
- Total shift operations = Σ(elements_shifted) for all dequeues

Space utilization = 100% (no wastage)
Average dequeue time = O(n) where n = average queue size
```

**In our example:**
- Total dequeue operations = 3
- Total shift operations = 3 + 2 + 4 = 9
- Average elements shifted per dequeue = 9/3 = 3
- Space utilization = 100% (optimal)

**Trade-off Analysis:**

**Advantages:**
- **Perfect Space Utilization**: 100% space efficiency, no wastage
- **No False Overflow**: Queue can always use full capacity
- **Predictable Behavior**: front always starts at index 0

**Disadvantages:**
- **Time Complexity Degradation**: Dequeue becomes O(n) instead of O(1)
- **Performance Impact**: Each dequeue requires n-1 shift operations
- **Scalability Issues**: Performance degrades linearly with queue size
- **CPU Intensive**: High computational cost for frequent dequeue operations

**Performance Comparison Summary:**

| Queue Type | Enqueue | Dequeue | Space Efficiency | Trade-off |
|------------|---------|---------|------------------|-----------|
| **Standard Linear** | O(1) | O(1) | 100-0% (degrades with dequeues) | Fast operations, space wastage |
| **Modified Linear** | O(1) | O(n) | 100% (optimal) | Perfect space, slow dequeue |

**Space Efficiency Analysis:**
```
Formula: Space Efficiency = ((rear - front + 1) / size) × 100%

Linear Queue Efficiency Range:
• Best Case:  100% (no dequeues performed)
• Worst Case: ~0%  (dequeued all but one element)  
• Average:    Depends on dequeue/enqueue operation ratio
```

#### Solution 2: **Circular Queue Approach**

Instead of shifting elements, we need to think: **How can we reuse the front spaces efficiently?**

The answer is to make the queue **circular** - when rear reaches the end, it wraps around to the beginning if front spaces are available.

### 3. **Circular Queue**

A **Circular Queue** treats the array as a circular structure where the rear can wrap around to the beginning, effectively reusing the spaces left by dequeued elements.

#### Characteristics
- **Wraparound Capability**: Rear pointer wraps to index 0 when it reaches the end
- **Space Efficiency**: No space wastage - all positions can be reused
- **Modulo Arithmetic**: Uses `%` operator for circular index calculation
- **Optimal Performance**: Maintains O(1) for all operations while solving space issues

#### How Circular Queue Works

**Initial State:**
```
Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  |     |     |     |     |     |
        +-----+-----+-----+-----+-----+
        ↑
    Front/Rear = -1 (Empty)
```

#### **Circular Queue Step-by-Step Demonstration**

Let's trace through an example with **Queue Size = 5** to show how circular queues solve the space wastage problem:

**Step 1: Enqueue 5 elements (10, 20, 30, 40, 50)**
```
Mathematical State:
- front = 0, rear = 4
- Elements in queue = 5 (Queue Full!)
- Space utilization = 5/5 = 100%

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 10  | 20  | 30  | 40  | 50  |
        +-----+-----+-----+-----+-----+
          ↑                       ↑
        Front                   Rear
```

**Step 2: Dequeue 2 elements (remove 10, 20)**
```
Mathematical State After Dequeues:
- front = 2, rear = 4
- Elements in queue = 3 (30, 40, 50)
- Available space = 2 positions (indices 0, 1)

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  |     |     | 30  | 40  | 50  |
        +-----+-----+-----+-----+-----+
                      ↑             ↑
                    Front         Rear
```

**Step 3: Enqueue 2 elements (60, 70) with Wraparound**

**Enqueue 60:**
```
Check Condition:
- Check: ((rear + 1) % size) != front → ((4 + 1) % 5) != 2 → 0 != 2 ✓
- rear = (rear + 1) % size = (4 + 1) % 5 = 0
- queue[0] = 60

Mathematical State After Enqueue 60:
- front = 2, rear = 0 (wrapped around!)
- Elements in queue = 4 (30, 40, 50, 60)
- Space utilization = 4/5 = 80%

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 60  |     | 30  | 40  | 50  |
        +-----+-----+-----+-----+-----+
          ↑            ↑           
         Rear        Front        

[First wraparound successful - rear wrapped to index 0]
```

**Enqueue 70:**
```
Check Condition:
- Check: ((rear + 1) % size) != front → ((0 + 1) % 5) != 2 → 1 != 2 ✓  
- rear = (rear + 1) % size = (0 + 1) % 5 = 1
- queue[1] = 70

Mathematical State After Enqueue 70:
- front = 2, rear = 1 (both wrapped around!)
- Elements in queue = 5 (Queue Full again!)
- Space utilization = 5/5 = 100%

Index:    0     1     2     3     4
        +-----+-----+-----+-----+-----+
Queue:  | 60  | 70  | 30  | 40  | 50  |
        +-----+-----+-----+-----+-----+
                ↑      ↑           
               Rear  Front        

[Perfect wraparound complete - 100% space utilization maintained!]
```

#### **Key Circular Queue Operations**

```c
// Circular increment for rear
rear = (rear + 1) % size;

// Circular increment for front  
front = (front + 1) % size;

// Check if queue is full
isFull = ((rear + 1) % size == front);
```

#### **Advantages of Circular Queue**
- **No Space Wastage**: All array positions can be reused efficiently
- **Optimal Performance**: Maintains O(1) time complexity for all operations  
- **Better Memory Utilization**: Maximum capacity is always available
- **Real-world Applicability**: Suitable for production systems

#### **Applications Where Circular Queues Excel**
- **CPU Scheduling**: Round-robin scheduling algorithms
- **Buffer Management**: Circular buffers for streaming data
- **Traffic Light Systems**: Cyclical signal management
- **Producer-Consumer Problems**: Efficient buffer sharing

## Queue Operations

### Core Operations

| Operation | Description | Time Complexity | Space Complexity | Error Condition |
|-----------|-------------|-----------------|------------------|-----------------|
| **Enqueue** | Add element to rear | O(1) | O(1) | Queue Overflow |
| **Dequeue** | Remove and return front element | O(1) - O(n)* | O(1) | Queue Underflow |
| **Front** | View front element without removing | O(1) | O(1) | Empty queue |
| **isEmpty** | Check if queue is empty | O(1) | O(1) | None |
| **isFull** | Check if queue is full | O(1) | O(1) | Fixed-size only |

*Note: O(n) for modified linear queues due to shifting

### Operation Examples

**Quick Reference:**
```
Basic Queue Operations:
enqueue(10): [10]           // front = 0, rear = 0
enqueue(20): [10, 20]       // front = 0, rear = 1  
enqueue(30): [10, 20, 30]   // front = 0, rear = 2
front(): returns 10         // Queue unchanged
dequeue(): returns 10       // Queue: [20, 30], front = 1
dequeue(): returns 20       // Queue: [30], front = 2
```

### Detailed Operation Analysis

> **Note**: For comprehensive operation demonstrations with mathematical analysis and visual examples, refer to the detailed queue type comparisons above. This section provides the technical implementation details and complexity analysis.

#### 1. **Enqueue Operation**

**Implementation varies by queue type:**
- **Linear Queue**: Simple rear increment, may cause false overflow
- **Circular Queue**: Uses modulo arithmetic for wraparound 
- **Modified Linear**: Same as linear, but requires shifting on dequeue

```c
// Linear Queue
void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = element;
}

// Circular Queue  
void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % size;
    queue[rear] = element;
}
```

**Process:**
1. **Check Capacity**: Verify if queue has space for new element
2. **Handle Empty Case**: Set front pointer if queue was empty  
3. **Update Rear**: Move rear pointer (linear increment or circular wraparound)
4. **Insert Element**: Place new element at the rear position

**Key Differences:**
- **Linear**: `rear++` may lead to space wastage 
- **Circular**: `rear = (rear + 1) % size` enables space reuse 

**Time Complexity**: O(1) - Direct array access for all queue types
**Space Complexity**: O(1) - No additional space required

#### 2. **Dequeue Operation**

**Implementation varies significantly by queue type:**
- **Linear/Circular**: Simple pointer advancement  
- **Modified Linear**: Requires element shifting 

```c
// Linear & Circular Queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int element = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;  // Linear: front++, Circular: front = (front + 1) % size
    }
    return element;
}

// Modified Linear Queue (with shifting)
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int element = queue[front];
    // Shift all elements left by one position
    for (int i = front; i < rear; i++) {
        queue[i] = queue[i + 1];
    }
    rear--;
    return element;
}
```

**Process:**
1. **Check Availability**: Verify queue is not empty
2. **Retrieve Element**: Get value at current front position
3. **Update Structure**: 
   - **Linear/Circular**: Advance front pointer
   - **Modified Linear**: Shift all remaining elements left
4. **Return Value**: Provide dequeued element to caller

**Performance Impact:**
- **Linear/Circular**: O(1) - Single pointer update
- **Modified Linear**: O(n) - Must shift n-1 elements 

**Time Complexity**: 
- O(1) for Linear/Circular queues
- O(n) for Modified Linear queues due to shifting overhead
**Space Complexity**: O(1) - No additional space needed

#### 3. **Front/Peek Operation**
```c
int front() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;  // Error value
    }
    return queue[front];
}
```

**Process:**
1. **Validate State**: Check if queue contains elements
2. **Access Element**: Read value at front position
3. **Preserve State**: No modification to queue structure
4. **Return Copy**: Provide element value without removal

**Time Complexity**: O(1) - Single array access
**Space Complexity**: O(1) - Read-only operation

#### 4. **isEmpty Check**
```c
int isEmpty() {
    return front == -1;  // For array implementation
    return rear == NULL; // For linked list implementation
}
```

**Process:**
1. **Compare State**: Check front pointer against empty condition
2. **Return Boolean**: Immediate true/false result

**Why O(1)**: Single comparison operation regardless of queue size

#### 5. **isFull Check (Array-based only)**
```c
int isFull() {
    return rear == size - 1;  // Linear queue
    return (rear + 1) % size == front;  // Circular queue
}
```

**Process:**
1. **Compare Capacity**: Check if rear reached maximum index
2. **Return Status**: Boolean result for capacity check

**Note**: Not applicable for linked list implementations (dynamic size)

### Error Handling Analysis

| Operation | Error Condition | Detection Method | Recovery Action |
|-----------|----------------|------------------|-----------------|
| **Enqueue** | Queue Overflow | `rear >= size-1` or full check | Return error, reject operation |
| **Dequeue** | Queue Underflow | `front == -1` or empty check | Return error value, maintain state |
| **Front** | Empty Queue | `front == -1` or empty check | Return error value, no change |
| **Access** | Invalid Index | Bounds checking | Prevent undefined behavior |

## Memory Management Approaches

### 1. **Array-Based Implementation**
- **Memory**: Static or dynamic arrays with index-based access
- **Storage**: Contiguous memory allocation for queue elements
- **Pointer Management**: Front and rear indices to track queue boundaries
- **Variants**: Can implement linear or circular queue logic
- **Advantages**: 
  - Fast O(1) access time due to cache locality
  - Simple memory layout and pointer arithmetic
  - Predictable memory usage
- **Disadvantages**: 
  - Fixed size (for static arrays)
  - Potential space wastage (linear queues)
  - Memory allocation overhead (dynamic arrays)

### 2. **Structure-Based Implementation**
- **Memory**: Encapsulated data within custom structures using typedef
- **Organization**: Combines queue data, pointers, and metadata in single structure
- **Access Pattern**: Dot notation for member access (e.g., `queue.front`, `queue.rear`)
- **Modularity**: Better code organization and reusability
- **Advantages**:
  - Clean code organization and encapsulation
  - Easy to pass queue as parameter to functions
  - Supports multiple queue instances
  - Better maintainability and debugging
- **Disadvantages**:
  - Slight memory overhead for structure metadata
  - Additional complexity in structure design

### 3. **Linked List Implementation**
- **Memory**: Dynamic node allocation with pointer-based connections
- **Storage**: Non-contiguous memory with each node containing data and next pointer
- **Growth**: Dynamic size expansion limited only by available memory
- **Pointer Management**: Front and rear pointers to first and last nodes
- **Advantages**:
  - No size limitations or memory wastage
  - Efficient memory utilization (allocate only what's needed)
  - No false overflow conditions
  - Flexible memory management
- **Disadvantages**:
  - Additional memory overhead for storing pointers
  - Potential memory fragmentation
  - Cache performance may be lower due to non-contiguous storage
  - More complex memory management (malloc/free)

## Implementations in this Repository

This repository contains comprehensive queue implementations organized into three main categories, each demonstrating different queue behaviors and implementation approaches.

### 🔹 **1. Linear Queue Implementations**

<details>
<summary><strong>🔸 Array-Based Linear Queue</strong></summary>

### Overview
Traditional linear queue implementation using global arrays and simple pointer management.

### Key Features
- Global variables: `int queue[MAX_SIZE]`, `int front`, `int rear`
- Fixed maximum capacity with simple bounds checking
- Direct array indexing for element access
- Demonstrates the classic space wastage problem

### Characteristics
- **Time Complexity**: O(1) for all operations
- **Space Efficiency**: Degrades with dequeue operations (can waste up to size-1 positions)
- **Use Case**: Educational purposes to understand basic queue concepts and limitations

### Source Code
```c
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

</details>

<details>
<summary><strong>🔸 Structure-Based Linear Queue</strong></summary>

### Overview
Enhanced linear queue using custom structures for better code organization and encapsulation.

### Key Features
- Structure encapsulation: `struct QueueStruct` with typedef
- Organized data members: `data[]`, `front`, `rear`, `size`, `capacity`
- Dot notation access for clean code structure
- Dynamic memory allocation for queue data

### Characteristics
- **Time Complexity**: O(1) for all operations
- **Organization**: Better code modularity and reusability
- **Use Case**: Learning structured programming and data encapsulation

### Source Code
```c
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

</details>

---

### 🔹 **2. Modified Linear Queue Implementations**

<details>
<summary><strong>🔸 Array-Based Modified Linear Queue</strong></summary>

### Overview
Linear queue with element shifting to eliminate space wastage at the cost of performance.

### Key Features
- Traditional array structure with shifting mechanism
- Elements shift left on every dequeue operation
- Achieves 100% space utilization through movement
- Demonstrates trade-off between space and time efficiency

### Characteristics
- **Time Complexity**: Enqueue O(1), Dequeue O(n) due to shifting
- **Space Efficiency**: 100% - no wasted positions
- **Use Case**: Educational demonstration of space-time trade-offs

### Source Code
```c
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
        for (int i = front; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;  
        front = 0;
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
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove with left shift)\n");
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

</details>

<details>
<summary><strong>🔸 Structure-Based Modified Linear Queue</strong></summary>

### Overview
Structured implementation of modified linear queue with organized shifting operations.

### Key Features
- Structure-based design with integrated shifting logic
- Clean separation of shifting operations within methods
- Organized approach to element movement and management
- Better code readability for complex shifting operations

### Characteristics
- **Time Complexity**: Enqueue O(1), Dequeue O(n) with organized shifting
- **Space Efficiency**: 100% with structured code management
- **Use Case**: Learning how to implement complex operations in organized manner

### Source Code
```c
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
    queue.size--;
    
    if (queue.size == 0) {
        queue.front = -1;
        queue.rear = -1;
    } else {
        for (int i = queue.front; i < queue.rear; i++) {
            queue.data[i] = queue.data[i + 1];
        }
        queue.rear--;
        queue.front = 0;
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
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove with left shift)\n");
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

</details>

---

### 🔹 **3. Circular Queue Implementations**

<details>
<summary><strong>🔸 Array-Based Circular Queue</strong></summary>

### Overview
Optimal queue implementation using modulo arithmetic to achieve perfect space utilization.

### Key Features
- Circular array with wraparound using `(index) % size`
- No space wastage - all positions can be reused
- Efficient O(1) operations with optimal memory usage
- Advanced pointer management with circular logic

### Characteristics
- **Time Complexity**: O(1) for all operations
- **Space Efficiency**: 100% - no wasted memory
- **Use Case**: Production systems requiring optimal performance

### Source Code
```c
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

</details>

<details>
<summary><strong>🔸 Structure-Based Circular Queue</strong></summary>

### Overview
Combines circular queue efficiency with structured programming benefits.

### Key Features
- Structure-based organization with circular logic
- Encapsulated circular operations within clean interface
- Memory allocation flexibility with structured design
- Best of both worlds: efficiency + organization

### Characteristics
- **Time Complexity**: O(1) for all operations  
- **Space Efficiency**: 100% with organized code structure
- **Use Case**: Large projects requiring both performance and maintainability

### Source Code
```c
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

</details>

<details>
<summary><strong>🔸 Linked List-Based Circular Queue</strong></summary>

### Overview
Dynamic circular queue using linked list structure for unlimited growth potential.

### Key Features
- Node-based circular structure with `next` pointers
- Dynamic memory allocation - no size limitations
- Circular linked list with rear pointer management
- Self-referencing nodes for circular behavior

### Characteristics
- **Time Complexity**: O(1) for all operations
- **Space Efficiency**: 100% + dynamic growth capability
- **Use Case**: Applications with unpredictable queue size requirements

### Source Code
```c
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

</details>

---

### Memory Usage Analysis

```c
// Memory footprint comparison
Linear Array:    size * sizeof(int) + 2 pointers (may waste space)
Circular Array:  size * sizeof(int) + 2 pointers (no space waste)
Linked List:     n * (sizeof(int) + sizeof(pointer))
Structure-based: size * sizeof(int) + struct overhead
```

### Performance Benchmarks

- **Circular Array**: Fastest due to contiguous memory and no space wastage
- **Linear Array**: Fast but space inefficient after many operations
- **Structure-based**: Similar to array-based with minimal overhead
- **Linked List**: Slightly slower due to dynamic allocation and pointer traversal

## Applications

### System Programming
- **Process Scheduling**: CPU scheduling and task management
- **Buffer Management**: I/O buffering and data streaming
- **Print Queue**: Document printing and spooling systems

### Algorithm Implementation
- **Breadth-First Search**: Graph traversal algorithms
- **Level-order Traversal**: Tree traversal operations
- **Cache Implementation**: LRU and FIFO cache policies

### Application Development
- **Event Handling**: GUI event processing
- **Request Processing**: Web server request queues
- **Simulation Systems**: Modeling waiting lines and service systems

## When to Use Queues

### **Ideal Use Cases**
- **Sequential processing** where order matters (FIFO)
- **Resource scheduling** and task management
- **Buffer implementation** for data streams
- **Breadth-first algorithms** and level-order processing
- **Producer-consumer scenarios** with ordered processing

### **Avoid When**
- **Random access** to elements is needed
- **LIFO processing** is required (use stacks)
- **Priority-based processing** is needed (use priority queues)
- **Frequent search operations** within the queue

## Best Practices

### Implementation Guidelines
- **Choose circular queues** for production systems to avoid space wastage
- **Use linear queues** only for educational purposes or simple scenarios
- **Initialize pointers properly**: Set front and rear to appropriate initial values
- **Handle memory carefully**: Free allocated memory in dynamic implementations

### Error Handling
- **Always check bounds**: Prevent overflow and underflow conditions
- **Provide clear error messages**: Help users understand queue state
- **Validate input parameters**: Check for null pointers and invalid sizes
- **Handle memory allocation failures**: Check malloc() return values

### Performance Optimization
- **Prefer circular arrays** for fixed-size requirements with optimal performance
- **Use linked lists** only when size is highly unpredictable
- **Consider cache performance**: Contiguous memory access patterns are faster
- **Monitor queue utilization**: Track peak usage for capacity planning

### Code Organization
- **Encapsulate data**: Use structures for better organization and reusability
- **Separate concerns**: Keep queue operations independent from business logic
- **Provide consistent interfaces**: Standard function naming and parameter patterns
- **Test edge cases**: Empty queues, full queues, and single-element scenarios
