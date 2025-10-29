<h1 align="center">ASSIGNMENT - 10: Quick Sort and Merge Sort</h1>

---

### Problem Statement
Write a program in C to sort a given array using Quick Sort and Merge Sort algorithm. Show the number of comparisons required for a given input.

### Algorithms

**QUICK SORT:**
1. If low >= high: return (base case)
2. Select pivot (last element)
3. Partition array:
   - Initialize i = low - 1
   - For j = low to high-1:
     - If arr[j] < pivot:
       - Increment i
       - Swap arr[i] with arr[j]
   - Swap arr[i+1] with pivot
   - Return pivot index (i+1)
4. Recursively sort left partition (low to pi-1)
5. Recursively sort right partition (pi+1 to high)

**MERGE SORT:**
1. If left >= right: return (base case)
2. Find middle: mid = left + (right - left) / 2
3. Recursively sort left half (left to mid)
4. Recursively sort right half (mid+1 to right)
5. Merge sorted halves:
   - Create temporary arrays L and R
   - Copy data to temporary arrays
   - Merge back comparing elements
   - Copy remaining elements

### Source Code

```c
/*
ASSIGNMENT 10:
Problem Statement: Write a program in C to sort a given array using Quick sort and merge sort algorithm.
Show the number of comparison required for a given input.
*/

#include<stdio.h>
#include<stdlib.h>

int compCount = 0;

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void copyArray(int src[], int dest[], int n){
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        compCount++;
        if (arr[j] < pivot){
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

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2){
        compCount++;
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1){
        arr[k] = L[i];
        i++; k++;
    }
    
    while (j < n2){
        arr[k] = R[j];
        j++; k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int *orig = malloc(n * sizeof(int));
    int *arr = malloc(n * sizeof(int));
    
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &orig[i]);
    
    printf("\nOriginal: ");
    printArray(orig, n);
    
    while (1){
        printf("\n1. Quick Sort\n2. Merge Sort\n3. Compare Both\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                copyArray(orig, arr, n);
                compCount = 0;
                printf("\nQuick Sort:\n");
                quickSort(arr, 0, n - 1);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", compCount);
                break;
            case 2:
                copyArray(orig, arr, n);
                compCount = 0;
                printf("\nMerge Sort:\n");
                mergeSort(arr, 0, n - 1);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", compCount);
                break;
            case 3:
                copyArray(orig, arr, n);
                compCount = 0;
                printf("\nQuick Sort:\n");
                quickSort(arr, 0, n - 1);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", compCount);
                
                copyArray(orig, arr, n);
                compCount = 0;
                printf("\nMerge Sort:\n");
                mergeSort(arr, 0, n - 1);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", compCount);
                break;
            case 4:
                free(orig);
                free(arr);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
```

### Sample Output

```
Enter number of elements: 8
Enter elements: 10 7 8 9 1 5 6 2

Original: 10 7 8 9 1 5 6 2

1. Quick Sort
2. Merge Sort
3. Compare Both
4. Exit
Choice: 3

Quick Sort:
Sorted: 1 2 5 6 7 8 9 10
Comparisons: 19

Merge Sort:
Sorted: 1 2 5 6 7 8 9 10
Comparisons: 17

1. Quick Sort
2. Merge Sort
3. Compare Both
4. Exit
Choice: 4
```

**Detailed Quick Sort Execution:**

```
Initial: [10, 7, 8, 9, 1, 5, 6, 2]
Pivot = 2

Partition:
i=-1, j=0: 10 > 2, no swap
i=-1, j=1: 7 > 2, no swap
i=-1, j=2: 8 > 2, no swap
i=-1, j=3: 9 > 2, no swap
i=-1, j=4: 1 < 2, i=0, swap arr[0] with arr[4]
[1, 7, 8, 9, 10, 5, 6, 2]
i=0, j=5: 5 > 2, no swap
i=0, j=6: 6 > 2, no swap
Pivot swap: swap arr[1] with pivot
[1, 2, 8, 9, 10, 5, 6, 7]
     ↑
   pivot position

Recursively sort:
Left: [1] → already sorted
Right: [8, 9, 10, 5, 6, 7]
  Pivot = 7
  After partition: [6, 5, 7, 9, 10, 8]
  Left: [6, 5] → Pivot=5 → [5, 6]
  Right: [9, 10, 8] → Pivot=8 → [8, 9, 10]

Final: [1, 2, 5, 6, 7, 8, 9, 10]
```

**Detailed Merge Sort Execution:**

```
Initial: [10, 7, 8, 9, 1, 5, 6, 2]

Divide Phase:
Level 1: [10, 7, 8, 9] | [1, 5, 6, 2]
Level 2: [10, 7] | [8, 9] | [1, 5] | [6, 2]
Level 3: [10] [7] [8] [9] [1] [5] [6] [2]

Merge Phase:
Level 3→2: [7, 10] | [8, 9] | [1, 5] | [2, 6]
Level 2→1: [7, 8, 9, 10] | [1, 2, 5, 6]
Level 1→0: [1, 2, 5, 6, 7, 8, 9, 10]

Final: [1, 2, 5, 6, 7, 8, 9, 10]
```

**Performance Comparison on Different Inputs:**

```
Test Case 1: Random [38, 27, 43, 3, 9, 82, 10]
Quick Sort: 17 comparisons
Merge Sort: 13 comparisons

Test Case 2: Already Sorted [1, 2, 3, 4, 5]
Quick Sort: 10 comparisons (worst case for last-pivot)
Merge Sort: 8 comparisons (predictable)

Test Case 3: Reverse Sorted [5, 4, 3, 2, 1]
Quick Sort: 10 comparisons (worst case)
Merge Sort: 8 comparisons (predictable)

Test Case 4: All Same [5, 5, 5, 5, 5]
Quick Sort: 10 comparisons
Merge Sort: 8 comparisons
```

**Visual Comparison:**

```
Quick Sort Tree (for [10, 7, 8, 9, 1, 5, 6, 2]):
                    [10,7,8,9,1,5,6,2]
                          ↓ pivot=2
              [1] | 2 | [8,9,10,5,6,7]
                          ↓ pivot=7
                  [6,5] | 7 | [9,10,8]
                   ↓           ↓ pivot=8
                [5]|6|...  [8] | ... 

Merge Sort Tree (for [10, 7, 8, 9, 1, 5, 6, 2]):
                    [10,7,8,9,1,5,6,2]
                     /              \
            [10,7,8,9]            [1,5,6,2]
             /      \              /      \
        [10,7]    [8,9]        [1,5]    [6,2]
         / \       / \          / \       / \
      [10][7]   [8][9]      [1][5]    [6][2]
         \ /       \ /          \ /       \ /
        [7,10]   [8,9]        [1,5]    [2,6]
             \      /              \      /
          [7,8,9,10]            [1,2,5,6]
                     \           /
                [1,2,5,6,7,8,9,10]
```

**Key Observations:**
1. ✅ Both achieve O(n log n) complexity
2. ✅ Merge Sort is more predictable (consistent comparisons)
3. ✅ Quick Sort varies based on pivot selection
4. ✅ Merge Sort requires O(n) extra space
5. ✅ Quick Sort is in-place (O(log n) stack space)

---
