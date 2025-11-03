# Advanced Sorting Algorithms - Quick Sort and Merge Sort

## Table of Contents
- [Introduction](#introduction)
- [Quick Sort](#quick-sort)
- [Merge Sort](#merge-sort)
- [Complexity Analysis](#complexity-analysis)
- [Comparison](#comparison)
- [Best Practices](#best-practices)

## Introduction

**Advanced Sorting Algorithms** use divide-and-conquer strategy to achieve better time complexity than basic algorithms. Quick Sort and Merge Sort are two of the most important sorting algorithms in computer science.

### Why Advanced Algorithms?

| Aspect | Basic Sorts | Advanced Sorts |
|--------|-------------|----------------|
| **Time Complexity** | O(n²) | O(n log n) |
| **Practical Speed** | Slow for large data | Fast for any size |
| **Use Cases** | Learning, tiny arrays | Production code |
| **Real-world** | Rarely used | Used everywhere |

### Divide and Conquer

Both algorithms follow this paradigm:
1. **Divide**: Break problem into smaller subproblems
2. **Conquer**: Recursively solve subproblems
3. **Combine**: Merge solutions to get final answer

## Quick Sort

### Concept

Quick Sort selects a 'pivot' element and partitions the array so that:
- Elements smaller than pivot are on the left
- Elements larger than pivot are on the right
- Recursively sort both partitions

### How It Works

```
Array: [10, 7, 8, 9, 1, 5]
Pivot: 5 (last element)

Partition:
[10, 7, 8, 9, 1, 5]
 i=-1           pivot

Compare 10 > 5: no swap, i stays -1
Compare 7 > 5: no swap, i stays -1
Compare 8 > 5: no swap, i stays -1
Compare 9 > 5: no swap, i stays -1
Compare 1 < 5: i++, swap arr[0] with arr[4]
[1, 7, 8, 9, 10, 5]
 i=0

Place pivot: swap arr[i+1] with pivot
[1, 5, 8, 9, 10, 7]
    ↑
  pivot position

Recursively sort:
Left: [1]  (already sorted)
Right: [8, 9, 10, 7] → continue sorting
```

### Algorithm

```
quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)

partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j = low to high-1:
        if arr[j] < pivot:
            i++
            swap(arr[i], arr[j])
    swap(arr[i+1], arr[high])
    return i+1
```

### Implementation

```c
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        compCount++;
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

### Characteristics

- **Best Case**: O(n log n) - Balanced partitions
- **Average Case**: O(n log n)
- **Worst Case**: O(n²) - Already sorted with bad pivot
- **Space**: O(log n) - Recursion stack
- **Stable**: No
- **In-place**: Yes

### Advantages

✅ Fastest in practice for average case  
✅ In-place (doesn't need extra array)  
✅ Cache-friendly (good locality)  
✅ Used in standard libraries (qsort)  

### Disadvantages

❌ O(n²) worst case  
❌ Not stable  
❌ Recursive (stack overflow risk)  

### Pivot Selection Strategies

1. **Last Element**: Simple but bad for sorted data
2. **First Element**: Bad for sorted data
3. **Middle Element**: Better than first/last
4. **Random Element**: Avoids worst case
5. **Median-of-Three**: Best practical choice

## Merge Sort

### Concept

Merge Sort divides the array into halves, recursively sorts them, and merges the sorted halves back together.

### How It Works

```
Array: [38, 27, 43, 3, 9, 82, 10]

Divide Phase:
[38, 27, 43, 3, 9, 82, 10]
        ↓
[38, 27, 43, 3] | [9, 82, 10]
        ↓                ↓
[38, 27] | [43, 3]   [9, 82] | [10]
    ↓         ↓           ↓        ↓
[38] [27] [43] [3]    [9] [82]  [10]

Merge Phase:
[27, 38] | [3, 43]   [9, 82] | [10]
        ↓                ↓
[3, 27, 38, 43]  | [9, 10, 82]
        ↓
[3, 9, 10, 27, 38, 43, 82]
```

### Algorithm

```
mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) / 2
        mergeSort(arr, left, mid)
        mergeSort(arr, mid+1, right)
        merge(arr, left, mid, right)

merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    Create temp arrays L[n1] and R[n2]
    Copy data to temp arrays
    Merge temp arrays back to arr[left..right]
```

### Implementation

```c
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        compCount++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

### Characteristics

- **Best Case**: O(n log n)
- **Average Case**: O(n log n)
- **Worst Case**: O(n log n) - Guaranteed!
- **Space**: O(n) - Needs extra array
- **Stable**: Yes
- **In-place**: No

### Advantages

✅ **Guaranteed O(n log n)** - No worst case  
✅ **Stable** - Maintains relative order  
✅ **Predictable** - Always same performance  
✅ **Good for linked lists** - No random access needed  
✅ **External sorting** - Works with disk storage  

### Disadvantages

❌ O(n) extra space required  
❌ Not in-place  
❌ Slower than Quick Sort in practice  

## Complexity Analysis

### Time Complexity

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) |
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) |

### Why O(n log n)?

**Divide and Conquer Analysis:**
- **Levels**: log₂(n) levels of recursion
- **Work per level**: O(n) comparisons/merges
- **Total**: O(n) × O(log n) = **O(n log n)**

**Example for n=8:**
```
Level 0:     [8 elements]           ← n work
Level 1:    [4] [4]                 ← n work
Level 2:   [2][2][2][2]             ← n work
Level 3:  [1][1][1][1][1][1][1][1]  ← n work

Total levels = log₂(8) = 3
Work = 3 × 8 = 24 operations
```

### Practical Performance

**For n = 100,000 elements:**

| Algorithm | Comparisons | Time (approx) |
|-----------|-------------|---------------|
| Bubble Sort | ~5,000,000,000 | Minutes |
| Insertion Sort | ~2,500,000,000 | Minutes |
| Quick Sort | ~1,660,000 | < 1 second |
| Merge Sort | ~1,660,000 | < 1 second |

## Comparison

### Quick Sort vs Merge Sort

| Aspect | Quick Sort | Merge Sort |
|--------|------------|------------|
| **Worst Case** | O(n²) | O(n log n) ✓ |
| **Space** | O(log n) ✓ | O(n) |
| **Stable** | No | Yes ✓ |
| **In-place** | Yes ✓ | No |
| **Cache** | Better ✓ | Worse |
| **Practical Speed** | Faster ✓ | Slower |
| **Predictable** | No | Yes ✓ |
| **Linked Lists** | Harder | Natural ✓ |

### When to Use Each

**Use Quick Sort when:**
- ✅ Average case performance matters most
- ✅ Memory is limited (in-place)
- ✅ Working with arrays
- ✅ Stability not required
- ✅ Cache performance critical

**Use Merge Sort when:**
- ✅ Guaranteed O(n log n) required
- ✅ Stability needed
- ✅ Working with linked lists
- ✅ External sorting (disk-based)
- ✅ Parallel processing possible

### Real-World Usage

- **C stdlib qsort()**: Quick Sort variant
- **Java Arrays.sort()**: Dual-pivot Quick Sort (primitives), Tim Sort (objects)
- **Python sort()**: Tim Sort (Merge + Insertion hybrid)
- **C++ std::sort()**: Intro Sort (Quick + Heap + Insertion hybrid)

## Best Practices

### 1. **Choose Appropriately**
```c
if (need_stability) {
    mergeSort();
} else if (memory_limited) {
    quickSort();
} else {
    // Quick Sort usually faster
    quickSort();
}
```

### 2. **Optimize Quick Sort**
```c
// Use median-of-three pivot
int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    // Return median of arr[low], arr[mid], arr[high]
}

// Use insertion sort for small subarrays
if (high - low < 10) {
    insertionSort(arr, low, high);
    return;
}
```

### 3. **Handle Edge Cases**
```c
if (left >= right) return;  // Base case
```

### 4. **Avoid Stack Overflow**
```c
// Tail recursion optimization for Quick Sort
// Sort smaller partition first
if (pi - low < high - pi) {
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
} else {
    quickSort(arr, pi + 1, high);
    quickSort(arr, low, pi - 1);
}
```

### 5. **Memory Management**
```c
// Always free allocated memory in Merge Sort
free(L);
free(R);
```

---

<div align="center">

**💡 Tip:** For most practical applications, use library sorting functions. Implement these algorithms to understand the concepts, not for production use.

</div>
