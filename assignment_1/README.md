# Array Operations Implementation in C

## Table of Contents
- [Overview](#overview)
- [What is an Array?](#what-is-an-array)
- [Array Operations](#array-operations)
- [Memory Management Approaches](#memory-management-approaches)
- [Static vs Dynamic Memory Allocation](#static-vs-dynamic-memory-allocation)
- [Implementations in this Repository](#implementations-in-this-repository)
- [Algorithm Analysis](#algorithm-analysis)
- [Applications](#applications)

## Overview

This repository contains **two different implementations** of fundamental array operations in C programming language, demonstrating both **static** and **dynamic** memory allocation approaches. Both implementations provide identical user interfaces while showcasing different memory management strategies.

## What is an Array?

An **Array** is a collection of elements of the same data type stored in contiguous memory locations. Arrays are one of the most fundamental data structures in computer science and provide efficient access to elements using indices.

<div align="center">
  <img src="array.png" alt="Array Data Structure Visualization" />
</div>

### Key Characteristics:
- **Homogeneous**: All elements are of the same data type
- **Contiguous**: Elements are stored in consecutive memory locations
- **Indexed**: Elements can be accessed using their position (0-based indexing in C)
- **Fixed Type**: Data type is determined at declaration time

## Array Operations

### Core Operations

| Operation | Description | Time Complexity |
|-----------|-------------|-----------------|
| **Access** | Retrieve element at given index | O(1) |
| **Search** | Find element by value | O(n) linear, O(log n) binary |
| **Insert** | Add element at specific position | O(n) |
| **Delete** | Remove element by value/position | O(n) |
| **Update** | Modify element at given index | O(1) |
| **Sort** | Arrange elements in order | O(n²) bubble sort |

### Advanced Operations

- **Traversal**: Visit all elements sequentially
- **Reversal**: Reverse the order of elements
- **Rotation**: Shift elements circularly
- **Merging**: Combine two arrays
- **Splitting**: Divide array into subarrays

## Memory Management Approaches

### 1. **Static Memory Allocation**
- Memory allocated at **compile time**
- Fixed size determined during declaration
- Memory allocated on the **stack**
- Automatic deallocation when out of scope

```c
int arr[100];  // Fixed size of 100 integers
```

### 2. **Dynamic Memory Allocation**
- Memory allocated at **runtime**
- Size can be determined during execution
- Memory allocated on the **heap**
- Manual allocation and deallocation required

```c
int *arr = malloc(n * sizeof(int));  // Size 'n' determined at runtime
```

## Static vs Dynamic Memory Allocation

| Aspect | Static Allocation | Dynamic Allocation |
|--------|------------------|-------------------|
| **Memory Location** | Stack | Heap |
| **Size** | Fixed at compile time | Variable at runtime |
| **Performance** | Faster access | Slightly slower |
| **Memory Management** | Automatic | Manual (malloc/free) |
| **Flexibility** | Limited | High |
| **Memory Waste** | Possible if underutilized | Minimal |
| **Risk** | Stack overflow | Memory leaks |

## Implementations in this Repository

This repository demonstrates both approaches with identical functionality but different memory management strategies:

> Expand to view detailed information about each implementation approach.



<details>
<summary><strong>🔹 Static Array Implementation</strong></summary>

### Overview
This implementation uses a **fixed-size array** with compile-time memory allocation. The array size is limited by the `MAX_SIZE` constant, providing fast access and simple memory management.

### Key Features
- **Fixed Size**: Maximum of 100 elements (configurable via `MAX_SIZE`)
- **Stack Memory**: Uses automatic memory management
- **Global Variables**: `int arr[MAX_SIZE]` and `int n` (current size)
- **Fast Access**: Direct array indexing for O(1) access time
- **No Memory Leaks**: Automatic cleanup when program ends

### Memory Management
```c
#define MAX_SIZE 100
int arr[MAX_SIZE];  // Fixed-size array
int n = 0;          // Current number of elements
```

### Advantages
- ✅ **Fast Performance**: Stack allocation is faster than heap
- ✅ **No Memory Management**: Automatic allocation/deallocation
- ✅ **Simple Implementation**: Straightforward array operations
- ✅ **No Fragmentation**: Contiguous memory allocation
- ✅ **Compile-time Safety**: Size known at compile time

### Disadvantages
- ❌ **Fixed Size Limitation**: Cannot exceed MAX_SIZE elements
- ❌ **Memory Waste**: Unused space if array not fully utilized
- ❌ **Stack Overflow Risk**: Large arrays may cause stack overflow
- ❌ **Inflexibility**: Cannot adapt to runtime requirements

### Use Cases
- **Small to Medium Arrays**: When size requirements are predictable
- **Performance-Critical Applications**: Where speed is paramount
- **Embedded Systems**: Limited memory environments
- **Educational Purposes**: Learning array fundamentals

### Source Code
```c
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int n = 0;

void readArray(int size){
    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid array size. Maximum allowed is %d\n", MAX_SIZE);
        n = 0;
        return;
    }
    printf("Enter array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    n = size;
    printf("Array read successfully.\n");
}

void displayArray(){
    if (n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    printf("Current array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int element, int position){
    if (n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    if (n >= MAX_SIZE) {
        printf("Array is full, cannot insert\n");
        return;
    }
    if (!(position > 0 && position <= n + 1)){
        printf("Invalid position\n");
        return;
    }
    for (int i = n; i >= position; i--) arr[i] = arr[i - 1];
    arr[position - 1] = element;
    n++;
    printf("Element %d inserted at position %d successfully.\n", element, position);
}

void deleteElement(int element){
    if (n == 0){
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == element){
            for (int j = i; j < n - 1; j++) arr[j] = arr[j + 1]; 
            n--;
            printf("Element %d deleted successfully.\n", element);
            return;
        }
    }
    printf("Element not found\n");
}

void deleteElementIndex(int position){
    if (n == 0){
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    if (!(position <= n && position >= 1)){
        printf("Position out of bounds\n");
        return;
    }
    int deletedElement = arr[position - 1];
    for (int j = position - 1; j < n - 1; j++) arr[j] = arr[j + 1];  
    n--;
    printf("Element %d at position %d deleted successfully.\n", deletedElement, position);
}

void searchElement(int element){
    if (n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    for (int i = 0; i < n; i++){
        if (arr[i] == element){
            printf("Element found at position: %d\n", i + 1);
            return;
        }
    }
    printf("Element not found\n");
}

void sortArray(){
    if (n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    int swapped;
    for (int i = 0; i < n-1; i++){
        swapped = 0;
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; 
            }
        }
        if (!swapped) {
            break;
        }
    }
    printf("Array sorted successfully\n");
}

void binarySearchElement(int element){
    if (n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    sortArray();
    
    printf("Array sorted for binary search: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == element){
            printf("Element found at position: %d (in sorted array)\n", mid + 1);
            return;
        }
        if (arr[mid] < element){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element not found\n");
}

int main(){
    int choice;
    
    while (1){
        printf("\nEnter operation to perform-\n");
        printf("1. Read Array\n");
        printf("2. Display Array\n");
        printf("3. Insert element\n");
        printf("4. Delete element\n");
        printf("5. Delete element from position\n");
        printf("6. Search element (Linear Search)\n");
        printf("7. Sort Array\n");
        printf("8. Search element (Binary Search)\n");
        printf("9. quit\n");
        printf("Selection: ");
        scanf("%d", &choice);
        
        if (choice == 9) return 0;
        if (!(choice > 0 && choice <= 9)){
            printf("Invalid input\n");
            continue;
        }
        
        switch(choice){
            case 1: {
                int size;
                printf("Enter array length: ");
                scanf("%d", &size);
                readArray(size);
                break;
            }
            case 2: 
                displayArray(); 
                break;
            case 3: {
                int element, position;
                printf("Enter element and position to insert: ");
                scanf("%d %d", &element, &position);
                insertElement(element, position);
                break;
            }
            case 4: {
                int element;
                printf("Enter element to remove: ");
                scanf("%d", &element);
                deleteElement(element);
                break;
            }
            case 5: {
                int position;
                printf("Enter the position of the element to delete: ");
                scanf("%d", &position);
                deleteElementIndex(position);
                break;
            }
            case 6: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                searchElement(element);
                break;
            }
            case 7: {
                sortArray();
                break;
            }
            case 8: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                binarySearchElement(element);
                break;
            }
        }
    }
}
```

</details>


<details>
<summary><strong>🔹 Dynamic Array Implementation</strong></summary>

### Overview
This implementation uses **dynamic memory allocation** with runtime size determination. The array can grow and shrink as needed using `malloc()`, `realloc()`, and `free()` functions, providing maximum flexibility.

### Key Features
- **Dynamic Size**: Array size determined at runtime
- **Heap Memory**: Uses manual memory management
- **Global Variables**: `int *arr` (pointer) and `int n` (current size)
- **Memory Efficiency**: Allocates only required memory
- **Flexible Resizing**: Can grow/shrink during execution using `realloc()`

### Memory Management
```c
int *arr = NULL;  // Dynamic array pointer
int n = 0;        // Current number of elements

// Allocation
arr = malloc(size * sizeof(int));

// Reallocation
arr = realloc(arr, new_size * sizeof(int));

// Deallocation
free(arr);
```

### Advantages
- ✅ **Unlimited Size**: Only limited by available system memory
- ✅ **Memory Efficiency**: Uses exact amount of memory needed
- ✅ **Runtime Flexibility**: Size can be determined during execution
- ✅ **Dynamic Resizing**: Can grow/shrink as requirements change
- ✅ **Scalability**: Suitable for large datasets

### Disadvantages
- ❌ **Memory Management Complexity**: Manual allocation/deallocation required
- ❌ **Memory Leak Risk**: Forgot to `free()` can cause memory leaks
- ❌ **Slower Access**: Heap allocation slightly slower than stack
- ❌ **Fragmentation**: Heap memory can become fragmented
- ❌ **Runtime Errors**: `malloc()` can fail if memory unavailable

### Use Cases
- **Large Datasets**: When array size is unknown at compile time
- **Memory-Constrained Systems**: Where memory efficiency is crucial
- **Data Structures**: Implementation of dynamic data structures
- **Real-world Applications**: Where input size varies significantly

### Memory Reallocation Strategy
The implementation uses `realloc()` for efficient memory management:

```c
void reAllocate(int mode){
    if (n + mode <= 0) {
        if (arr != NULL) {
            free(arr);
            arr = NULL;
        }
        n = 0;
        return;
    }
    int *temp = (int *) realloc(arr, (n + mode) * sizeof(int));
    if (temp == NULL) {
        printf("Memory Allocation failed\n");
        return;
    }
    arr = temp; 
    n += mode;
}
```

### Source Code
```c
#include<stdio.h>
#include<stdlib.h>

int *arr = NULL;
int n = 0;

void reAllocate(int mode){
    if (n + mode <= 0) {
        if (arr != NULL) {
            free(arr);
            arr = NULL;
        }
        n = 0;
        return;
    }
    int *temp = (int *) realloc(arr, (n + mode) * sizeof(int));
    if (temp == NULL) {
        printf("Memory Allocation failed\n");
        return;
    }
    arr = temp; 
    n += mode;
}

void readArray(int size){
    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }
    if (size <= 0) {
        printf("Invalid array length\n");
        n = 0;
        return;
    }
    arr = (int *) malloc(size * sizeof(int));
    if (arr == NULL){
        printf("Memory Allocation failed\n");
        n = 0;
        return;
    }
    n = size;
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    printf("Array read successfully.\n");
}

void displayArray(){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    printf("Current array: ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
    printf("\n");
}

void insertElement(int element, int position){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    if (!(position > 0 && position <= n + 1)){
        printf("Invalid position\n");
        return;
    }
    reAllocate(1);
    if (arr == NULL) return; 
    for (int i = n - 1; i >= position; i--) {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + position - 1) = element;
    printf("Element %d inserted at position %d successfully.\n", element, position);
}

void deleteElement(int element){
    if (arr == NULL || n == 0){
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    for (int i = 0; i < n; i++){
        if (*(arr + i) == element){
            for (int j = i; j < n - 1; j++) {
                *(arr + j) = *(arr + j + 1);
            }
            reAllocate(-1);
            printf("Element %d deleted successfully.\n", element);
            return;
        }
    }
    printf("Element not found\n");
}

void deleteElementIndex(int position){
    if (arr == NULL || n == 0){
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    if (!(position <= n && position >= 1)){
        printf("Position out of bounds\n");
        return;
    }
    int deletedElement = *(arr + position - 1);
    for (int j = position - 1; j < n - 1; j++) {
        *(arr + j) = *(arr + j + 1);
    }
    reAllocate(-1);
    printf("Element %d at position %d deleted successfully.\n", deletedElement, position);
}

void searchElement(int element){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    for (int i = 0; i < n; i++){
        if (*(arr + i) == element){
            printf("Element found at position: %d\n", i + 1);
            return;
        }
    }
    printf("Element not found\n");
}

void sortArray(){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    int swapped;
    for (int i = 0; i < n-1; i++){
        swapped = 0; 
        for (int j = 0; j < n-i-1; j++){
            if (*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                swapped = 1; 
            }
        }
        if (!swapped) {
            break;
        }
    }
    printf("Array sorted successfully\n");
}

void binarySearchElement(int element){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    sortArray();
    printf("Array sorted for binary search: ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
    printf("\n");
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (*(arr + mid) == element){
            printf("Element found at position: %d (in sorted array)\n", mid + 1);
            return;
        }
        if (*(arr + mid) < element){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element not found\n");
}

int main(){
    int choice;
    while (1){
        printf("\nEnter operation to perform-\n");
        printf("1. Read Array\n");
        printf("2. Display Array\n");
        printf("3. Insert element\n");
        printf("4. Delete element\n");
        printf("5. Delete element from position\n");
        printf("6. Search element (Linear Search)\n");
        printf("7. Sort Array\n");
        printf("8. Search element (Binary Search)\n");
        printf("9. quit\n");
        printf("Selection: ");
        scanf("%d", &choice);
        
        if (choice == 9) {
            if (arr != NULL) {
                free(arr);
            }
            return 0;
        }
        if (!(choice > 0 && choice <= 9)){
            printf("Invalid input\n");
            continue; 
        }
        
        switch(choice){
            case 1: {
                int size;
                printf("Enter array length: ");
                scanf("%d", &size);
                readArray(size);
                break;
            }
            case 2: 
                displayArray(); 
                break;
            case 3: {
                int element, position;
                printf("Enter element and position to insert: ");
                scanf("%d %d", &element, &position);
                insertElement(element, position);
                break;
            }
            case 4: {
                int element;
                printf("Enter element to remove: ");
                scanf("%d", &element);
                deleteElement(element);
                break;
            }
            case 5: {
                int position;
                printf("Enter the position of the element to delete: ");
                scanf("%d", &position);
                deleteElementIndex(position);
                break;
            }
            case 6: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                searchElement(element);
                break;
            }
            case 7: {
                sortArray();
                break;
            }
            case 8: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                binarySearchElement(element);
                break;
            }
        }
    }
}
```

</details>

---

## Algorithm Analysis

### Time Complexity Comparison

| Operation | Static Array | Dynamic Array | Notes |
|-----------|--------------|---------------|-------|
| **Access** | O(1) | O(1) | Direct indexing |
| **Linear Search** | O(n) | O(n) | Sequential scan |
| **Binary Search** | O(log n) | O(log n) | Requires sorted array |
| **Insert** | O(n) | O(n) | Element shifting required |
| **Delete** | O(n) | O(n) | Element shifting required |
| **Sort (Bubble)** | O(n²) | O(n²) | Optimized with early termination |

### Space Complexity

| Approach | Space Complexity | Memory Location | Management |
|----------|------------------|-----------------|------------|
| **Static** | O(MAX_SIZE) | Stack | Automatic |
| **Dynamic** | O(n) | Heap | Manual |

### Performance Considerations

1. **Cache Performance**: Static arrays often have better cache locality
2. **Memory Overhead**: Dynamic arrays have allocation overhead
3. **Fragmentation**: Heap allocation can lead to memory fragmentation
4. **Speed**: Stack allocation (static) is generally faster than heap allocation

## Applications

### Real-World Use Cases

#### **Static Arrays:**
- **Embedded Systems**: Microcontroller programming with limited memory
- **Real-time Systems**: Predictable memory usage requirements
- **Mathematical Computations**: Fixed-size matrices and vectors
- **Graphics Programming**: Fixed-size buffers for pixel data

#### **Dynamic Arrays:**
- **Database Systems**: Variable-length records and datasets
- **Text Processing**: Documents with unknown length
- **Image Processing**: Images of varying dimensions
- **Web Applications**: User input of variable size

### Programming Applications

- **Algorithm Implementation**: Sorting, searching, graph algorithms
- **Data Structure Foundation**: Building blocks for stacks, queues, lists
- **String Manipulation**: Character arrays for text processing
- **Numerical Computing**: Mathematical operations on datasets

## Conclusion

Both implementations implement fundamental array operations using different memory management philosophies:

- **Static Implementation**: Ideal for performance-critical applications with predictable memory requirements
- **Dynamic Implementation**: Perfect for flexible applications where memory efficiency and scalability are important


