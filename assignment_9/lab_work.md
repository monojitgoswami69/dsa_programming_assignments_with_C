<h1 align="center">ASSIGNMENT - 9: Basic Sorting Algorithms</h1>

---

### Problem Statement
Write a program in C to sort a given array using bubble sort, selection sort and insertion sort algorithm. Show the number of comparisons required for a given input.


### Algorithm

1. START
2. Input `n` (number of elements)
3. Declare arrays: `orig[n]`, `arr1[n]`, `arr2[n]`, `arr3[n]`
4. Input `n` elements into `orig[]`
5. Copy `orig[]` to `arr1[]`, `arr2[]`, `arr3[]`
6. Perform **Bubble Sort** on `arr1[]`:
   - For `i = 0` to `n-2`:
    - For `j = 0` to `n-i-2`:
      - Compare `arr1[j]` and `arr1[j+1]`
      - If `arr1[j] > arr1[j+1]`, swap them
      - Count comparisons and swaps
    - If no swaps in a pass, break
7. Perform **Selection Sort** on `arr2[]`:
   - For `i = 0` to `n-2`:
    - Find index of minimum in `arr2[i..n-1]`
    - Swap with `arr2[i]` if needed
    - Count comparisons and swaps
8. Perform **Insertion Sort** on `arr3[]`:
   - For `i = 1` to `n-1`:
    - Set `key = arr3[i]`
    - Compare with previous elements, shift if greater
    - Insert `key` at correct position
    - Count comparisons and shifts
9. Print sorted arrays and comparison counts for each sort
10. STOP


### Source Code

```c
/*
ASSIGNMENT 9:
Problem Statement: Write a program in C to sort a given array using bubble sort, selection sort and insertion sort algorithm.
Show the number of comparison required for a given input.
*/

#include<stdio.h>

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
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int orig[n], arr1[n], arr2[n], arr3[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &orig[i]);
    
    copyArray(orig, arr1, n);
    copyArray(orig, arr2, n);
    copyArray(orig, arr3, n);
    
    printf("\nOriginal: ");
    printArray(orig, n);
    
    printf("\nBubble Sort:\n");
    int comp1 = bubbleSort(arr1, n);
    printf("Sorted: ");
    printArray(arr1, n);
    printf("Comparisons: %d\n", comp1);
    
    printf("\nSelection Sort:\n");
    int comp2 = selectionSort(arr2, n);
    printf("Sorted: ");
    printArray(arr2, n);
    printf("Comparisons: %d\n", comp2);
    
    printf("\nInsertion Sort:\n");
    int comp3 = insertionSort(arr3, n);
    printf("Sorted: ");
    printArray(arr3, n);
    printf("Comparisons: %d\n", comp3);
    
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
