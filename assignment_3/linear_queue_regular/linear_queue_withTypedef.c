#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

int isEmpty(Queue *q) {
    return q->size == 0;
}

int isFull(Queue *q) {
    return q->size == q->capacity;
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow - cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = -1;
    }
    q->rear++;
    q->data[q->rear] = data;
    q->size++;
    printf("Enqueued: %d\n", data);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow - cannot dequeue\n");
        return;
    }
    printf("Dequeued: %d\n", q->data[q->front]);
    q->front++;
    q->size--;
    
    if (q->size == 0) {
        q->front = -1;
        q->rear = -1;
    }
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: Front -> ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("<- Rear\n");
}

void peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty - cannot peek\n");
        return;
    }
    printf("Front: %d\n", q->data[q->front]);
    printf("Rear: %d\n", q->data[q->rear]);
}

int main() {
    int capacity, choice, data;
    
    printf("Enter queue capacity: ");
    scanf("%d", &capacity);
    
    if (capacity <= 0) {
        printf("Invalid queue capacity\n");
        return 1;
    }
    
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation failed for queue structure\n");
        return 1;
    }
    
    queue->data = (int*)malloc(capacity * sizeof(int));
    if (queue->data == NULL) {
        printf("Memory allocation failed for queue data\n");
        free(queue);
        return 1;
    }
    
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
        
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
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                peek(queue);
                break;
            case 5:
                free(queue->data);
                free(queue);
                return 0;
        }
    }
    return 0;
}
