/*
ASSIGNMENT 3:
Problem Statement: Write a menu driven program in C to implement a Circular Queue using array and perform the following operations.
(a) isFull() function to check whether the Circular Queue is full or not.
(b) isEmpty() function to check whether the Circular Queue is empty or not.
(c) insert(item) function to insert an element item in the Circular Queue.
(d) delete() function to read and remove an element from the Circular Queue.
(e) display() function to display the entire Circular Queue.
*/

#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int size = 0;

int isEmpty() {
    return front == -1;
}

int isFull() {
    if (isEmpty()) return 0;
    return (rear + 1) % size == front % size;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow - cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = -1;
    }
    rear++;
    queue[rear % size] = data;
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow - cannot dequeue\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front % size]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: Front -> ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i % size]);
    }
    printf("<- Rear\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty - cannot peek\n");
        return;
    }
    printf("Front: %d\n", queue[front % size]);
    printf("Rear: %d\n", queue[rear % size]);
}

int main() {
    int choice, data;
    printf("Enter queue size (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid queue size. Must be between 1 and %d.\n", MAX_SIZE);
        return 1;
    }
    while (1) {
        printf("\n=== Circular Queue Operations ===\n");
        printf("1. Enqueue(Insert)\n");
        printf("2. Dequeue(Remove)\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Selection: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: return 0;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
}
