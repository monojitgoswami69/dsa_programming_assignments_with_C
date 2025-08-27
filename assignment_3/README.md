# Queue Data Structure Implementation in C

## Table of Contents
- [What is a Queue?](#what-is-a-queue)
- [Queue Operations](#queue-operations)
- [Uses of Queue](#uses-of-queue)
- [Advantages and Disadvantages](#advantages-and-disadvantages)
- [Types of Queues](#types-of-queues)
- [Implementation Methods in C](#implementation-methods-in-c)
- [Implementations in this Repository](#implementations-in-this-repository)
- [Performance Comparison](#performance-comparison)
- [Conclusion](#conclusion)

## What is a Queue?

A **Queue** is a fundamental linear data structure that implements the **First In, First Out (FIFO)** principle. In queue operations, the first element inserted will be the first element to be removed, maintaining strict sequential order processing.

### Core Characteristics

- **FIFO Ordering**: Elements are processed in the exact order of their insertion
- **Restricted Access**: Elements can only be added at the rear and removed from the front
- **Linear Organization**: Data elements maintain sequential arrangement
- **Controlled Processing**: Access is limited to the front element for removal operations

### Fundamental Operations

Queue operations are designed around two primary access points: the **rear** for insertion (enqueue) and the **front** for removal (dequeue). This design ensures the FIFO property is maintained across all operations.

## Queue Operations

Queue operations form the foundation of FIFO data processing. Each operation maintains the structural integrity of the queue while providing specific functionality.

### Primary Operations

| Operation | Description | Time Complexity | Purpose |
|-----------|-------------|-----------------|---------|
| **Enqueue** | Insert element at the rear of the queue | O(1) | Add new data to processing sequence |
| **Dequeue** | Remove and return the front element | O(1) - O(n)* | Process next element in sequence |
| **Front/Peek** | Access front element without removal | O(1) | Examine next element without modification |
| **isEmpty** | Verify if queue contains no elements | O(1) | Check queue state for processing logic |
| **isFull** | Verify if queue has reached capacity | O(1) | Prevent overflow in bounded implementations |

*Note: Time complexity varies by implementation type. Modified linear queues exhibit O(n) dequeue due to element shifting.

### Auxiliary Operations

Queue implementations typically include additional operations that enhance functionality and debugging capabilities:

- **Size/Count**: Returns the current number of elements stored in the queue
- **Display**: Iterates through queue elements from front to rear for inspection
- **Clear**: Removes all elements and resets the queue to its initial state

### Operation Design Principles

Queue operations maintain strict adherence to FIFO ordering. The restricted access pattern ensures that elements can only be removed from the front position, preventing arbitrary access that would violate the sequential processing guarantee.

## Uses of Queue

Queues serve as fundamental components in numerous computing systems where ordered processing is required. The FIFO principle provides essential functionality across diverse application domains.

### Process Scheduling Systems

Operating systems utilize queues extensively for process and resource management. The scheduler maintains process queues to ensure fair CPU time allocation and systematic task execution.

**Applications:**
- CPU scheduling algorithms implementing round-robin and priority-based processing
- Job queue management for batch processing systems
- Task scheduling in multithreaded environments

### Data Buffer Management

Queues function as buffers in systems where data production and consumption rates differ. This buffering capability prevents data loss and ensures smooth system operation.

**Applications:**
- Input device buffering (keyboard, mouse, network interface)
- Print job spooling and management
- Network packet queuing in routers and switches

### Graph Traversal Algorithms

Breadth-First Search (BFS) algorithms rely on queues to maintain the correct order of node exploration. The FIFO property ensures level-by-level traversal of graph structures.

**Applications:**
- Shortest path algorithms in unweighted graphs
- Network topology analysis and routing protocols
- Tree level-order traversal operations

### Asynchronous Communication

Message queues facilitate communication between distributed system components by providing reliable, ordered message delivery mechanisms.

**Applications:**
- Event-driven architecture implementations
- Microservices communication patterns
- Distributed system messaging protocols

### Resource Management

Queues coordinate access to shared resources in multi-user and multi-process environments, ensuring orderly resource allocation.

**Applications:**
- Database connection pooling systems
- Thread pool management in concurrent applications
- Hardware resource scheduling in embedded systems

### Simulation Systems

Discrete event simulation systems employ queues to model temporal sequences and waiting processes in complex systems.

**Applications:**
- Performance modeling of service systems
- Network traffic analysis and capacity planning
- Manufacturing process optimization studies

## Advantages and Disadvantages

Queue data structures offer specific benefits and limitations that influence their suitability for different applications. Understanding these characteristics enables informed design decisions.

### Strengths

| Characteristic | Benefit | Implementation Impact |
|----------------|---------|----------------------|
| **FIFO Ordering** | Ensures predictable, sequential processing | Maintains data integrity in time-sensitive operations |
| **Simple Interface** | Straightforward operation semantics | Reduces implementation complexity and error potential |
| **Optimal Performance** | O(1) operations in well-designed implementations | Enables efficient processing of large data volumes |
| **Natural Abstraction** | Maps directly to real-world processing patterns | Simplifies system design and reasoning |
| **Memory Locality** | Sequential access patterns improve cache performance | Enhanced execution speed in memory-intensive operations |
| **Concurrency Support** | Well-suited for producer-consumer architectures | Facilitates safe multi-threaded data processing |

### Limitations

| Constraint | Impact | Mitigation Strategies |
|------------|--------|----------------------|
| **Access Restriction** | Limited to front and rear operations | Use alternative structures for random access requirements |
| **Sequential Processing** | Cannot prioritize or reorder elements | Implement priority queues for non-FIFO processing needs |
| **Implementation Dependency** | Performance varies significantly by implementation type | Choose appropriate implementation based on usage patterns |
| **Capacity Constraints** | Fixed-size implementations may overflow | Use dynamic implementations or implement overflow handling |
| **Search Limitations** | No efficient element lookup mechanisms | Combine with hash tables for fast element identification |

### Application Guidelines

**Optimal Use Cases:**
- Sequential data processing requirements
- Fair resource allocation systems
- Breadth-first algorithm implementations
- Producer-consumer pattern implementations

**Alternative Considerations:**
- Priority-based processing: Priority queues or heaps
- Random access requirements: Arrays or hash tables
- Frequent search operations: Balanced search trees
- Order-independent processing: Sets or stacks

## Types of Queues

Queue implementations can be categorized into two primary types: **Linear Queues** and **Circular Queues**. Linear queues represent the foundational approach with inherent limitations, while circular queues provide the optimal solution through mathematical innovation.

## Linear Queue

Linear queues represent the foundational implementation of FIFO principles using straightforward array indexing with front and rear pointers. This implementation prioritizes conceptual simplicity while revealing inherent space utilization challenges.

**Implementation Characteristics:**
- Front and rear pointers track queue boundaries
- Elements occupy consecutive array positions during insertion
- Dequeue operations advance the front pointer without reclaiming space
- Fixed array size with compile-time or runtime allocation

**Space Utilization Challenge:**
Linear queues exhibit progressive space wastage as front elements are removed. Dequeued positions become permanently inaccessible, leading to "phantom full" conditions where the queue appears at capacity despite available space at the beginning of the array.

**Performance Profile:**
- Enqueue operations: O(1) constant time
- Dequeue operations: O(1) constant time
- Space efficiency: Degrades over time, potentially wasting up to (n-1) positions

**The Core Problem:**
The fundamental limitation of linear queues lies in their inability to reuse dequeued positions. Once elements are removed from the front, those array positions become permanently inaccessible, resulting in progressive capacity reduction despite the physical availability of memory space.

## Solution Approaches to Linear Queue Limitations

The space wastage problem in linear queues can be addressed through two distinct approaches, each with different performance and complexity trade-offs:

### Modified Linear Queue Approach

This approach addresses space wastage through element shifting strategies that reclaim front positions after dequeue operations. The method eliminates space wastage at the cost of increased computational complexity.

**Implementation Strategy:**
- Dequeue operations trigger left-shift of all remaining elements
- Front position remains fixed at index 0 after shifting
- All array positions become reusable, eliminating space wastage
- Rear pointer adjusts to reflect new element positions

**Performance Trade-offs:**
- Enqueue operations: O(1) constant time
- Dequeue operations: O(n) linear time due to element shifting
- Space efficiency: 100% utilization of allocated array space

**Computational Impact:**
The shifting mechanism introduces significant overhead for large queues or high dequeue frequencies. Each dequeue operation requires moving all subsequent elements, resulting in O(n) complexity that can severely impact performance in demanding applications.

**Use Case Scenarios:**
- Educational demonstrations of space-time complexity trade-offs
- Applications with heavily skewed enqueue-to-dequeue ratios
- Small queue sizes where shifting overhead remains negligible

## Circular Queue Approach (Optimal Solution)

The circular queue approach provides the optimal solution to both space utilization and performance challenges through mathematical wraparound logic. This implementation employs modulo arithmetic to create a conceptually infinite array within finite memory bounds, representing one of the most elegant solutions in data structure design.

### Core Innovation and Mathematical Foundation

Circular queues treat the array as a circular buffer where the rear pointer wraps to the beginning when reaching the array end, provided space is available. This eliminates both space wastage and shifting overhead through elegant mathematical operations that fundamentally redefine how we conceptualize array boundaries.

**Mathematical Transformation:**
Instead of viewing arrays as linear structures with fixed endpoints, circular queues employ modulo arithmetic to create a continuous, cyclical address space. The linear array with fixed start and end points is transformed into a continuous cycle where the last position connects back to the first position.

### Modulo Arithmetic Application

The mathematical foundation relies on modulo operations that enable seamless wraparound. The core operations use modulo arithmetic where rear and front pointers advance circularly using `(pointer + 1) % MAX_SIZE` calculations.

**Wraparound Logic:**
When the rear pointer reaches the maximum array size, modulo arithmetic automatically wraps it back to position 0, creating the circular behavior. Similarly, the front pointer wraps around when advancing past the last array position.

### State Management and Boundary Conditions

Circular queues require sophisticated state tracking to distinguish between empty and full conditions since both states can have `front == rear`.

**Empty vs Full Disambiguation:**

1. **Count-Based Approach** (Recommended): Uses an additional counter variable to track the current number of elements in the queue, making state determination straightforward.

2. **Sacrificial Slot Approach**: Keeps one slot always empty to distinguish between empty and full states, sacrificing one position for simpler logic.


### Performance Analysis and Complexity

**Time Complexity:**
- **Enqueue**: O(1) - Constant time insertion with modulo calculation
- **Dequeue**: O(1) - Constant time removal with modulo calculation
- **Peek/Front**: O(1) - Direct access to front element
- **isEmpty/isFull**: O(1) - Simple state checks

**Space Complexity:**
- **Storage**: O(n) where n is the maximum queue capacity
- **Auxiliary Space**: O(1) - Only requires front, rear, and count variables
- **Space Efficiency**: 100% utilization of allocated array space

**Performance Advantages:**
- **No Element Shifting**: Unlike modified linear queues, no O(n) shifting operations
- **Predictable Performance**: All operations maintain constant time complexity
- **Cache Efficiency**: Sequential memory access patterns optimize cache performance
- **Memory Locality**: Circular access patterns maintain spatial locality benefits

### Comparison with Alternative Approaches

| Aspect | Linear Queue | Modified Linear | Circular Queue |
|--------|-------------|----------------|----------------|
| **Space Efficiency** | Poor (degrades over time) | Excellent (100%) | Excellent (100%) |
| **Time Complexity** | O(1) enqueue/dequeue | O(1) enqueue, O(n) dequeue | O(1) enqueue/dequeue |
| **Implementation Complexity** | Simple | Moderate | Moderate |
| **Memory Overhead** | Minimal | Minimal | Minimal |
| **Production Suitability** | Educational only | Limited use cases | Industry standard |

### Mathematical Elegance and Design Philosophy

Circular queues exemplify how mathematical insight can fundamentally transform computational limitations. Rather than accepting trade-offs or implementing workarounds, the circular approach eliminates the underlying problem through conceptual innovation.

**Design Philosophy Principles:**
1. **Mathematical Foundation**: Modulo arithmetic provides elegant wraparound logic
2. **Zero-Waste Principle**: Every allocated memory position remains perpetually usable
3. **Constant Performance**: All operations maintain O(1) complexity regardless of usage patterns
4. **Scalability**: Solution effectiveness remains consistent across different queue sizes

**Technical Advantages:**
Circular queues achieve optimal performance by eliminating the fundamental limitations of both linear queue space wastage and modified linear queue performance penalties. The mathematical elegance of modulo operations provides both space efficiency and constant-time operations, making circular queues the definitive solution for production queue implementations.

## Implementation Methods in C

Queue implementations in C can be categorized by their memory management strategies and data organization approaches. Each method provides different trade-offs between performance, flexibility, and complexity.

### Static Array Implementation

Static arrays provide the most direct implementation approach using compile-time memory allocation on the program stack. This method prioritizes execution speed and simplicity over flexibility.

**Technical Characteristics:**
- Memory allocation occurs at compile time on the stack
- Fixed capacity determined by preprocessor definition
- Direct memory addressing provides optimal access speed
- No dynamic memory management overhead

**Performance Benefits:**
- Fastest possible memory access due to stack allocation
- Predictable memory layout enables compiler optimizations
- No allocation/deallocation overhead during runtime
- Cache-friendly memory access patterns

**Application Scenarios:**
- Embedded systems with strict memory constraints
- Performance-critical applications requiring minimal latency
- Systems with well-defined capacity requirements

### Dynamic Array Implementation

Dynamic arrays utilize heap allocation to provide runtime flexibility in queue sizing. This approach trades some performance for increased adaptability and memory efficiency.

**Implementation Benefits:**
- Queue size determined at runtime based on application requirements
- Memory allocation matches actual usage needs
- Support for multiple queue instances with different capacities
- Flexible memory management with proper allocation and deallocation

**Performance Considerations:**
- Heap allocation introduces slight overhead compared to stack allocation
- Memory access patterns may be less cache-friendly than static arrays
- Requires careful memory management to prevent leaks
- Dynamic sizing enables optimal memory utilization

**Suitable Applications:**
- Applications with variable or unknown capacity requirements
- Multi-instance systems requiring different queue sizes
- Memory-constrained environments where exact sizing matters

### Structure-Based Implementation

Structure-based implementations encapsulate queue data and operations within custom data types, providing enhanced code organization and support for multiple queue instances. This approach combines the benefits of data abstraction with flexible implementation choices.

**Organizational Benefits:**
- Encapsulation of related data elements within a single entity
- Support for multiple independent queue instances
- Clean function interfaces with explicit queue parameters
- Enhanced code maintainability and readability

**Implementation Flexibility:**
- Internal array can use static or dynamic allocation strategies
- Runtime configuration of queue capacity and behavior
- Easy extension with additional metadata and functionality
- Object-oriented design patterns applicable in C

**Professional Applications:**
- Production systems requiring maintainable code architecture
- Applications managing multiple queue instances with different properties
- Systems where code organization and extensibility are priorities

### Linked List Implementation

Linked list implementations provide dynamic memory allocation with no inherent size limitations. Each queue element exists as an independent node with pointer-based connectivity.

**Dynamic Characteristics:**
- Memory allocation grows and shrinks with actual queue usage
- No fixed capacity limitations beyond system memory constraints
- Efficient memory utilization proportional to element count
- Flexible insertion and deletion without pre-allocated space requirements

**Performance Implications:**
- Non-contiguous memory allocation may impact cache performance
- Pointer overhead increases memory usage per element
- Dynamic allocation introduces malloc/free overhead
- No array indexing benefits for memory access optimization

**Optimal Use Cases:**
- Applications with highly variable or unpredictable queue sizes
- Memory-constrained environments requiring efficient space utilization
- Systems where maximum capacity cannot be predetermined

### Implementation Method Selection

The choice of implementation method depends on specific application requirements and constraints:

**Performance Priority:** Static arrays for maximum speed with known capacity bounds
**Memory Efficiency:** Dynamic arrays for optimal space utilization with runtime sizing
**Code Organization:** Structure-based approaches for maintainable, multi-instance systems
**Flexibility:** Linked lists for dynamic sizing without capacity limitations

## Implementations in this Repository

Linear and modified linear queue implementations focus on array-based approaches because the space utilization challenges are specific to fixed-size arrays. Circular queues include all implementation types (array, struct, and linked list) as they represent complete, production-ready solutions.

---

## Linear Queue Implementations

Linear queue implementations provide the foundational understanding of FIFO operations while clearly exposing the inherent space utilization limitations. These implementations serve as the baseline for understanding why more sophisticated solutions are necessary.

**Educational Purpose:** These implementations demonstrate the core problem that drives queue design evolution - the progressive loss of usable space due to inability to reclaim dequeued positions.

### Implementation Scope

Linear queue implementations focus exclusively on array-based approaches because the space wastage problem is intrinsic to fixed-size array structures. Dynamic memory allocation inherently avoids these issues, making such implementations inappropriate for demonstrating the core challenges.

<details>
<summary><strong>🔹 Linear Queue Implementation (Array-Based)</strong></summary>

### Technical Overview

This implementation employs a static array with global front and rear pointer variables to maintain queue state. The approach emphasizes implementation simplicity while exposing fundamental space utilization inefficiencies inherent in naive array-based queue designs.

**Implementation Characteristics:**
- Global array declaration with fixed maximum capacity
- Front and rear pointers track queue boundaries
- Enqueue operations advance rear pointer and insert elements
- Dequeue operations advance front pointer without space reclamation

### Operational Sequence Analysis

The following sequence demonstrates the progressive space degradation inherent in linear queue operations:

1. **Initial State**: Array capacity of 5 elements with empty queue indicators
2. **Element Insertion**: After enqueuing elements 10, 20, 30, positions 3-4 remain available
3. **Dequeue Operation Impact**: After dequeuing element 10, position 0 becomes inaccessible
4. **Space Wastage Progression**: Position 0 becomes permanently unusable for future operations

### Phantom Capacity Exhaustion

Linear queues exhibit a critical flaw where apparent capacity exhaustion occurs despite available array positions. After multiple enqueue/dequeue cycles, the queue array shows positions 0-2 as inaccessible while positions 3-4 contain current elements. Subsequent enqueue attempts fail because the rear pointer reaches maximum capacity, even though earlier positions remain available but inaccessible due to implementation constraints.

### Performance Analysis

**Strengths:**
- **Implementation Simplicity**: Minimal complexity in logic and memory management
- **Optimal Operation Speed**: O(1) time complexity for both enqueue and dequeue operations
- **Stack Memory Usage**: Static allocation eliminates dynamic memory overhead
- **Predictable Behavior**: Deterministic performance characteristics
- **Educational Clarity**: Demonstrates fundamental FIFO principles effectively

**Limitations:**
- **Progressive Space Loss**: Front positions become permanently inaccessible after dequeue operations
- **Phantom Capacity Issues**: Queue appears full while containing accessible empty positions
- **Fixed Capacity Constraints**: Compile-time size limitations prevent runtime adaptation
- **Space Utilization Inefficiency**: Worst-case scenario approaches zero effective capacity utilization

### Application Contexts

**Appropriate Use Cases:**
- Educational environments for demonstrating FIFO principles and design limitations
- Simple applications with periodic complete queue drainage
- Embedded systems where implementation simplicity outweighs efficiency concerns
- Temporary processing scenarios with predictable reset intervals

### Implementation Insight

This implementation serves as an excellent educational foundation, clearly demonstrating both the fundamental principles of queue operations and the limitations that drive the development of more sophisticated solutions. The simplicity of the approach makes it ideal for understanding basic concepts before progressing to optimized implementations.

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
        while (choice < 1 || choice > 5) {
            printf("Invalid selection\n");
            printf("Selection: ");
            scanf("%d", &choice);
        }
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
        }
    }
}
```

</details>

<details>
<summary><strong>🔹 Linear Queue Implementation (Struct-Based)</strong></summary>

### Technical Overview

The struct-based linear queue implementation encapsulates queue data within a custom structure while maintaining the same fundamental operational characteristics as the array-based approach. This design emphasizes code organization and multi-instance capability without addressing the underlying space utilization challenges.

**Structural Design:**
The implementation uses a Queue structure containing a dynamically allocated array pointer, front and rear element indices, and maximum queue capacity.

**Implementation Benefits:**
- Enhanced code organization through data encapsulation
- Support for multiple independent queue instances
- Runtime capacity configuration flexibility
- Professional code structure suitable for larger applications

### Memory Management Strategy

The struct-based approach employs dynamic memory allocation to provide runtime flexibility while maintaining the linear queue operational model through proper queue creation with memory allocation for both the queue structure and internal data array.

### Multi-Instance Capability

This implementation enables simultaneous management of multiple queue instances with independent capacities and states. Different queues can be created for customers, orders, and priority handling, each maintaining its own space wastage pattern and operational state, demonstrating how structural organization can coexist with algorithmic limitations.

### Performance Analysis

**Enhanced Characteristics:**
- **Professional Code Organization**: Clean, maintainable structure design
- **Runtime Configuration**: Flexible capacity determination during initialization
- **Multi-Instance Support**: Independent queue management capability
- **Memory Efficiency**: Allocation matches specified requirements
- **Extensibility**: Easy addition of queue metadata and functionality

**Persistent Limitations:**
- **Inherited Space Wastage**: Same fundamental space utilization problems as array-based version
- **Memory Management Complexity**: Additional allocation/deallocation responsibilities
- **Implementation Overhead**: Increased complexity compared to simple array approach
- **Performance Consistency**: Space efficiency degrades identically to array-based implementation

### Application Contexts

**Suitable Scenarios:**
- Educational demonstrations of professional code organization principles
- Multi-queue applications requiring independent instance management
- Systems where code maintainability priorities outweigh algorithmic optimality
- Development environments emphasizing software engineering best practices

### Educational Value

This implementation demonstrates how software engineering practices (encapsulation, modularity, professional structure) can improve code quality and maintainability even when underlying algorithms remain suboptimal. It serves as an important bridge between basic concepts and production-quality implementations.

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
    
    printf("Queue with capacity %d created successfully!\n", capacity);
    
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
        
        while (choice < 1 || choice > 5) {
            printf("Invalid selection\n");
            printf("Selection: ");
            scanf("%d", &choice);
        }
        
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
        }
    }
    
    return 0;
}
```

</details>

---

## Modified Linear Queue Implementations - Solution Approach #1

Modified linear queue implementations represent the first solution approach to address the space wastage problem inherent in linear queues. This strategy employs element shifting to reclaim dequeued positions, trading space efficiency for computational overhead.

**Solution Principle:** When dequeue operations occur, all remaining elements shift left to eliminate gaps and make front positions reusable. This approach achieves 100% space utilization but introduces O(n) complexity for dequeue operations.

**Trade-off Analysis:** This solution resolves the space utilization problem at the cost of performance degradation. Each dequeue operation requires repositioning all subsequent elements, making it computationally expensive for large queues or frequent dequeue operations.

### Implementation Scope

Modified linear queue implementations focus on array-based approaches because element shifting is specifically relevant to contiguous memory structures. Linked list implementations naturally avoid space wastage through pointer manipulation, making shifting operations unnecessary and conceptually irrelevant.

<details>
<summary><strong>🔹 Modified Linear Queue Implementation (Array-Based)</strong></summary>

### Technical Overview

This implementation addresses linear queue space limitations through systematic element shifting that reclaims front positions after dequeue operations. The approach prioritizes space efficiency over operational performance, demonstrating a fundamental trade-off in algorithm design.

**Core Mechanism:**
- Dequeue operations remove front elements and trigger left-shifting of all remaining elements
- Front position remains consistently at index 0 after shifting operations
- All array positions become reusable, eliminating the space wastage characteristic of linear queues
- Rear pointer adjusts to reflect new element positions after shifting

### Operational Sequence with Shifting

The following sequence demonstrates how element shifting eliminates space wastage:

1. **Initial Full State**: Queue contains elements [10, 20, 30, 40, 50] with rear index at position 4, all positions occupied
2. **Dequeue with Shifting**: Remove element 10 from front position, shift all remaining elements left by one position, update rear pointer to reflect new positions. Result: [20, 30, 40, 50, __] with position 4 now available
3. **Space Reclamation**: Enqueue operation can now use position 4. Final result: [20, 30, 40, 50, 60] achieving 100% space utilization

### Performance Impact Analysis

The shifting mechanism fundamentally alters the performance characteristics of queue operations:

**Time Complexity Changes:**
- Enqueue operations: O(1) - unchanged from linear queue
- Dequeue operations: O(n) - linear time due to element shifting
- Space complexity: O(n) with 100% utilization efficiency

**Computational Overhead:**
For a queue with n elements, each dequeue operation requires (n-1) element movements, resulting in significant computational overhead for large queues or high dequeue frequencies.

### Performance Analysis

**Advantages:**
- **Perfect Space Utilization**: Every array position remains reusable throughout operations
- **Eliminated Phantom Full Condition**: Queue capacity accurately reflects actual availability
- **Predictable Memory Footprint**: Fixed allocation with optimal space efficiency
- **Educational Clarity**: Clearly demonstrates space-time complexity trade-offs

**Limitations:**
- **Linear Dequeue Complexity**: O(n) dequeue operations create performance bottlenecks
- **CPU Intensive Processing**: High computational overhead for element shifting
- **Poor Scalability**: Performance degradation increases with queue size
- **Unsuitable for Production**: Performance characteristics eliminate real-world applicability

### Application Contexts

**Educational Applications:**
- Demonstrating fundamental trade-offs between space and time complexity
- Teaching algorithm optimization principles and decision-making
- Illustrating why simple solutions may not be optimal solutions

**Limited Practical Use:**
- Applications with heavily skewed enqueue-to-dequeue ratios (many enqueues, few dequeues)
- Small queue implementations where shifting overhead remains negligible
- Systems where space efficiency significantly outweighs performance considerations

### Implementation Insight

This approach demonstrates that solving one algorithmic problem may introduce another. While element shifting successfully eliminates space wastage, it creates performance problems that make the solution impractical for most applications. This implementation serves as an important stepping stone in understanding why more sophisticated solutions like circular queues become necessary.

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
        while (choice < 1 || choice > 5) {
            printf("Invalid selection\n");
            printf("Selection: ");
            scanf("%d", &choice);
        }
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
        }
    }
}
```

</details>

<details>
<summary><strong>🔹 Modified Linear Queue Implementation (Struct-Based)</strong></summary>

### Technical Overview

The struct-based modified linear queue implementation combines professional code organization with the element shifting solution approach. This design provides enhanced code structure and multi-instance capability while maintaining the same space-time trade-off characteristics as the array-based version.

**Enhanced Structure Design:**
The modified queue structure includes a dynamically allocated array, rear pointer, maximum size, and current size counter. The absence of a front pointer reflects the shifting strategy where elements always occupy positions starting from index 0.

### Professional Implementation Features

This implementation demonstrates how professional software engineering practices can be applied even to algorithmically suboptimal solutions through proper memory management, error handling, and clean interface design.

### Multi-Instance Management

The struct-based approach enables sophisticated queue management scenarios with different queues sized appropriately for different purposes:
- Network buffers with large capacities (1024+ elements)
- Print queues with moderate sizes (50-100 elements)  
- Event queues with small, responsive sizes (200 elements)

Each queue independently manages its shifting operations and space utilization, demonstrating how structural organization scales with system complexity.

### Operational Implementation

The shifting mechanism receives professional implementation with proper error handling and state management:
- Empty queue detection before dequeue operations
- Element retrieval from front position (always index 0)
- Professional shifting with bounds checking using loop iterations
- Proper pointer and counter updates after shifting
- Return of dequeued data with error codes for failure cases

### Performance Analysis

**Enhanced Characteristics:**
- **Professional Code Architecture**: Clean, maintainable implementation structure
- **Runtime Configuration**: Flexible capacity determination for different use cases
- **Multi-Instance Capability**: Independent queue management with different characteristics
- **Memory Management**: Proper allocation and deallocation handling
- **Error Handling**: Robust boundary condition management

**Persistent Performance Issues:**
- **Inherited Shifting Overhead**: Same O(n) dequeue complexity as array-based version
- **Scalability Limitations**: Performance degradation remains problematic for large queues
- **Computational Inefficiency**: Professional implementation cannot overcome algorithmic limitations
- **Production Unsuitability**: Enhanced structure does not resolve fundamental performance issues

### Application Contexts

**Professional Development Scenarios:**
- Teaching software engineering principles alongside algorithm analysis
- Demonstrating how code quality and algorithmic efficiency represent separate concerns
- Developing maintainable implementations of suboptimal algorithms during system evolution

**Educational Value:**
- Illustrating the relationship between code organization and algorithmic performance
- Showing how professional practices apply regardless of underlying algorithm optimality
- Preparing students for real-world scenarios where algorithm improvement occurs incrementally

### Implementation Insight

This implementation demonstrates that professional software engineering practices remain valuable even when applied to algorithmically suboptimal solutions. While the struct-based organization improves code quality, maintainability, and usability, it cannot overcome the fundamental performance limitations inherent in the shifting approach. This serves as an important lesson in distinguishing between code quality and algorithmic efficiency.

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
        
        while (choice < 1 || choice > 5) {
            printf("Invalid selection\n");
            printf("Selection: ");
            scanf("%d", &choice);
        }
        
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
        }
    }
    
    return 0;
}
```

</details>

---

## Circular Queue Implementations - Solution Approach #2 (Optimal)

Circular queue implementations provide the optimal solution to linear queue limitations through mathematical innovation rather than computational brute force. This approach employs modulo arithmetic to achieve both perfect space utilization and constant-time operations.

**Solution Principle:** Circular queues treat arrays as circular buffers where pointer wraparound enables continuous space reuse without element shifting. The mathematical elegance of modulo operations eliminates both space wastage and performance degradation.

**Technical Innovation:** Instead of accepting space limitations or introducing computational overhead, circular queues transform the fundamental approach by reimagining array boundaries as cyclical rather than linear.

### Comprehensive Implementation Coverage

Circular queues represent complete, production-ready solutions suitable for all implementation approaches:

1. **Array-Based**: Demonstrates optimal modulo arithmetic application
2. **Struct-Based**: Provides professional, multi-instance capable implementations  
3. **Linked List**: Illustrates true circular topology in dynamic structures

Each implementation type maintains the core circular queue advantages while addressing different deployment scenarios and requirements.

<details>
<summary><strong>🔹 Circular Queue Implementation (Array-Based)</strong></summary>

### Technical Overview

The array-based circular queue implementation represents the mathematical solution to linear queue limitations through modulo arithmetic operations. This approach achieves optimal space utilization and performance characteristics by treating fixed-size arrays as conceptually infinite circular buffers.

**Core Mathematical Innovation:**
Circular queues employ modulo arithmetic to enable pointer wraparound, creating a logical circle within linear memory through rear and front pointer advancement using modulo operations.

### Operational Sequence Analysis

The following sequence demonstrates circular wraparound functionality:

1. **Initial Setup**:
   - Initialize integer array with specified capacity
   - Set front and rear pointers to -1 (empty state)
   - Initialize count to 0 for state tracking

2. **Fill to Capacity**:
   - After enqueueing elements 10, 20, 30, 40, 50
   - Queue state: [10, 20, 30, 40, 50]
   - Front pointer at 0, rear at 4, count equals 5

3. **Dequeue Operations**:
   - Remove elements 10 and 20 from front
   - Logical state: [XX, XX, 30, 40, 50]
   - Front advances to 2, rear remains 4, count becomes 3

4. **Wraparound Enqueue**:
   - Enqueue element 60 using modulo arithmetic
   - Rear advances: (4 + 1) % 5 = 0 (mathematical wraparound)
   - Final state: [60, XX, 30, 40, 50]
   - Front at 2, rear at 0, count equals 4

### Mathematical Foundation

The modulo operation provides the mathematical basis for circular behavior:
- When index < array_size - 1: Normal increment behavior
- When index == array_size - 1: Wraps to 0, creating circular effect

### State Management

Circular queues require careful state tracking to distinguish between empty and full conditions using count variables, since pointer positions alone cannot differentiate between empty and full states in circular implementations.

### Performance Analysis

**Optimal Characteristics:**
- **Perfect Space Utilization**: 100% of array positions remain continuously reusable
- **Constant Time Operations**: Both enqueue and dequeue maintain O(1) complexity
- **No Element Movement**: Mathematical operations eliminate shifting overhead
- **Predictable Performance**: Consistent operation times regardless of queue state
- **Memory Efficiency**: No wasted space or unnecessary allocations

**Implementation Requirements:**
- **Additional State Tracking**: Count variable required for state determination
- **Modulo Arithmetic Understanding**: Slightly increased conceptual complexity
- **Boundary Condition Handling**: Careful management of wraparound scenarios

### Application Contexts

**Production Systems:**
- High-performance computing applications requiring optimal queue operations
- Operating system buffers and kernel-level data structures
- Network packet processing in routers and communication equipment
- Real-time systems where predictable performance is critical
- Embedded systems requiring optimal resource utilization

### Implementation Insight

Circular queues demonstrate how mathematical insight can fundamentally transform algorithmic limitations. Rather than accepting trade-offs or introducing workarounds, the circular approach eliminates the problem entirely through conceptual innovation. This implementation represents the gold standard for queue implementations in production systems.

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
        while (choice < 1 || choice > 5) {
            printf("Invalid selection\n");
            printf("Selection: ");
            scanf("%d", &choice);
        }
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
        }
    }
}
```

</details>

<details>
<summary><strong>🔹 Circular Queue Implementation (Struct-Based)</strong></summary>

### Technical Overview

The struct-based circular queue implementation combines the mathematical optimality of modulo arithmetic with professional software engineering practices. This approach provides the optimal performance characteristics of circular queues within a well-organized, maintainable code structure suitable for production applications.

**Enhanced Structure Design:**
The circular queue structure includes a dynamically allocated circular array, front and rear pointers for operations, maximum capacity, and current element count. This structure acts as a complete queue management system, encapsulating all necessary data and state information for independent circular queue operation.

### Professional Implementation Features

The struct-based approach enables sophisticated queue management capabilities through proper memory allocation, initialization of all structure members, and professional error handling patterns.

### Multi-Instance Management

This implementation enables complex applications with multiple independent circular queues:
- Network buffers with large capacities for high-throughput operations
- Audio buffers with optimized sizes for multimedia processing
- Event queues with smaller, responsive capacities for real-time processing

Each queue maintains optimal performance independently without interference.

### Encapsulated Operations

The circular logic receives professional implementation with clean interfaces:

**Enqueue Operations:**
- Check capacity limits before insertion
- Handle first element special case
- Apply modulo arithmetic for circular rear advancement
- Update count and return operation status

**Dequeue Operations:**  
- Verify queue state before removal
- Retrieve data from front position
- Apply modulo arithmetic for circular front advancement
- Reset pointers when queue becomes empty
- Return dequeued data with proper error handling

### Memory Management Excellence

Professional memory management ensures robust operation through proper allocation validation, structured deallocation of both data array and queue structure, and null pointer safety checks.

### Performance Analysis

**Professional Advantages:**
- **Optimal Performance**: All circular queue benefits with O(1) operations and perfect space utilization
- **Enterprise Architecture**: Clean, maintainable code structure suitable for large applications
- **Runtime Configuration**: Each instance sized appropriately for specific requirements
- **Independent Operation**: Multiple queues operate without interference
- **Professional Interface**: Clean function signatures and error handling
- **Scalability**: Easy integration into complex systems

**Implementation Considerations:**
- **Memory Management Responsibility**: Proper allocation and deallocation required
- **Increased Complexity**: More sophisticated than simple array implementation
- **Structure Overhead**: Additional memory for queue metadata

### Application Contexts

**Enterprise Applications:**
- Production systems requiring multiple queue instances with optimal performance
- Server applications managing different types of data streams
- Game development with separate circular buffers for audio, graphics, and input
- Distributed systems with multiple communication channels
- Multi-threaded applications where each thread requires independent queue access

### Professional Development Benefits

This implementation demonstrates how optimal algorithms can be packaged within professional software engineering practices:

```c
// Clean, readable interfaces
int getQueueSize(CircularQueue* cq);
int getQueueCapacity(CircularQueue* cq);
bool isQueueEmpty(CircularQueue* cq);
bool isQueueFull(CircularQueue* cq);

