#include <stdio.h>
#include <stdlib.h>

struct NodeStruct {
    int data;
    struct NodeStruct *next;
};

struct QueueStruct {
    struct NodeStruct *front;
    struct NodeStruct *rear;
    int size;
};

typedef struct NodeStruct Node;
typedef struct QueueStruct Queue;

Queue queue;

int isEmpty() {
    return queue.front == NULL;
}

void enqueue(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed - cannot enqueue %d\n", data);
        return;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    if (isEmpty()) {
        queue.front = newNode;
        queue.rear = newNode;
    } else {
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
    
    Node *temp = queue.front;
    printf("Dequeued: %d\n", temp->data);
    
    queue.front = queue.front->next;
    
    if (queue.front == NULL) {
        queue.rear = NULL;
    }
    
    free(temp);
    queue.size--;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue contents: Front -> ");
    Node *current = queue.front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("<- Rear\n");
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty - cannot peek\n");
        return;
    }
    printf("Front: %d\n", queue.front->data);
    printf("Rear: %d\n", queue.rear->data);
}

void freeQueue() {
    while (!isEmpty()) {
        Node *temp = queue.front;
        queue.front = queue.front->next;
        free(temp);
    }
    queue.rear = NULL;
    queue.size = 0;
}

int main() {
    int choice, data;
    
    queue.front = NULL;
    queue.rear = NULL;
    queue.size = 0;
    
    printf("Linear Queue with Linked List created successfully!\n");
    
    while (1) {
        printf("\n=== Queue Operations ===\n");
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
