# Basic Sorting Algorithms - Complete Guide

## Table of Contents
- [Introduction to Sorting](#introduction-to-sorting)
- [Bubble Sort](#bubble-sort)
- [Selection Sort](#selection-sort)
- [Insertion Sort](#insertion-sort)
- [Complexity Analysis](#complexity-analysis)
- [Comparison of Algorithms](#comparison-of-algorithms)
- [When to Use Each Algorithm](#when-to-use-each-algorithm)
- [Implementation in this Repository](#implementation-in-this-repository)
- [Best Practices](#best-practices)

## Introduction to Sorting

**Sorting** is the process of arranging data in a particular order (ascending or descending). It is one of the most fundamental operations in computer science.

### Why Sorting Matters

1. **Faster Searching**: Binary search requires sorted data (O(log n) vs O(n))
2. **Data Organization**: Makes data easier to understand and analyze
3. **Algorithm Efficiency**: Many algorithms work better with sorted data
4. **User Experience**: Sorted results are more readable
5. **Duplicate Detection**: Adjacent duplicates in sorted data

### Sorting Terminology

| Term | Definition | Example |
|------|------------|---------|
| **In-place** | Uses O(1) extra space | Bubble, Selection, Insertion |
| **Stable** | Preserves relative order of equal elements | Insertion, Bubble (if implemented correctly) |
| **Adaptive** | Performs better on partially sorted data | Insertion Sort |
| **Comparison** | Number of times elements are compared | Primary complexity metric |

### Performance Metrics

- **Time Complexity**: How running time grows with input size
- **Space Complexity**: Additional memory required
- **Number of Comparisons**: How many times elements are compared
- **Number of Swaps/Shifts**: How many times elements are moved

## Bubble Sort

### Concept

**Bubble Sort** repeatedly steps through the list, compares adjacent elements, and swaps them if they're in the wrong order. Larger elements "bubble up" to the end.

### How It Works

```
Pass 1: [5, 2, 8, 1, 9]
        [2, 5, 8, 1, 9]  (5>2, swap)
        [2, 5, 8, 1, 9]  (5<8, no swap)
        [2, 5, 1, 8, 9]  (8>1, swap)
        [2, 5, 1, 8, 9]  (8<9, no swap)
        → Largest element (9) is now at end

Pass 2: [2, 5, 1, 8, 9]
        [2, 5, 1, 8, 9]  (2<5, no swap)
        [2, 1, 5, 8, 9]  (5>1, swap)
        [2, 1, 5, 8, 9]  (5<8, no swap)
        → Second largest (8) is now in position

Pass 3: [2, 1, 5, 8, 9]
        [1, 2, 5, 8, 9]  (2>1, swap)
        [1, 2, 5, 8, 9]  (2<5, no swap)
        → Array is sorted!
```

### Algorithm

```
bubbleSort(arr[], n):
    for i = 0 to n-2:
        swapped = false
        for j = 0 to n-i-2:
            if arr[j] > arr[j+1]:
                swap(arr[j], arr[j+1])
                swapped = true
        if not swapped:
            break  // Array is sorted
```

### Implementation

```c
int bubbleSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = 1;
            }
        }
        if (!swapped) break;  // Optimization: already sorted
    }
    return comparisons;
}
```

### Characteristics

- **Best Case**: O(n) - Already sorted (with optimization)
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - Reverse sorted
- **Space**: O(1) - In-place
- **Stable**: Yes - Equal elements maintain order
- **Adaptive**: Yes (with optimization flag)

### Advantages

✅ Simple to understand and implement  
✅ No extra space required  
✅ Stable sorting  
✅ Detects sorted arrays quickly (with optimization)  

### Disadvantages

❌ Very slow for large datasets  
❌ O(n²) comparisons in worst case  
❌ Not suitable for practical applications  

## Selection Sort

### Concept

**Selection Sort** divides the array into sorted and unsorted portions. It repeatedly finds the minimum element from the unsorted portion and places it at the beginning.

### How It Works

```
Initial: [64, 25, 12, 22, 11]
         ↑
      unsorted

Pass 1: Find minimum (11) and swap with first
        [11, 25, 12, 22, 64]
         ↑   ↑
      sorted unsorted

Pass 2: Find minimum (12) and swap with second
        [11, 12, 25, 22, 64]
         ↑   ↑   ↑
        sorted  unsorted

Pass 3: Find minimum (22) and swap with third
        [11, 12, 22, 25, 64]
         ↑   ↑   ↑   ↑
          sorted    unsorted

Pass 4: Find minimum (25) - already in place
        [11, 12, 22, 25, 64]
         ↑   ↑   ↑   ↑   ↑
            all sorted
```

### Algorithm

```
selectionSort(arr[], n):
    for i = 0 to n-2:
        minIdx = i
        for j = i+1 to n-1:
            if arr[j] < arr[minIdx]:
                minIdx = j
        if minIdx != i:
            swap(arr[i], arr[minIdx])
```

### Implementation

```c
int selectionSort(int arr[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }
    return comparisons;
}
```

### Characteristics

- **Best Case**: O(n²) - Always performs same comparisons
- **Average Case**: O(n²)
- **Worst Case**: O(n²)
- **Space**: O(1) - In-place
- **Stable**: No - Can change relative order
- **Adaptive**: No - Always O(n²)

### Advantages

✅ Simple implementation  
✅ Minimum number of swaps: O(n)  
✅ Good when memory writes are expensive  
✅ In-place sorting  

### Disadvantages

❌ O(n²) even for best case  
❌ Not stable  
❌ Not adaptive - no benefit for partially sorted data  

## Insertion Sort

### Concept

**Insertion Sort** builds the sorted array one element at a time by inserting each element into its correct position, similar to sorting playing cards in your hand.

### How It Works

```
Initial: [5, 2, 4, 6, 1, 3]
         ↑
      sorted

Pass 1: Insert 2 into sorted portion [5]
        [2, 5, 4, 6, 1, 3]
         ↑  ↑
        sorted

Pass 2: Insert 4 into sorted portion [2, 5]
        [2, 4, 5, 6, 1, 3]
         ↑  ↑  ↑
          sorted

Pass 3: Insert 6 into sorted portion [2, 4, 5]
        [2, 4, 5, 6, 1, 3]
         ↑  ↑  ↑  ↑
            sorted

Pass 4: Insert 1 into sorted portion [2, 4, 5, 6]
        [1, 2, 4, 5, 6, 3]
         ↑  ↑  ↑  ↑  ↑
              sorted

Pass 5: Insert 3 into sorted portion [1, 2, 4, 5, 6]
        [1, 2, 3, 4, 5, 6]
         ↑  ↑  ↑  ↑  ↑  ↑
              all sorted
```

### Algorithm

```
insertionSort(arr[], n):
    for i = 1 to n-1:
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j = j - 1
        arr[j+1] = key
```

### Implementation

```c
int insertionSort(int arr[], int n) {
    int comparisons = 0, shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                shifts++;
            } else break;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}
```

### Characteristics

- **Best Case**: O(n) - Already sorted
- **Average Case**: O(n²)
- **Worst Case**: O(n²) - Reverse sorted
- **Space**: O(1) - In-place
- **Stable**: Yes - Equal elements maintain order
- **Adaptive**: Yes - Efficient for nearly sorted data

### Advantages

✅ Efficient for small datasets  
✅ Efficient for nearly sorted data  
✅ Stable sorting  
✅ Online algorithm - can sort as it receives data  
✅ Simple implementation  

### Disadvantages

❌ O(n²) for large random datasets  
❌ Not suitable for large unsorted arrays  

## Complexity Analysis

### Time Complexity Comparison

| Algorithm | Best Case | Average Case | Worst Case |
|-----------|-----------|--------------|------------|
| **Bubble Sort** | O(n) * | O(n²) | O(n²) |
| **Selection Sort** | O(n²) | O(n²) | O(n²) |
| **Insertion Sort** | O(n) | O(n²) | O(n²) |

\* With early termination optimization

### Space Complexity

All three algorithms are **in-place**: **O(1)** auxiliary space

### Operations Count (for n=5)

| Algorithm | Comparisons (Worst) | Swaps/Shifts (Worst) |
|-----------|---------------------|----------------------|
| **Bubble Sort** | 10 | 10 |
| **Selection Sort** | 10 | 4 |
| **Insertion Sort** | 10 | 10 |

### Empirical Example

**Input**: [5, 2, 8, 1, 9]

| Algorithm | Comparisons | Swaps/Shifts |
|-----------|-------------|--------------|
| Bubble Sort | 10 | 8 |
| Selection Sort | 10 | 4 |
| Insertion Sort | 10 | 8 |

## Comparison of Algorithms

### Performance Characteristics

| Aspect | Bubble | Selection | Insertion |
|--------|--------|-----------|-----------|
| **Simplicity** | Very Simple | Very Simple | Simple |
| **Best for** | Nearly sorted | Minimum writes | Small/Nearly sorted |
| **Stability** | Yes | No | Yes |
| **Adaptivity** | Yes* | No | Yes |
| **Online** | No | No | Yes |

\* With optimization

### Number of Writes

- **Bubble Sort**: O(n²) swaps
- **Selection Sort**: O(n) swaps (minimum!)
- **Insertion Sort**: O(n²) shifts

**Key Insight:** Selection sort is best when writing to memory is expensive

### Practical Behavior

**For n = 10,000 random elements:**

| Algorithm | Comparisons | Time (approx) |
|-----------|-------------|---------------|
| Bubble Sort | ~50M | ~2-3 seconds |
| Selection Sort | ~50M | ~1-2 seconds |
| Insertion Sort | ~25M (avg) | ~1-2 seconds |

## When to Use Each Algorithm

### Use Bubble Sort When:
- ✅ Learning/teaching sorting concepts
- ✅ Array is nearly sorted
- ✅ Need stable sort with no extra space
- ❌ **Don't use for production code!**

### Use Selection Sort When:
- ✅ Memory writes are very expensive
- ✅ Want minimum number of swaps
- ✅ Array is small (< 20 elements)
- ❌ Don't need stability

### Use Insertion Sort When:
- ✅ Array is small (< 50 elements)
- ✅ Array is nearly sorted
- ✅ Need online sorting (streaming data)
- ✅ Need stable sort
- ✅ Part of hybrid sorting (e.g., in TimSort, QuickSort)

### Modern Recommendations:
- **Small arrays**: Insertion Sort
- **Large arrays**: Quick Sort, Merge Sort, Heap Sort
- **Nearly sorted**: Insertion Sort
- **Production**: Use library functions (`qsort()`, `std::sort()`)

## Implementation in this Repository

### File: `sorting_algorithms.c`

**Features:**
- ✅ All three sorting algorithms
- ✅ Comparison counter for each algorithm
- ✅ Swap/shift counter
- ✅ Menu-driven interface
- ✅ Original array preserved for multiple sorts
- ✅ Compare all algorithms simultaneously

**Menu Options:**
1. Bubble Sort (with optimizations)
2. Selection Sort
3. Insertion Sort
4. Compare All Three
5. Exit

**Metrics Displayed:**
- Sorted array
- Number of comparisons
- Number of swaps/shifts
- Easy comparison between algorithms

## Best Practices

### 1. **Choose the Right Algorithm**
```c
if (size < 50 && nearly_sorted) {
    insertionSort();  // Best choice
} else if (memory_writes_expensive) {
    selectionSort();  // Minimum swaps
} else {
    // Use advanced algorithms (Quick/Merge Sort)
}
```

### 2. **Optimize Bubble Sort**
```c
// Always include early termination
if (!swapped) break;
```

### 3. **Handle Edge Cases**
```c
if (n <= 1) return;  // Already sorted
```

### 4. **Count Operations**
```c
// Track comparisons and swaps for analysis
int comparisons = 0, swaps = 0;
```

### 5. **Use for Learning**
These algorithms are excellent for:
- Understanding sorting concepts
- Learning algorithm analysis
- Teaching big-O notation
- Interview preparation

### 6. **Don't Use in Production**
For real applications:
```c
#include <stdlib.h>
qsort(arr, n, sizeof(int), compare);  // Use standard library
```

---

<div align="center">

**💡 Tip:** These basic sorting algorithms are mainly educational. For production code, use optimized algorithms like Quick Sort, Merge Sort, or built-in library functions.

</div>