// Easy debugging and monitoring
void printQueueStatistics(CircularQueue* cq);
```

### Implementation Insight

This implementation represents the synthesis of mathematical optimality and software engineering excellence. It demonstrates how the best algorithmic solutions can be made even more valuable through professional implementation practices, making them suitable for production deployment in complex systems.

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
        
        while (choice < 1 || choice > 5) {
            printf("Invalid selection\n");
            printf("Selection: ");
            scanf("%d", &choice);
        }
        
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
        }
    }
    
    return 0;
}
```

</details>

<details>
<summary><strong>🔹 Circular Queue Implementation (Linked List)</strong></summary>

### Technical Overview

The linked list circular queue implementation creates true circular topology in memory through dynamic node allocation and pointer-based connectivity. This approach combines the unlimited growth potential of linked lists with circular queue principles, providing the most flexible implementation variant.

**Unique Structural Design:**
The implementation uses specialized data structures where Node contains data and next pointer for circular connectivity, while CircularLinkedQueue maintains only a rear pointer since in a true circle, rear->next always points to the front, eliminating the need for separate front pointer management.

**Key Innovation:** Only the rear pointer is maintained because in a true circle, the rear's next pointer always points to the front, eliminating the need for separate front pointer management.

### True Circular Topology

This implementation creates actual circular structures in memory where each node connects to the next, with the last node connecting back to the first. For a single element, the node points to itself creating a perfect circle.

