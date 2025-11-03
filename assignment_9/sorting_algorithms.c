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
