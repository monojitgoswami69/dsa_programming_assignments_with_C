<h1 align="center">ASSIGNMENT - 7: Linked List Variants</h1>

<div align="center" id="index">
  <h2>Table of Contents</h2>
</div>

<div align="center">

| **Implementation** |
|---|
| [**#1** Circular Linked List Operations](#implementation1) |
| [**#2** Doubly Linked List Operations](#implementation2) |

</div>

---

> ### **Note** 
> - All programs include problem statement, algorithm, source code, and sample outputs
> - **You can write any one of the following implementations** for your lab work
> - Both implementations provide complete menu-driven operations

<hr>

<a id="implementation1"></a>
## 1. Circular Linked List Implementation

### Problem Statement
Write a menu driven program in C to perform the following operations on circular linked list:
- (a) Insert a node at the kth position of the list
- (b) Delete the kth node from the list
- (c) Display the whole list
- (d) Search an element x in the list

### Algorithm

1. START
2. Define `struct Node` with:
   - `int data` (stores value)
   - `struct Node *next` (points to next node)
3. Initialize `head = NULL`
4. Display menu with operations:
   - Insert at position k
   - Delete from position k
   - Display list
   - Search element
   - Exit
5. For **insertAtK(head, value, k)**:
   - Create new node with `malloc()`
   - **Case 1: Empty List**
     - Set `newNode->next = newNode` (points to itself)
     - Set `head = newNode`
   - **Case 2: Insert at Beginning (k ≤ 1)**
     - Find last node (traverse until `last->next == head`)
     - Set `newNode->next = head`
     - Set `last->next = newNode`
     - Set `head = newNode`
   - **Case 3: Insert at Position k**
     - Traverse to (k-1)th position
     - Set `newNode->next = temp->next`
     - Set `temp->next = newNode`
6. For **deleteFromK(head, k)**:
   - **Case 1: Empty List** - Display error
   - **Case 2: Delete First Node (k ≤ 1)**
     - If only one node: Free it and set `head = NULL`
     - Otherwise: Find last node, update pointers, free first node
   - **Case 3: Delete from Position k**
     - Traverse to (k-1)th position
     - Update pointer to skip kth node
     - Free the deleted node
7. For **display(head)**:
   - Use do-while loop to traverse circular list
   - Print each node's data
   - Stop when back to head
8. For **search(head, value)**:
   - Traverse list using do-while loop
   - Check each node's data
   - Return position if found
9. STOP

**Key Circular List Concepts:**
- **Last Node → Head**: No NULL termination
- **Traversal Condition**: `while (temp != head)` instead of `while (temp != NULL)`
- **Finding Last Node**: Essential for beginning insertion/deletion
- **Do-While Loop**: Ensures at least one iteration for non-empty list

### Source Code

```c
/*
ASSIGNMENT 7:
Problem Statement: Write a menu driven program in C to perform the following operations on circular linked list.
(a) insert a node at the kth position of the list.
(b) delete the kth node at the end of the list.
(c) display the whole list.
(d) search an element x in the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtK(struct Node **head, int value, int k) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) { printf("Memory allocation failed!\n"); return; }
    newNode->data = value;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        printf("Inserted %d at position 1\n", value);
        return;
    }

    if (k <= 1) {
        struct Node *last = *head;
        while (last->next != *head)
            last = last->next;
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
        printf("Inserted %d at position 1\n", value);
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp->next != *head; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d\n", value, k);
}

void deleteFromK(struct Node **head, int k) {
    if (*head == NULL) { printf("List is empty!\n"); return; }

    struct Node *temp = *head;

    if (k <= 1) {
        if (temp->next == temp) {
            printf("Deleted %d\n", temp->data);
            free(temp);
            *head = NULL;
            return;
        }

        struct Node *last = *head;
        while (last->next != *head)
            last = last->next;

        last->next = temp->next;
        *head = temp->next;
        printf("Deleted %d from position 1\n", temp->data);
        free(temp);
        return;
    }

    for (int i = 1; i < k - 1 && temp->next != *head; i++)
        temp = temp->next;

    if (temp->next == *head) { printf("Position %d out of bounds\n", k); return; }

    struct Node *del = temp->next;
    temp->next = del->next;
    printf("Deleted %d from position %d\n", del->data, k);
    free(del);
}

void display(struct Node *head) {
    if (!head) { printf("List is empty\n"); return; }
    struct Node *temp = head;
    printf("List: ");
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != head) printf(" -> ");
    } while (temp != head);
    printf(" (circular)\n");
}

void search(struct Node *head, int value) {
    if (!head) { printf("List is empty\n"); return; }
    struct Node *temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Found %d at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("%d not found\n", value);
}

void displayMenu() {
    printf("\n===== CIRCULAR LINKED LIST MENU =====\n");
    printf("1. Insert at position k\n");
    printf("2. Delete from position k\n");
    printf("3. Display list\n");
    printf("4. Search value\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node *head = NULL;
    int ch, val, k;
    while (1) {
        displayMenu();
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value and position: "); scanf("%d%d", &val, &k); insertAtK(&head, val, k); break;
            case 2: printf("Enter position to delete: "); scanf("%d", &k); deleteFromK(&head, k); break;
            case 3: display(head); break;
            case 4: printf("Enter value to search: "); scanf("%d", &val); search(head, val); break;
            case 0: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
```

### Sample Output

```
===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 10 1
Inserted 10 at position 1

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 20 2
Inserted 20 at position 2

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 30 3
Inserted 30 at position 3

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 5 1
Inserted 5 at position 1

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 3
List: 5 -> 10 -> 20 -> 30 (circular)

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 15 3
Inserted 15 at position 3

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 3
List: 5 -> 10 -> 15 -> 20 -> 30 (circular)

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 4
Enter value to search: 15
Found 15 at position 3

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 4
Enter value to search: 100
100 not found

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 2
Enter position to delete: 1
Deleted 5 from position 1

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 3
List: 10 -> 15 -> 20 -> 30 (circular)

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 2
Enter position to delete: 3
Deleted 20 from position 3

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 3
List: 10 -> 15 -> 30 (circular)

===== CIRCULAR LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 0
```

**Visual Representation of Operations:**

```
Initial State:
head = NULL

After inserting 10 at position 1:
   ┌─────┐
   ↓     ↑
[10|•]──┘
head

After inserting 20 at position 2:
   ┌──────────┐
   ↓          ↑
[10|•]──>[20|•]
head

After inserting 30 at position 3:
   ┌───────────────┐
   ↓               ↑
[10|•]─>[20|•]─>[30|•]
head

After inserting 5 at position 1:
   ┌────────────────────┐
   ↓                    ↑
[5|•]─>[10|•]─>[20|•]─>[30|•]
head

Final circular structure:
       head
        ↓
    [5 | •]────────────┐
        ↑              ↓
   [30 | •]      [10 | •]
        ↑              ↓
        └────[20 | •]──┘
```

<div align="right"><a href="#index">return to index</a></div><hr>

<a id="implementation2"></a>
## 2. Doubly Linked List Implementation

### Problem Statement
Write a menu driven program in C to perform the following operations on doubly linked list:
- (a) Insert a node at the kth position of the list
- (b) Delete the kth node from the list
- (c) Display the whole list
- (d) Search an element x in the list

### Algorithm

1. START
2. Define `struct Node` with:
   - `int data` (stores value)
   - `struct Node *prev` (points to previous node)
   - `struct Node *next` (points to next node)
3. Initialize `head = NULL`
4. Display menu with operations (same as circular list)
5. For **insertAtK(head, value, k)**:
   - Create new node with `malloc()`
   - Initialize `newNode->prev = newNode->next = NULL`
   - **Case 1: Insert at Beginning or Empty List (k ≤ 1)**
     - Set `newNode->next = head`
     - If `head` exists, set `head->prev = newNode`
     - Set `head = newNode`
   - **Case 2: Insert at Position k**
     - Traverse to (k-1)th position
     - Set `newNode->next = temp->next`
     - Set `newNode->prev = temp`
     - If `temp->next` exists, set `temp->next->prev = newNode`
     - Set `temp->next = newNode`
6. For **deleteFromK(head, k)**:
   - **Case 1: Empty List** - Display error
   - **Case 2: Delete First Node (k ≤ 1)**
     - Set `head = head->next`
     - If new head exists, set `head->prev = NULL`
     - Free old head
   - **Case 3: Delete from Position k**
     - Traverse to kth position
     - If `temp->prev` exists, set `temp->prev->next = temp->next`
     - If `temp->next` exists, set `temp->next->prev = temp->prev`
     - Free temp
7. For **display(head)**:
   - Traverse forward using `temp = temp->next`
   - Print data with bidirectional arrows (⇄)
   - Stop at NULL
8. For **search(head, value)**:
   - Traverse list checking each node's data
   - Return position if found
9. STOP

**Key Doubly List Concepts:**
- **Bidirectional Links**: Each node has both prev and next pointers
- **Easy Deletion**: No need to track previous node (already have it)
- **Forward/Backward Traversal**: Can move in both directions
- **Extra Memory**: Requires additional pointer per node
- **Pointer Maintenance**: Must update both prev and next for operations

### Source Code

```c
/*
ASSIGNMENT 7:
Problem Statement: Write a menu driven program in C to perform the following operations on double linked list.
(a) insert a node at the kth position of the list.
(b) delete the kth node at the end of the list.
(c) display the whole list.
(d) search an element x in the list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAtK(struct Node **head, int value, int k) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) { printf("Memory allocation failed!\n"); return; }
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (k <= 1 || *head == NULL) {
        newNode->next = *head;
        if (*head) (*head)->prev = newNode;
        *head = newNode;
        printf("Inserted %d at position 1\n", value);
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < k - 1 && temp->next; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;

    printf("Inserted %d at position %d\n", value, k);
}

void deleteFromK(struct Node **head, int k) {
    if (*head == NULL) { printf("List is empty!\n"); return; }

    struct Node *temp = *head;
    if (k <= 1) {
        *head = temp->next;
        if (*head) (*head)->prev = NULL;
        printf("Deleted %d from position 1\n", temp->data);
        free(temp);
        return;
    }

    for (int i = 1; i < k && temp; i++)
        temp = temp->next;

    if (!temp) { printf("Position %d out of bounds\n", k); return; }

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    printf("Deleted %d from position %d\n", temp->data, k);
    free(temp);
}

void display(struct Node *head) {
    if (!head) { printf("List is empty\n"); return; }
    printf("List: ");
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" <-> ");
        head = head->next;
    }
    printf("\n");
}

void search(struct Node *head, int value) {
    int pos = 1;
    while (head) {
        if (head->data == value) {
            printf("Found %d at position %d\n", value, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("%d not found\n", value);
}

void displayMenu() {
    printf("\n===== DOUBLY LINKED LIST MENU =====\n");
    printf("1. Insert at position k\n");
    printf("2. Delete from position k\n");
    printf("3. Display list\n");
    printf("4. Search value\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node *head = NULL;
    int ch, val, k;
    while (1) {
        displayMenu();
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value and position: "); scanf("%d%d", &val, &k); insertAtK(&head, val, k); break;
            case 2: printf("Enter position to delete: "); scanf("%d", &k); deleteFromK(&head, k); break;
            case 3: display(head); break;
            case 4: printf("Enter value to search: "); scanf("%d", &val); search(head, val); break;
            case 0: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
```

### Sample Output

```
===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 50 1
Inserted 50 at position 1

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 60 2
Inserted 60 at position 2

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 70 3
Inserted 70 at position 3

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 3
List: 50 <-> 60 <-> 70

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 40 1
Inserted 40 at position 1

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 1
Enter value and position: 55 3
Inserted 55 at position 3

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 3
List: 40 <-> 50 <-> 55 <-> 60 <-> 70

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 4
Enter value to search: 55
Found 55 at position 3

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 4
Enter value to search: 80
80 not found

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 2
Enter position to delete: 1
Deleted 40 from position 1

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 3
List: 50 <-> 55 <-> 60 <-> 70

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 2
Enter position to delete: 3
Deleted 60 from position 3

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 3
List: 50 <-> 55 <-> 70

===== DOUBLY LINKED LIST MENU =====
1. Insert at position k
2. Delete from position k
3. Display list
4. Search value
0. Exit
Enter your choice: 0
```

**Visual Representation of Operations:**

```
Initial State:
head = NULL

After inserting 50:
NULL ← [prev|50|next] → NULL
       ↑
      head

After inserting 60 at position 2:
NULL ← [prev|50|next] ⇄ [prev|60|next] → NULL
       ↑
      head

After inserting 70 at position 3:
NULL ← [prev|50|next] ⇄ [prev|60|next] ⇄ [prev|70|next] → NULL
       ↑
      head

After inserting 40 at position 1:
NULL ← [prev|40|next] ⇄ [prev|50|next] ⇄ [prev|60|next] ⇄ [prev|70|next] → NULL
       ↑
      head

After inserting 55 at position 3:
NULL ← [40] ⇄ [50] ⇄ [55] ⇄ [60] ⇄ [70] → NULL
       ↑
      head

After deleting position 1:
NULL ← [50] ⇄ [55] ⇄ [60] ⇄ [70] → NULL
       ↑
      head

Final structure after deleting position 3:
NULL ← [50] ⇄ [55] ⇄ [70] → NULL
       ↑
      head

Each node maintains bidirectional links:
[50] has: prev=NULL, next→[55]
[55] has: prev←[50], next→[70]
[70] has: prev←[55], next=NULL
```

**Comparison: Circular vs Doubly Linked List**

| Feature | Circular | Doubly |
|---------|----------|--------|
| **Pointers/Node** | 1 (next) | 2 (prev, next) |
| **Memory** | Less | More |
| **Traversal** | Forward (circular) | Both directions |
| **End Detection** | `temp == head` | `temp == NULL` |
| **Backward Movement** | Must go around | Direct via prev |
| **Deletion** | Need to find previous | Have prev pointer |
| **Use Case** | Round-robin | Navigation |

<div align="right"><a href="#index">return to index</a></div><hr>
