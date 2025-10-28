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

> ### **Note** 
> - All programs include problem statement, algorithm, source code, and sample outputs
> - **You can write any one of the following implementations** for your lab work

<hr>

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

1. START
2. Declare static array `arr[MAX_SIZE]` with fixed size (MAX_SIZE = 100)
3. Initialize `n = 0` (current size of array)
4. Display menu with options and accept user choice
5. **For Read Array**:
   - Accept size from user
   - Validate size: `size > 0 AND size <= MAX_SIZE`
   - Accept `size` number of elements
   - Store in array: `arr[0]` to `arr[size-1]`
   - Set `n = size`
6. **For Display Array**:
   - Check if array is empty (`n == 0`)
   - If not empty, traverse from `i = 0` to `i = n-1`
   - Print each element: `arr[i]`
7. **For Insert Element at Position k**:
   - Check if array is empty or full (`n >= MAX_SIZE`)
   - Validate position: `1 <= position <= n+1`
   - Shift elements right starting from last element:
     * For `i = n` down to `i = position`, do `arr[i] = arr[i-1]`
   - Insert element: `arr[position-1] = element`
   - Increment size: `n++`
8. **For Delete Element by Value**:
   - Check if array is empty (`n == 0`)
   - Search element in array using loop:
     * For `i = 0` to `i = n-1`, check if `arr[i] == element`
   - If found at index `i`:
     * Shift all elements left: For `j = i` to `j = n-2`, do `arr[j] = arr[j+1]`
     * Decrement size: `n--`
   - If not found, display "Element not found"
9. **For Delete Element by Position**:
   - Check if array is empty
   - Validate position: `1 <= position <= n`
   - Store element to be deleted: `deletedElement = arr[position-1]`
   - Shift all elements left from position:
     * For `j = position-1` to `j = n-2`, do `arr[j] = arr[j+1]`
   - Decrement size: `n--`
   - Display deleted element
10. **For Linear Search**:
    - Check if array is empty
    - Initialize `comparisons = 0`
    - Traverse array: For `i = 0` to `i = n-1`:
      * Increment comparisons: `comparisons++`
      * If `arr[i] == element`:
        - Display position: `i+1`
        - Display number of comparisons
        - Return
    - If not found, display "Element not found" and comparisons
11. **For Sort Array (Bubble Sort)**:
    - Check if array is empty
    - For `i = 0` to `i = n-2`:
      * Set `swapped = 0`
      * For `j = 0` to `j = n-i-2`:
        - If `arr[j] > arr[j+1]`:
          * Swap: `temp = arr[j]`, `arr[j] = arr[j+1]`, `arr[j+1] = temp`
          * Set `swapped = 1`
      * If `swapped == 0`, break (array already sorted)
    - Display "Array sorted successfully"
12. **For Binary Search**:
    - Check if array is empty
    - First sort the array using bubble sort
    - Display sorted array
    - Initialize: `left = 0`, `right = n-1`, `comparisons = 0`
    - While `left <= right`:
      * Calculate middle: `mid = left + (right - left) / 2`
      * Increment comparisons: `comparisons++`
      * If `arr[mid] == element`:
        - Display position: `mid+1` (in sorted array)
        - Display number of comparisons
        - Return
      * Else if `arr[mid] < element`:
        - Search right half: `left = mid + 1`
      * Else:
        - Search left half: `right = mid - 1`
    - If not found, display "Element not found" and comparisons
