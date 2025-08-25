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