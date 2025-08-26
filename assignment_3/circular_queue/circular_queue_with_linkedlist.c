#include <stdio.h>
#include <stdlib.h>

struct NodeStruct {
    int data;
    struct NodeStruct *next;
};

struct QueueStruct {
    struct NodeStruct *rear;
    int size;
    int capacity;
};

typedef struct NodeStruct Node;
typedef struct QueueStruct Queue;

Queue queue;

int isEmpty() {
    return queue.rear == NULL;
}

int isFull() {
    return queue.size == queue.capacity;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow - cannot enqueue %d\n", data);
        return;
    }
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed - cannot enqueue %d\n", data);
        return;
    }
    
    newNode->data = data;
    
    if (isEmpty()) {
        newNode->next = newNode;
        queue.rear = newNode;
    } else {
        newNode->next = queue.rear->next;
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
    
    queue.size++;
    printf("Enqueued: %d\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow - cannot dequeue\n");
        return;
    }
    
    Node *front = queue.rear->next;
    printf("Dequeued: %d\n", front->data);
    
    if (queue.size == 1) {
        free(front);
        queue.rear = NULL;
    } else {
        queue.rear->next = front->next;
        free(front);
    }
    
    queue.size--;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue contents: Front -> ");
    Node *current = queue.rear->next;
    
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue.rear->next);
    
    printf("<- Rear\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty - cannot peek\n");
        return;
    }
    printf("Front: %d\n", queue.rear->next->data);
    printf("Rear: %d\n", queue.rear->data);
}

void freeQueue() {
    if (isEmpty()) return;
    
    Node *current = queue.rear->next;
    Node *temp;
    
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != queue.rear->next);
    
    queue.rear = NULL;
    queue.size = 0;
}

int main() {
    int capacity, choice, data;
    
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);
    
    if (capacity <= 0) {
        printf("Invalid queue capacity\n");
        return 1;
    }
    
    queue.rear = NULL;
    queue.size = 0;
    queue.capacity = capacity;
    
    printf("Circular Queue with Linked List (capacity %d) created successfully!\n", capacity);
    
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
        
        while (choice < 1 || choice > 5) {
            printf("Invalid selection\n");
            printf("Selection: ");
            scanf("%d", &choice);
        }
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                freeQueue();
                printf("Queue freed successfully!\n");
                return 0;
        }
    }
    
    return 0;
}
