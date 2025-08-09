#include<stdio.h>
#include<stdlib.h>

void reAllocate(int **arr, int *n, int mode){
    if (*n + mode <= 0) {
        if (*arr != NULL) {
            free(*arr);
            *arr = NULL;
        }
        *n = 0;
        return;
    }
    int *temp = (int *) realloc(*arr, (*n + mode) * sizeof(int));
    if (temp == NULL) {
        printf("\nMemory Allocation failed\n");
        return;
    }
    *arr = temp; 
    *n += mode;
}

void readArray(int **arr, int *n){
    if (*arr != NULL) {
        free(*arr);
        *arr = NULL;
    }
    printf("Enter array length: ");
    scanf("%d",n);
    if (*n <= 0) {
        printf("\nInvalid array length\n");
        *n = 0;
        return;
    }
    *arr = (int *) malloc((*n)*sizeof(int));
    if (*arr == NULL){
        printf("\nMemory Allocation failed\n");
        *n = 0;
        return;
    }
    printf("Enter array elements: ");
    for (int i = 0; i<*n;i++) scanf("%d",*arr+i);
}

void displayArray(int *arr, int n){
    if (arr == NULL || n == 0){
        printf("\nArray is empty. Please read array first.\n");
        return;
    }
    printf("\nCurrent array: ");
    for (int i=0; i<n;i++) printf("%d ", *(arr+i));
    printf("\n");
}

void insertElement(int **arr, int *n){
    if (*arr == NULL || *n == 0){
        printf("\nArray is empty. Please read array first.\n");
        return;
    }
    int x, y;
    printf("Enter element and position to insert: ");
    scanf("%d%d",&x,&y);
    if(!(y>0 && y<=*n+1)){
        printf("\nInvalid position\n");
        return;
    }
    reAllocate(arr,n,1);
    if (*arr == NULL) return; 
    for (int i = *n - 1; i >= y; i--) {
        *(*arr + i) = *(*arr + i - 1);
    }
    *(*arr + y - 1) = x;
    printf("\nElement %d inserted at position %d successfully.\n", x, y);
}

void deleteElement(int **arr, int *n){
    if (*arr == NULL || *n == 0){
        printf("\nArray is empty. Nothing to delete.\n");
        return;
    }
    int x;
    printf("Enter element to remove: ");
    scanf("%d",&x);
    for (int i = 0; i<*n; i++){
        if (*(*arr + i) == x){
            for (int j = i; j<*n-1;j++) {
                *(*arr + j) = *(*arr + j + 1);
            }
            reAllocate(arr,n,-1);
            printf("\nElement %d deleted successfully.\n", x);
            return;
        }
    }
    printf("\nElement not found\n");
}

void deleteElementIndex(int **arr, int *n){
    if (*arr == NULL || *n == 0){
        printf("\nArray is empty. Nothing to delete.\n");
        return;
    }
    int y;
    printf("Enter the position of the element to delete: ");
    scanf("%d", &y);
    if (!(y>0 && y<=*n)){
        printf("\nPosition out of bounds\n");
        return;
    }
    int deletedElement = *(*arr + y - 1);
    for (int j = y-1; j<*n-1;j++) {
        *(*arr + j) = *(*arr + j + 1);
    }
    reAllocate(arr,n,-1);
    printf("\nElement %d at position %d deleted successfully.\n", deletedElement, y);
}

void searchElement(int *arr, int n){
    if (arr == NULL || n == 0){
        printf("\nArray is empty. Please read array first.\n");
        return;
    }
    int x, comparisons = 0;
    printf("Enter the element to search: ");
    scanf("%d", &x);
    for (int i = 0; i<n; i++){
        comparisons++;
        if (*(arr + i) == x){
            printf("\nElement found at position: %d\n", i+1);
            printf("Number of comparisons (Linear Search): %d\n", comparisons);
            return;
        }
    }
    printf("\nElement not found\n");
    printf("Number of comparisons (Linear Search): %d\n", comparisons);
}

void sortArray(int *arr, int n){
    int swapped;
    for (int i = 0; i < n-1; i++){
        swapped = 0; 
        for (int j = 0; j < n-i-1; j++){
            if (*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                swapped = 1; 
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void binarySearchElement(int *arr, int n){
    if (arr == NULL || n == 0){
        printf("\nArray is empty. Please read array first.\n");
        return;
    }
    int x, comparisons = 0;
    printf("Enter the element to search: ");
    scanf("%d", &x);
    sortArray(arr, n);
    printf("\nArray sorted for binary search: ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
    printf("\n");
    int left = 0, right = n - 1;
    while (left <= right){
        comparisons++;
        int mid = left + (right - left) / 2;
        if (*(arr + mid) == x){
            printf("\nElement found at position: %d (in sorted array)\n", mid + 1);
            printf("Number of comparisons (Binary Search): %d\n", comparisons);
            return;
        }
        if (*(arr + mid) < x){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("\nElement not found\n");
    printf("Number of comparisons (Binary Search): %d\n", comparisons);
}

void batchOperation(int **arr, int *n){
    readArray(arr,n);
    displayArray(*arr,*n);
    insertElement(arr,n);
    displayArray(*arr,*n);
    deleteElement(arr,n);
    displayArray(*arr,*n);
    deleteElementIndex(arr,n);
    displayArray(*arr,*n);
    searchElement(*arr,*n);
    binarySearchElement(*arr,*n);
}

int main(){
    int *arr = NULL,n=0,choice;
    while (1){
        printf("\nEnter operation to perform-\n");
        printf("1. Read Array\n");
        printf("2. Display Array\n");
        printf("3. Insert element\n");
        printf("4. Delete element\n");
        printf("5. Delete element from position\n");
        printf("6. Search element (Linear Search)\n");
        printf("7. Search element (Binary Search)\n");
        printf("8. Batch operation(all operations)\n");
        printf("9. quit\n");
        printf("Selection: ");
        scanf("%d",&choice);
        if (choice == 9) {
            if (arr != NULL) {
                free(arr);
            }
            return 0;
        }
        if (!(choice>0 && choice<=9)){
            printf("Invalid input\n");
            continue; 
        }
        switch(choice){
            case 1: readArray(&arr,&n); break;
            case 2: displayArray(arr,n); break;
            case 3: insertElement(&arr,&n); break;
            case 4: deleteElement(&arr,&n); break;
            case 5: deleteElementIndex(&arr,&n); break;
            case 6: searchElement(arr,n); break;
            case 7: binarySearchElement(arr,n); break;
            case 8: batchOperation(&arr,&n); break;
        }
    }
}   