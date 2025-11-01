<h1 align="center">ASSIGNMENT - 1: Array Operations</h1>

<div align="center" id="index">
  <h2>Table of Contents</h2>
</div>

<div align="center">

| **Implementation** |
|---|
| [**#1** Static Array Allocation](#implementation1) |
| [**#2** Dynamic Array Allocation](#implementation2) |

</div>

---

> **Note:** You can write **any one** of the following implementations for your lab work.

---

<a id="implementation1"></a>
## 1. Array Operations - Static Memory Allocation

### Problem Statement
Write a menu driven program to perform the following operations on an array.
- (a) insert an element x at position k in the array.
- (b) remove an element x from the array.
- (c) search an element x from the array using linear search (check no. of comparison).
- (d) search an element x from the array using binary search (check no. of comparison).
- (e) display the array.

### Algorithm

1. **Start**
2. **Initialize**:
   - Declare a static array `arr[MAX_SIZE]` (MAX_SIZE = 100).
   - Set `n = 0` (current size of the array).
3. **Display Menu**:
   - Present the user with the following options:
     1. Read Array
     2. Insert Element at Position
     3. Remove Element by Value
     4. Search Element (Linear Search)
     5. Search Element (Binary Search)
     6. Display Array
     7. Quit
4. **Perform Operations Based on User Choice**:
   - **Read Array**:
     - Accept the size of the array from the user.
     - Validate the size: `1 <= size <= MAX_SIZE`.
     - Read `size` elements into `arr`.
     - Update `n = size`.
   - **Insert Element at Position**:
     - Validate the position: `1 <= position <= n + 1`.
     - Shift elements from `position-1` to `n-1` one position to the right.
     - Insert the new element at `arr[position-1]`.
     - Increment `n`.
   - **Remove Element by Value**:
     - Search for the element in the array.
     - If found, shift all elements after the element one position to the left.
     - Decrement `n`.
     - If not found, display an appropriate message.
   - **Search Element (Linear Search)**:
     - Traverse the array and compare each element with the target.
     - Count the number of comparisons.
     - If found, display the position and the number of comparisons.
     - If not found, display an appropriate message.
   - **Search Element (Binary Search)**:
     - Sort the array using Bubble Sort.
     - Perform binary search on the sorted array:
       - Initialize `left = 0`, `right = n-1`.
       - While `left <= right`:
         - Compute `mid = left + (right - left) / 2`.
         - Compare the middle element with the target.
         - Adjust `left` or `right` based on the comparison.
         - Count the number of comparisons.
       - If found, display the position and the number of comparisons.
       - If not found, display an appropriate message.
   - **Display Array**:
     - Traverse the array and print each element.
   - **Quit**:
     - Exit the program.
5. **Repeat** until the user chooses to quit.
6. **Stop**

### Source Code

```c
// Updated Static Array Implementation
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

void searchElement(int element){
    if (n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    int comparisons = 0;
    for (int i = 0; i < n; i++){
        comparisons++;
        if (arr[i] == element){
            printf("Element found at position: %d\n", i + 1);
            printf("Linear Search - Number of comparisons: %d\n", comparisons);
            return;
        }
    }
    printf("Element not found\n");
    printf("Linear Search - Number of comparisons: %d\n", comparisons);
}

void binarySearchElement(int element){
    if (n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    // Sort array internally
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
    printf("Array sorted for binary search: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int comparisons = 0;
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == element){
            printf("Element found at position: %d (in sorted array)\n", mid + 1);
            printf("Binary Search - Number of comparisons: %d\n", comparisons);
            return;
        }
        if (arr[mid] < element){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element not found\n");
    printf("Binary Search - Number of comparisons: %d\n", comparisons);
}

int main(){
    int choice;
    
    while (1){
        printf("\nEnter operation to perform-\n");
        printf("1. Read Array\n");
        printf("2. Insert element at position\n");
        printf("3. Remove element\n");
        printf("4. Search element (Linear Search)\n");
        printf("5. Search element (Binary Search)\n");
        printf("6. Display Array\n");
        printf("7. Quit\n");
        printf("Selection: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: {
                int size;
                printf("Enter array length: ");
                scanf("%d", &size);
                readArray(size);
                break;
            }
            case 2: {
                int element, position;
                printf("Enter element and position to insert: ");
                scanf("%d %d", &element, &position);
                insertElement(element, position);
                break;
            }
            case 3: {
                int element;
                printf("Enter element to remove: ");
                scanf("%d", &element);
                deleteElement(element);
                break;
            }
            case 4: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                searchElement(element);
                break;
            }
            case 5: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                binarySearchElement(element);
                break;
            }
            case 6: 
                displayArray(); 
                break;
            case 7: {
                return 0;
            }
            default: {
                printf("Invalid input\n");
                break;
            }
        }
    }
}
```

### Sample Output

```
Enter operation to perform-
1. Read Array
2. Insert element at position
3. Remove element
4. Search element (Linear Search)
5. Search element (Binary Search)
6. Display Array
7. Quit
Selection: 1
Enter array length: 5
Enter array elements: 10 20 30 40 50
Array read successfully.

Selection: 6
Current array: 10 20 30 40 50 

Selection: 2
Enter element and position to insert: 25 3
Element 25 inserted at position 3 successfully.

Selection: 6
Current array: 10 20 25 30 40 50 

Selection: 4
Enter the element to search: 30
Element found at position: 4
Linear Search - Number of comparisons: 4

Selection: 3
Enter element to remove: 25
Element 25 deleted successfully.

Selection: 6
Current array: 10 20 30 40 50 

Selection: 5
Enter the element to search: 40
Array sorted for binary search: 10 20 30 40 50 
Element found at position: 4 (in sorted array)
Binary Search - Number of comparisons: 1

Selection: 7
```

<div align="right"><a href="#index">return to index</a></div><hr>

<a id="implementation2"></a>
## 2. Array Operations - Dynamic Memory Allocation

### Problem Statement
Write a menu driven program to perform the following operations on an array using dynamic memory allocation.
- (a) insert an element x at position k in the array.
- (b) remove an element x from the array.
- (c) search an element x from the array using linear search (check no. of comparison).
- (d) search an element x from the array using binary search (check no. of comparison).
- (e) display the array.

### Algorithm

1. **Start**
2. **Initialize**:
   - Declare a dynamic array pointer: `int *arr = NULL`.
   - Set `n = 0` (current size of the array).
3. **Display Menu**:
   - Present the user with the following options:
     1. Read Array
     2. Insert Element at Position
     3. Remove Element by Value
     4. Search Element (Linear Search)
     5. Search Element (Binary Search)
     6. Display Array
     7. Quit
4. **Perform Operations Based on User Choice**:
   - **Read Array**:
     - If `arr != NULL`, free existing memory.
     - Accept the size of the array from the user.
     - Validate the size: `size > 0`.
     - Allocate memory: `arr = (int *) malloc(size * sizeof(int))`.
     - Check if allocation was successful.
     - If successful:
       - Set `n = size`.
       - Read `n` elements into `arr`.
   - **Insert Element at Position**:
     - Check if the array is empty.
     - Validate the position: `1 <= position <= n + 1`.
     - Reallocate memory to increase the size: `temp = (int *) realloc(arr, (n + 1) * sizeof(int))`.
     - Check if reallocation was successful.
     - If successful:
       - Update `arr = temp`, `n = n + 1`.
       - Shift elements from `position-1` to `n-1` one position to the right.
       - Insert the new element at `arr[position-1]`.
   - **Remove Element by Value**:
     - Check if the array is empty.
     - Search for the element in the array.
     - If found:
       - Shift all elements after the element one position to the left.
       - Reallocate memory to decrease the size.
     - If not found, display an appropriate message.
   - **Remove Element by Position**:
     - Check if the array is empty.
     - Validate the position: `1 <= position <= n`.
     - Store the element to be deleted.
     - Shift all elements after the position one position to the left.
     - Reallocate memory to decrease the size.
     - Display the deleted element.
   - **Search Element (Linear Search)**:
     - Check if the array is empty.
     - Initialize `comparisons = 0`.
     - Traverse the array and compare each element with the target.
     - Count the number of comparisons.
     - If found, display the position and the number of comparisons.
     - If not found, display an appropriate message.
   - **Sort Array (Bubble Sort)**:
     - Check if the array is empty.
     - For `i = 0` to `n-2`:
       - Set `swapped = 0`.
       - For `j = 0` to `n-i-2`:
         - If `*(arr + j) > *(arr + j + 1)`:
           - Swap using pointer arithmetic.
           - Set `swapped = 1`.
       - If `swapped == 0`, break.
     - Display "Array sorted successfully".
   - **Search Element (Binary Search)**:
     - Check if the array is empty.
     - Sort the array first.
     - Display the sorted array.
     - Initialize `left = 0`, `right = n-1`, `comparisons = 0`.
     - While `left <= right`:
       - Calculate `mid = left + (right - left) / 2`.
       - Increment comparisons.
       - If `*(arr + mid) == element`:
         - Display the position and the number of comparisons.
         - Return.
       - Else if `*(arr + mid) < element`: `left = mid + 1`.
       - Else: `right = mid - 1`.
     - If not found, display an appropriate message.
5. **Quit**:
    - Free allocated memory: `free(arr)`.
    - Set `arr = NULL`.
6. **Repeat** until the user chooses to quit.
7. **Stop**

### Source Code

```c
/*
ASSIGNMENT 1:
Problem Statement: Write a menu driven program to perform the following operations on an array.
(a) insert an element x at position k in the array.
(b) remove an element x from the array.
(c) search an element x from the array using linear search(check no. of comparison).
(d) search an element x from the array using binary search(check no. of comparison).
(e) display the array.
*/

#include<stdio.h>
#include<stdlib.h>

int *arr = NULL;
int n = 0;

void reAllocate(int mode){
    if (n + mode <= 0) {
        if (arr != NULL) {
            free(arr);
            arr = NULL;
        }
        n = 0;
        return;
    }
    int *temp = (int *) realloc(arr, (n + mode) * sizeof(int));
    if (temp == NULL) {
        printf("Memory Allocation failed\n");
        return;
    }
    arr = temp; 
    n += mode;
}

void readArray(int size){
    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }
    if (size <= 0) {
        printf("Invalid array length\n");
        n = 0;
        return;
    }
    arr = (int *) malloc(size * sizeof(int));
    if (arr == NULL){
        printf("Memory Allocation failed\n");
        n = 0;
        return;
    }
    n = size;
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    printf("Array read successfully.\n");
}

void displayArray(){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    printf("Current array: ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
    printf("\n");
}

void insertElement(int element, int position){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    if (!(position > 0 && position <= n + 1)){
        printf("Invalid position\n");
        return;
    }
    reAllocate(1);
    if (arr == NULL) return; 
    for (int i = n - 1; i >= position; i--) {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + position - 1) = element;
    printf("Element %d inserted at position %d successfully.\n", element, position);
}

void deleteElement(int element){
    if (arr == NULL || n == 0){
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    for (int i = 0; i < n; i++){
        if (*(arr + i) == element){
            for (int j = i; j < n - 1; j++) {
                *(arr + j) = *(arr + j + 1);
            }
            reAllocate(-1);
            printf("Element %d deleted successfully.\n", element);
            return;
        }
    }
    printf("Element not found\n");
}

void deleteElementIndex(int position){
    if (arr == NULL || n == 0){
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    if (!(position <= n && position >= 1)){
        printf("Position out of bounds\n");
        return;
    }
    int deletedElement = *(arr + position - 1);
    for (int j = position - 1; j < n - 1; j++) {
        *(arr + j) = *(arr + j + 1);
    }
    reAllocate(-1);
    printf("Element %d at position %d deleted successfully.\n", deletedElement, position);
}

void searchElement(int element){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    int comparisons = 0;
    for (int i = 0; i < n; i++){
        comparisons++;
        if (*(arr + i) == element){
            printf("Element found at position: %d\n", i + 1);
            printf("Linear Search - Number of comparisons: %d\n", comparisons);
            return;
        }
    }
    printf("Element not found\n");
    printf("Linear Search - Number of comparisons: %d\n", comparisons);
}

void sortArray(){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    int swapped;
    for (int i = 0; i < n - 1; i++){
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++){
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
    printf("Array sorted successfully\n");
}

void binarySearchElement(int element){
    if (arr == NULL || n == 0){
        printf("Array is empty. Please read array first.\n");
        return;
    }
    sortArray();
    
    printf("Array sorted for binary search: ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
    printf("\n");
    
    int comparisons = 0;
    int left = 0, right = n - 1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        comparisons++;
        if (*(arr + mid) == element){
            printf("Element found at position: %d (in sorted array)\n", mid + 1);
            printf("Binary Search - Number of comparisons: %d\n", comparisons);
            return;
        }
        if (*(arr + mid) < element){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element not found\n");
    printf("Binary Search - Number of comparisons: %d\n", comparisons);
}

int main(){
    int choice;
    
    while (1){
        printf("\nEnter operation to perform-\n");
        printf("1. Read Array\n");
        printf("2. Insert element at position\n");
        printf("3. Remove element\n");
        printf("4. Search element (Linear Search)\n");
        printf("5. Search element (Binary Search)\n");
        printf("6. Display Array\n");
        printf("7. Quit\n");
        printf("Selection: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: {
                int size;
                printf("Enter array length: ");
                scanf("%d", &size);
                readArray(size);
                break;
            }
            case 2: {
                int element, position;
                printf("Enter element and position to insert: ");
                scanf("%d %d", &element, &position);
                insertElement(element, position);
                break;
            }
            case 3: {
                int element;
                printf("Enter element to remove: ");
                scanf("%d", &element);
                deleteElement(element);
                break;
            }
            case 4: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                searchElement(element);
                break;
            }
            case 5: {
                int element;
                printf("Enter the element to search: ");
                scanf("%d", &element);
                binarySearchElement(element);
                break;
            }
            case 6: 
                displayArray(); 
                break;
            case 7: {
                if (arr != NULL) {
                    free(arr);
                }
                return 0;
            }
            default: {
                printf("Invalid input\n");
                break;
            }
        }
    }
}
```

### Sample Output

```
Enter operation to perform-
1. Read Array
2. Insert element at position
3. Remove element
4. Search element (Linear Search)
5. Search element (Binary Search)
6. Display Array
7. Quit
Selection: 1
Enter array length: 4
Enter array elements: 15 25 35 45
Array read successfully.

Selection: 6
Current array: 15 25 35 45 

Selection: 2
Enter element and position to insert: 30 3
Element 30 inserted at position 3 successfully.

Selection: 6
Current array: 15 25 30 35 45 

Selection: 4
Enter the element to search: 35
Element found at position: 4
Linear Search - Number of comparisons: 4

Selection: 3
Enter the position of the element to delete: 3
Element 30 at position 3 deleted successfully.

Selection: 6
Current array: 15 25 35 45 

Selection: 5
Enter the element to search: 25
Array sorted for binary search: 15 25 35 45 
Element found at position: 2 (in sorted array)
Binary Search - Number of comparisons: 2

Selection: 7
```

<div align="right"><a href="#index">return to index</a></div><hr>