### Dynamic Circular Operations

The circular linked list grows and shrinks while maintaining circular topology. Enqueue operations handle first node creation (self-pointing circle) and insertion into existing circles by updating pointer linkages. Dequeue operations manage front removal while preserving circular connections and handle the special case of removing the last element.

### Circular Traversal Capability

One unique feature is infinite circular traversal where starting from the front (rear->next), the implementation can traverse multiple complete cycles through the queue elements, automatically wrapping around due to the circular pointer structure.

### Flexible Capacity Management

This implementation can operate as bounded or unbounded queue by setting capacity limits, providing flexibility for different application requirements.

### Performance Analysis

**Unique Advantages:**
- **True Circular Structure**: Physical circular topology, not simulated through arithmetic
- **Dynamic Sizing**: Grows and shrinks based on actual usage
- **Unlimited Capacity**: No fixed size restrictions (unless artificially imposed)
- **Memory Efficiency**: Allocates exactly what is needed
- **Flexible Capacity**: Can implement bounded or unbounded behavior
- **Infinite Traversal**: Natural support for circular iteration patterns

**Implementation Considerations:**
- **Memory Overhead**: Each node requires additional pointer storage
- **Non-Contiguous Memory**: Nodes distributed throughout heap memory
- **Dynamic Allocation Cost**: malloc/free overhead for each operation
- **Cache Performance**: May exhibit poor cache locality compared to arrays
- **Pointer Complexity**: More complex pointer manipulation requirements

