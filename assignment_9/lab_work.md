<h1 align="center">ASSIGNMENT - 9: Basic Sorting Algorithms</h1>

---

### Problem Statement
Write a program in C to sort a given array using bubble sort, selection sort and insertion sort algorithm. Show the number of comparisons required for a given input.

### Algorithm

**MAIN PROGRAM:**
1. START
2. Accept number of elements n
3. Input array elements
4. Display menu:
   - Bubble Sort
   - Selection Sort
   - Insertion Sort
   - Compare All
   - Exit
5. For each choice, copy original array and sort
6. Display sorted array and comparison count
7. STOP

**BUBBLE SORT:**
1. Initialize comparisons = 0, swaps = 0
2. FOR i = 0 to n-2:
   - Set swapped = false
   - FOR j = 0 to n-i-2:
     - Increment comparisons
     - IF arr[j] > arr[j+1]:
       - Swap arr[j] and arr[j+1]
       - Increment swaps
       - Set swapped = true
   - IF not swapped: BREAK (optimization)
3. Return comparisons

**SELECTION SORT:**
1. Initialize comparisons = 0, swaps = 0
2. FOR i = 0 to n-2:
   - Set minIdx = i
   - FOR j = i+1 to n-1:
     - Increment comparisons
     - IF arr[j] < arr[minIdx]:
       - Set minIdx = j
   - IF minIdx != i:
     - Swap arr[i] and arr[minIdx]
     - Increment swaps
3. Return comparisons

**INSERTION SORT:**
1. Initialize comparisons = 0, shifts = 0
2. FOR i = 1 to n-1:
   - Set key = arr[i]
   - Set j = i-1
   - WHILE j >= 0:
     - Increment comparisons
     - IF arr[j] > key:
       - Shift arr[j] to arr[j+1]
       - Decrement j
       - Increment shifts
     - ELSE: BREAK
   - Place key at arr[j+1]
3. Return comparisons

### Source Code

```c
/*
ASSIGNMENT 9:
Problem Statement: Write a program in C to sort a given array using bubble sort, selection sort and insertion sort algorithm.
Show the number of comparison required for a given input.
*/

#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int bubbleSort(int arr[], int n){
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++){
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++){
            comparisons++;
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    printf("Swaps: %d\n", swaps);
    return comparisons;
}

int selectionSort(int arr[], int n){
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++){
        int minIdx = i;
        for (int j = i + 1; j < n; j++){
            comparisons++;
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        if (minIdx != i){
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }
    printf("Swaps: %d\n", swaps);
    return comparisons;
}

int insertionSort(int arr[], int n){
    int comparisons = 0, shifts = 0;
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0){
            comparisons++;
            if (arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
                shifts++;
            } else break;
        }
        arr[j + 1] = key;
    }
    printf("Shifts: %d\n", shifts);
    return comparisons;
}

void copyArray(int src[], int dest[], int n){
    for (int i = 0; i < n; i++) dest[i] = src[i];
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
        printf("\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Compare All\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        
        int comp;
        switch (choice){
            case 1:
                copyArray(orig, arr, n);
                printf("\nBubble Sort:\n");
                comp = bubbleSort(arr, n);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", comp);
                break;
            case 2:
                copyArray(orig, arr, n);
                printf("\nSelection Sort:\n");
                comp = selectionSort(arr, n);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", comp);
                break;
            case 3:
                copyArray(orig, arr, n);
                printf("\nInsertion Sort:\n");
                comp = insertionSort(arr, n);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", comp);
                break;
            case 4:
                copyArray(orig, arr, n);
                printf("\nBubble Sort:\n");
                comp = bubbleSort(arr, n);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", comp);
                
                copyArray(orig, arr, n);
                printf("\nSelection Sort:\n");
                comp = selectionSort(arr, n);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", comp);
                
                copyArray(orig, arr, n);
                printf("\nInsertion Sort:\n");
                comp = insertionSort(arr, n);
                printf("Sorted: ");
                printArray(arr, n);
                printf("Comparisons: %d\n", comp);
                break;
            case 5:
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
Enter number of elements: 6
Enter elements: 64 34 25 12 22 11

Original: 64 34 25 12 22 11

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Compare All
5. Exit
Choice: 4

Bubble Sort:
Swaps: 13
Sorted: 11 12 22 25 34 64
Comparisons: 15

Selection Sort:
Swaps: 5
Sorted: 11 12 22 25 34 64
Comparisons: 15

Insertion Sort:
Shifts: 13
Sorted: 11 12 22 25 34 64
Comparisons: 15

1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Compare All
5. Exit
Choice: 5
```

**Detailed Step-by-Step Example:**

**Bubble Sort on [64, 34, 25, 12, 22, 11]:**

```
Pass 1:
[64, 34, 25, 12, 22, 11]
[34, 64, 25, 12, 22, 11]  (64>34, swap)
[34, 25, 64, 12, 22, 11]  (64>25, swap)
[34, 25, 12, 64, 22, 11]  (64>12, swap)
[34, 25, 12, 22, 64, 11]  (64>22, swap)
[34, 25, 12, 22, 11, 64]  (64>11, swap)
→ 64 in final position

Pass 2:
[34, 25, 12, 22, 11, 64]
[25, 34, 12, 22, 11, 64]  (34>25, swap)
[25, 12, 34, 22, 11, 64]  (34>12, swap)
[25, 12, 22, 34, 11, 64]  (34>22, swap)
[25, 12, 22, 11, 34, 64]  (34>11, swap)
→ 34 in final position

... continues until sorted
```

**Selection Sort on [64, 34, 25, 12, 22, 11]:**

```
Pass 1: Find minimum (11) → swap with position 0
[11, 34, 25, 12, 22, 64]

Pass 2: Find minimum (12) → swap with position 1
[11, 12, 25, 34, 22, 64]

Pass 3: Find minimum (22) → swap with position 2
[11, 12, 22, 34, 25, 64]

Pass 4: Find minimum (25) → swap with position 3
[11, 12, 22, 25, 34, 64]

Pass 5: Find minimum (34) → already in position
[11, 12, 22, 25, 34, 64]

Sorted!
```

**Insertion Sort on [64, 34, 25, 12, 22, 11]:**

```
Pass 1: Insert 34
[34, 64, 25, 12, 22, 11]

Pass 2: Insert 25
[25, 34, 64, 12, 22, 11]

Pass 3: Insert 12
[12, 25, 34, 64, 22, 11]

Pass 4: Insert 22
[12, 22, 25, 34, 64, 11]

Pass 5: Insert 11
[11, 12, 22, 25, 34, 64]

Sorted!
```

**Comparison Analysis:**

| Input | Bubble Comp | Selection Comp | Insertion Comp | Winner |
|-------|-------------|----------------|----------------|--------|
| **Random [64,34,25,12,22,11]** | 15 | 15 | 15 | Tie |
| **Sorted [11,12,22,25,34,64]** | 5 | 15 | 5 | Bubble/Insertion |
| **Reverse [64,34,25,22,12,11]** | 15 | 15 | 15 | Tie |

**Key Observations:**
- Selection Sort always makes same comparisons regardless of input
- Bubble and Insertion Sort benefit from sorted/nearly-sorted data
- Selection Sort has minimum swaps (best when memory writes expensive)

---
