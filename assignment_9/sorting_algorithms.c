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
