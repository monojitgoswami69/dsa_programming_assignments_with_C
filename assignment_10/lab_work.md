<h1 align="center">ASSIGNMENT - 10: Quick Sort and Merge Sort</h1>

---

### Problem Statement
Write a program in C to sort a given array using Quick Sort and Merge Sort algorithm. Show the number of comparisons required for a given input.


### Algorithm

1. START
2. Input `n` (number of elements)
3. Declare arrays: `orig[n]`, `arr1[n]`, `arr2[n]`
4. Input `n` elements into `orig[]`
5. Copy `orig[]` to `arr1[]`, `arr2[]`
6. **Quick Sort** on `arr1[]`:
     - Call `quickSort(arr1, 0, n-1)`
     - `quickSort(arr, low, high)`:
         - If `low < high`:
             - Partition `arr[low..high]` using last element as pivot
             - Recursively quickSort left and right subarrays
     - `partition(arr, low, high)`:
         - Set `pivot = arr[high]`, `i = low-1`
         - For `j = low` to `high-1`:
             - Compare `arr[j]` and `pivot`
             - If `arr[j] < pivot`, increment `i` and swap `arr[i]` and `arr[j]`
         - Swap `arr[i+1]` and `arr[high]`, return `i+1`
     - Count and print comparisons
7. **Merge Sort** on `arr2[]`:
     - Call `mergeSort(arr2, 0, n-1)`
     - `mergeSort(arr, left, right)`:
         - If `left < right`:
             - Find `mid = left + (right-left)/2`
             - Recursively mergeSort left and right halves
             - Merge `arr[left..mid]` and `arr[mid+1..right]`
     - `merge(arr, left, mid, right)`:
         - Create `L[n1]`, `R[n2]` for left and right halves
         - Copy data, merge by comparing, copy remaining
     - Count and print comparisons
8. Print sorted arrays and comparison counts for each sort
9. STOP

### Source Code

```c
/*
ASSIGNMENT 10:
Problem Statement: Write a program in C to sort a given array using Quick sort and merge sort algorithm.
Show the number of comparison required for a given input.
*/

#include<stdio.h>

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
    int L[n1], R[n2];
    
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
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int orig[n], arr1[n], arr2[n];
    
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &orig[i]);
    
    copyArray(orig, arr1, n);
    copyArray(orig, arr2, n);
    
    printf("\nOriginal: ");
    printArray(orig, n);
    
    compCount = 0;
    
    printf("\nQuick Sort:\n");
    quickSort(arr1, 0, n - 1);
    printf("Sorted: ");
    printArray(arr1, n);
    printf("Comparisons: %d\n", compCount);
    
    compCount = 0;
    printf("\nMerge Sort:\n");
    mergeSort(arr2, 0, n - 1);
    printf("Sorted: ");
    printArray(arr2, n);
    printf("Comparisons: %d\n", compCount);
    
    return 0;
}
```

### Sample Output

```
Enter number of elements: 6
Enter elements: 64 34 25 12 22 11

Original: 64 34 25 12 22 11

Quick Sort:
Sorted: 11 12 22 25 34 64
Comparisons: 15

Merge Sort:
Sorted: 11 12 22 25 34 64
Comparisons: 13
```

