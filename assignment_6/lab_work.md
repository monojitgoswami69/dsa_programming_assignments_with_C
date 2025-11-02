<h1 align="center">ASSIGNMENT - 6: Singly Linked List Operations</h1>

### Problem Statement
Write a menu driven program in C to perform the following operations on single linked list.
- (a) insert a node at the beginning of the list.
- (b) insert a node at the end of the list.
- (c) insert a node at kth position of the list
- (d) delete a node from the beginning of the list.
- (e) delete a node at the end of the list.
- (f) display the whole list.
- (g) search an element x in the list.
- (h) reverse the list.

### Algorithm


1. START
2. Define structure `Node` with members: `int data`, `struct Node *next`
3. Initialize head pointer: `struct Node *head = NULL`
4. Display menu with operations and accept user choice
5. **For insert at beginning:**
    - Create new node, set data, point next to head, update head
6. **For insert at end:**
    - Create new node, set data, set next to NULL
    - If list empty, set head to new node
    - Else, traverse to last node and link new node
7. **For insert at kth position:**
    - Validate position
    - If position 1, insert at beginning
    - Else, traverse to (k-1)th node, insert new node
8. **For delete from beginning:**
    - If list empty, display message
    - Else, update head to next node, free old head
9. **For delete from end:**
    - If list empty, display message
    - If only one node, free head, set head to NULL
    - Else, traverse to second last node, free last node, set next to NULL
10. **For delete from kth position:**
     - Validate position
     - If position 1, delete from beginning
     - Else, traverse to (k-1)th node, unlink and free kth node
11. **For display:**
     - Traverse from head, print each node's data
12. **For search:**
     - Traverse from head, compare data with target, display position if found
13. **For reverse:**
     - Use three pointers: prev, current, next
     - Traverse list, reverse links, update head
14. Repeat menu until user chooses to quit
15. Free all nodes before exit
16. STOP

### Source Code

```c
/*
ASSIGNMENT 6:
Problem Statement: Write a menu driven program in C to perform the following operations on single linked list.
(a) insert a node at the beginning of the list.
(b) insert a node at the end of the list.
(c) insert a node at kth position of the list
(d) delete a node from the beginning of the list.
(e) delete a node at the end of the list.
(f) display the whole list.
(g) search an element x in the list.
(h) reverse the list.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int value){
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at beginning\n", value);
}

void insertAtEnd(struct Node **head, int value){
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL){
        *head = newNode;
    } 
    else{
        struct Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at end\n", value);
}

void insertAtK(struct Node **head, int value, int k){
    if (k <= 0) {
        printf("Invalid position! Position should be >= 1\n");
        return;
    }

    if (k == 1) {
        insertAtBeginning(head, value);
        return;
    }
    
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    
    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position %d is out of bounds\n", k);
        free(newNode);
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", value, k);
}

void deleteFromBeginning(struct Node **head){
    if (*head == NULL) {
        printf("List is empty! Nothing to delete\n");
        return;
    }
    
    struct Node *temp = *head;
    *head = (*head)->next;
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

void deleteFromEnd(struct Node **head){
    if (*head == NULL) {
        printf("List is empty! Nothing to delete\n");
        return;
    }
    
    if ((*head)->next == NULL) {
        printf("Deleted %d from end\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    
    struct Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    printf("Deleted %d from end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteFromK(struct Node **head, int k){
    if (*head == NULL) {
        printf("List is empty! Nothing to delete\n");
        return;
    }
    
    if (k <= 0) {
        printf("Invalid position! Position should be >= 1\n");
        return;
    }
    
    if (k == 1) {
        deleteFromBeginning(head);
        return;
    }
    
    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is out of bounds\n", k);
        return;
    }
    
    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted %d from position %d\n", nodeToDelete->data, k);
    free(nodeToDelete);
}

void display(struct Node *head){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("List: ");
    while(head != NULL){
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

void search(struct Node *head, int value){
    int position = 1;
    while (head != NULL) {
        if (head->data == value) {
            printf("Value %d found at position %d\n", value, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Value %d not found in the list\n", value);
}

void reverse(struct Node **head){
    if (*head == NULL) {
        printf("List is empty! Nothing to reverse\n");
        return;
    }
    
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    *head = prev;
    printf("List reversed successfully\n");
}

void displayMenu(){
    printf("\n===== LINKED LIST MENU =====\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position k\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Delete from position k\n");
    printf("7. Display list\n");
    printf("8. Search for value\n");
    printf("9. Reverse list\n");
    printf("0. Quit\n");
    printf("============================\n");
    printf("Enter your choice: ");
}

int main(){
    struct Node *head = NULL;
    int choice, value, position;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
                
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
                
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (1-indexed): ");
                scanf("%d", &position);
                insertAtK(&head, value, position);
                break;
                
            case 4:
                deleteFromBeginning(&head);
                break;
                
            case 5:
                deleteFromEnd(&head);
                break;
                
            case 6:
                printf("Enter position to delete (1-indexed): ");
                scanf("%d", &position);
                deleteFromK(&head, position);
                break;
                
            case 7:
                display(head);
                break;
                
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;
                
            case 9:
                reverse(&head);
                break;
                
            case 0:               
                while (head != NULL) {
                    struct Node *temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 0-9\n");
                break;
        }
    }
    
    return 0;
}
```

### Sample Output

```
===== LINKED LIST MENU =====
1. Insert at beginning
2. Insert at end
3. Insert at position k
4. Delete from beginning
5. Delete from end
6. Delete from position k
7. Display list
8. Search for value
9. Reverse list
0. Quit
============================
Enter your choice: 2
Enter value to insert at end: 10
Inserted 10 at end

Enter your choice: 2
Enter value to insert at end: 20
Inserted 20 at end

Enter your choice: 2
Enter value to insert at end: 30
Inserted 30 at end

Enter your choice: 7
List: 10 -> 20 -> 30

Enter your choice: 1
Enter value to insert at beginning: 5
Inserted 5 at beginning

Enter your choice: 7
List: 5 -> 10 -> 20 -> 30

Enter your choice: 3
Enter value to insert: 15
Enter position (1-indexed): 3
Inserted 15 at position 3

Enter your choice: 7
List: 5 -> 10 -> 15 -> 20 -> 30

Enter your choice: 8
Enter value to search: 20
Value 20 found at position 4

Enter your choice: 4
Deleted 5 from beginning

Enter your choice: 7
List: 10 -> 15 -> 20 -> 30

Enter your choice: 5
Deleted 30 from end

Enter your choice: 7
List: 10 -> 15 -> 20

Enter your choice: 9
List reversed successfully

Enter your choice: 7
List: 20 -> 15 -> 10

Enter your choice: 6
Enter position to delete (1-indexed): 2
Deleted 15 from position 2

Enter your choice: 7
List: 20 -> 10

Enter your choice: 0
```