13. Repeat until user chooses to quit
14. STOP

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
            case 9: {
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
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 1
Enter array length: 5
Enter array elements: 10 20 30 40 50
Array read successfully.

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 2
Current array: 10 20 30 40 50 

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 3
Enter element and position to insert: 25 3
Element 25 inserted at position 3 successfully.

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 2
Current array: 10 20 25 30 40 50 

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 6
Enter the element to search: 30
Element found at position: 4
Linear Search - Number of comparisons: 4

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 4
Enter element to remove: 25
Element 25 deleted successfully.

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 2
Current array: 10 20 30 40 50 

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 8
Enter the element to search: 40
Array sorted successfully
Array sorted for binary search: 10 20 30 40 50 
Element found at position: 4 (in sorted array)
Binary Search - Number of comparisons: 1

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 9
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

1. START
2. Declare dynamic array pointer: `int *arr = NULL`
3. Initialize `n = 0` (current size of array)
4. Display menu with options and accept user choice
5. **For Read Array**:
   - If `arr != NULL`, free existing memory
   - Accept size from user
   - Validate size: `size > 0`
   - Allocate memory: `arr = (int *) malloc(size * sizeof(int))`
   - Check if allocation successful
   - If successful:
     * Set `n = size`
     * Accept `n` elements and store using pointer: `*(arr + i)`
6. **For Display Array**:
   - Check if array is empty (`arr == NULL` OR `n == 0`)
   - If not empty, traverse from `i = 0` to `i = n-1`
   - Print each element using pointer arithmetic: `*(arr + i)`
7. **For Insert Element at Position k**:
   - Check if array is empty
   - Validate position: `1 <= position <= n+1`
   - Reallocate memory to increase size:
     * `temp = (int *) realloc(arr, (n + 1) * sizeof(int))`
     * Check if reallocation successful
     * If successful: `arr = temp`, `n = n + 1`
   - Shift elements right from last to position:
     * For `i = n-1` down to `i = position`, do `*(arr + i) = *(arr + i - 1)`
   - Insert element: `*(arr + position - 1) = element`
8. **For Delete Element by Value**:
   - Check if array is empty
   - Search element: For `i = 0` to `i = n-1`:
     * If `*(arr + i) == element`:
       - Shift all elements left: For `j = i` to `j = n-2`, do `*(arr + j) = *(arr + j + 1)`
       - Reallocate memory to decrease size:
         * If `n - 1 <= 0`: Free memory and set `arr = NULL`, `n = 0`
         * Else: `temp = (int *) realloc(arr, (n - 1) * sizeof(int))`
         * If successful: `arr = temp`, `n = n - 1`
       - Return
   - If not found, display "Element not found"
9. **For Delete Element by Position**:
   - Check if array is empty
   - Validate position: `1 <= position <= n`
   - Store element: `deletedElement = *(arr + position - 1)`
   - Shift elements left: For `j = position-1` to `j = n-2`, do `*(arr + j) = *(arr + j + 1)`
   - Reallocate memory to decrease size (same as delete by value)
   - Display deleted element
10. **For Linear Search**:
    - Check if array is empty
    - Initialize `comparisons = 0`
    - Traverse array: For `i = 0` to `i = n-1`:
      * Increment comparisons
      * If `*(arr + i) == element`:
        - Display position and comparisons
        - Return
    - If not found, display message and comparisons
11. **For Sort Array (Bubble Sort)**:
    - Check if array is empty
    - For `i = 0` to `i = n-2`:
      * Set `swapped = 0`
      * For `j = 0` to `j = n-i-2`:
        - If `*(arr + j) > *(arr + j + 1)`:
          * Swap using pointer arithmetic
          * Set `swapped = 1`
      * If `swapped == 0`, break
    - Display "Array sorted successfully"
12. **For Binary Search**:
    - Check if array is empty
    - Sort array first
    - Display sorted array
    - Initialize: `left = 0`, `right = n-1`, `comparisons = 0`
    - While `left <= right`:
      * Calculate: `mid = left + (right - left) / 2`
      * Increment comparisons
      * If `*(arr + mid) == element`:
        - Display position and comparisons
        - Return
      * Else if `*(arr + mid) < element`: `left = mid + 1`
      * Else: `right = mid - 1`
    - If not found, display message and comparisons
13. **For Exit**:
    - Free allocated memory: `free(arr)`
    - Set `arr = NULL`
14. Repeat until user chooses to quit
15. STOP

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
            case 9: {
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
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 1
Enter array length: 4
Enter array elements: 15 25 35 45
Array read successfully.

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 2
Current array: 15 25 35 45 

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 3
Enter element and position to insert: 30 3
Element 30 inserted at position 3 successfully.

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 2
Current array: 15 25 30 35 45 

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 6
Enter the element to search: 35
Element found at position: 4
Linear Search - Number of comparisons: 4

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 5
Enter the position of the element to delete: 3
Element 30 at position 3 deleted successfully.

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 2
Current array: 15 25 35 45 

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 8
Enter the element to search: 25
Array sorted successfully
Array sorted for binary search: 15 25 35 45 
Element found at position: 2 (in sorted array)
Binary Search - Number of comparisons: 2

Enter operation to perform-
1. Read Array
2. Display Array
3. Insert element
4. Delete element
5. Delete element from position
6. Search element (Linear Search)
7. Sort Array
8. Search element (Binary Search)
9. quit
Selection: 9
```

<div align="right"><a href="#index">return to index</a></div><hr>
