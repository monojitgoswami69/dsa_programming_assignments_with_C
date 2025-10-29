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