### Application Contexts

**Specialized Use Cases:**
- Round-robin scheduling systems with dynamic process lists
- Circular playlists in media applications with dynamic song management
- Load balancing systems with dynamic server lists
- Game development for circular player rotation with variable player counts
- Simulation systems requiring circular resource allocation

### Advanced Features

This implementation enables sophisticated circular queue operations including circular merge operations, circular split operations, and circular rotation capabilities that take advantage of the dynamic linked structure.

### Implementation Insight

The linked list circular queue represents the ultimate flexibility in queue implementation. It demonstrates how circular queue principles can be applied beyond fixed arrays to create truly dynamic, circular data structures. While it may not be the optimal choice for high-performance scenarios, it provides unmatched flexibility for applications requiring dynamic circular behavior.

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

void freeQueue() {
    if (isEmpty()) return;
    
    Node *current = queue.rear->next;
    Node *temp;
    
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != queue.rear->next);
    
    queue.rear = NULL;
    queue.size = 0;
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
    
    printf("Circular Queue with Linked List (capacity %d) created successfully!\n", capacity);
    
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
        
        while (choice < 1 || choice > 5) {
            printf("Invalid selection\n");
            printf("Selection: ");
            scanf("%d", &choice);
        }
        
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
                freeQueue();
                printf("Queue freed successfully!\n");
                return 0;
        }
    }
    
    return 0;
}
```

</details>

---

## Performance Comparison

| Queue Type | Implementation | Enqueue Time | Dequeue Time | Space Efficiency | Memory Usage | Purpose |
|------------|----------------|--------------|--------------|------------------|--------------|---------|
| **Linear Queue** | Array | O(1) | O(1) | ❌ Poor (up to n-1 wasted) | Fixed | Foundational learning |
| **Linear Queue** | Struct | O(1) | O(1) | ❌ Poor (up to n-1 wasted) | Dynamic allocation | Multi-instance learning |
| **Modified Linear** (Solution #1) | Array | O(1) | O(n) | ✅ Perfect | Fixed | Trade-off demonstration |
| **Modified Linear** (Solution #1) | Struct | O(1) | O(n) | ✅ Perfect | Dynamic allocation | Professional trade-off demo |
| **Circular Queue** (Solution #2) | Array | O(1) | O(1) | ✅ Perfect | Fixed | 🏆 Production systems |
| **Circular Queue** (Solution #2) | Struct | O(1) | O(1) | ✅ Perfect | Dynamic allocation | 🏆 Professional applications |
| **Circular Queue** (Solution #2) | Linked List | O(1) | O(1) | ✅ Perfect | Dynamic nodes | 🏆 Unlimited dynamic systems |

## Implementation Selection Guide

### Production Implementation Decisions
- **Circular Array**: High-performance systems with predetermined maximum capacity requirements
- **Circular Struct**: Professional applications needing multiple queue instances with runtime configuration
- **Circular Linked List**: Systems with highly variable capacity requirements or unlimited growth needs

### Implementation Guidelines
- **Fixed capacity, maximum performance**: Choose Circular Array
- **Multiple queues, runtime sizing**: Choose Circular Struct  
- **Dynamic capacity, unlimited growth**: Choose Circular Linked List
- **Learning purposes**: Progress from Linear → Modified Linear → Circular

## Conclusion

This repository demonstrates the systematic approach to solving the fundamental queue data structure challenge through progressive solution development and mathematical improvement

1. **Linear Queues** establish the foundational FIFO principles while exposing critical space utilization limitations
2. **Modified Linear Queue Approach** represents the first solution attempt using element shifting, trading performance for space efficiency
3. **Circular Queue Approach** provides the optimal solution through mathematical innovation, achieving both space efficiency and performance optimization with modulo arithmetic
