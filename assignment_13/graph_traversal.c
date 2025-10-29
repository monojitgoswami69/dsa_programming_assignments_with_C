/*
ASSIGNMENT 13:
Problem statement: Write a c program to perform the following operations
(a) Read the adjacency matrix from a file.
(b) DFS function to traverse the graph.
(c) BFS function to traverse the graph.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct Queue{
    int items[MAX];
    int front, rear;
};

struct Stack{
    int items[MAX];
    int top;
};

void initQueue(struct Queue* q){
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct Queue* q){
    return q->front == -1;
}

void enqueue(struct Queue* q, int val){
    if (q->rear == MAX - 1){
        printf("Queue full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = val;
}

int dequeue(struct Queue* q){
    if (isQueueEmpty(q)){
        printf("Queue empty\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) q->front = q->rear = -1;
    return item;
}

void initStack(struct Stack* s){
    s->top = -1;
}

int isStackEmpty(struct Stack* s){
    return s->top == -1;
}

void push(struct Stack* s, int val){
    if (s->top == MAX - 1){
        printf("Stack full\n");
        return;
    }
    s->top++;
    s->items[s->top] = val;
}

int pop(struct Stack* s){
    if (isStackEmpty(s)){
        printf("Stack empty\n");
        return -1;
    }
    int item = s->items[s->top];
    s->top--;
    return item;
}

void DFS_Recursive(int graph[][MAX], int n, int v, int visited[]){
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++){
        if (graph[v][i] == 1 && !visited[i]){
            DFS_Recursive(graph, n, i, visited);
        }
    }
}

void DFS_Iterative(int graph[][MAX], int n, int start){
    int visited[MAX] = {0};
    struct Stack s;
    initStack(&s);
    push(&s, start);
    
    printf("DFS (Iterative): ");
    while (!isStackEmpty(&s)){
        int v = pop(&s);
        if (!visited[v]){
            printf("%d ", v);
            visited[v] = 1;
        }
        for (int i = n - 1; i >= 0; i--){
            if (graph[v][i] == 1 && !visited[i]){
                push(&s, i);
            }
        }
    }
    printf("\n");
}

void BFS(int graph[][MAX], int n, int start){
    int visited[MAX] = {0};
    struct Queue q;
    initQueue(&q);
    
    visited[start] = 1;
    enqueue(&q, start);
    
    printf("BFS: ");
    while (!isQueueEmpty(&q)){
        int v = dequeue(&q);
        printf("%d ", v);
        for (int i = 0; i < n; i++){
            if (graph[v][i] == 1 && !visited[i]){
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int readFromFile(int graph[][MAX], const char* file){
    FILE* f = fopen(file, "r");
    if (f == NULL){
        printf("Error opening file '%s'\n", file);
        return -1;
    }
    
    int n;
    fscanf(f, "%d", &n);
    printf("Reading %dx%d matrix from file\n", n, n);
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            fscanf(f, "%d", &graph[i][j]);
        }
    }
    
    fclose(f);
    return n;
}

int inputGraph(int graph[][MAX]){
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    return n;
}

void display(int graph[][MAX], int n){
    printf("\nAdjacency Matrix:\n   ");
    for (int i = 0; i < n; i++) printf("%2d ", i);
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%2d: ", i);
        for (int j = 0; j < n; j++){
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }
}

void createSample(){
    FILE* f = fopen("graph.txt", "w");
    if (f == NULL){
        printf("Error creating file\n");
        return;
    }
    fprintf(f, "6\n");
    fprintf(f, "0 1 1 0 0 0\n");
    fprintf(f, "1 0 0 1 1 0\n");
    fprintf(f, "1 0 0 0 1 0\n");
    fprintf(f, "0 1 0 0 0 1\n");
    fprintf(f, "0 1 1 0 0 1\n");
    fprintf(f, "0 0 0 1 1 0\n");
    fclose(f);
    printf("Sample file 'graph.txt' created\n");
}

int main(){
    int graph[MAX][MAX];
    int n = 0;
    int choice, start;
    int visited[MAX];
    
    while (1){
        printf("\n1. Create sample file\n2. Read from file\n3. Input matrix\n4. Display\n5. DFS (Recursive)\n6. DFS (Iterative)\n7. BFS\n8. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                createSample();
                break;
            case 2:{
                char file[100];
                printf("Enter filename: ");
                scanf("%s", file);
                n = readFromFile(graph, file);
                if (n > 0) printf("Graph loaded (%d vertices)\n", n);
                break;
            }
            case 3:
                n = inputGraph(graph);
                printf("Graph input (%d vertices)\n", n);
                break;
            case 4:
                if (n > 0) display(graph, n);
                else printf("Load graph first\n");
                break;
            case 5:
                if (n > 0){
                    printf("Enter start vertex (0-%d): ", n - 1);
                    scanf("%d", &start);
                    if (start >= 0 && start < n){
                        for (int i = 0; i < n; i++) visited[i] = 0;
                        printf("DFS (Recursive): ");
                        DFS_Recursive(graph, n, start, visited);
                        printf("\n");
                    } else printf("Invalid vertex\n");
                } else printf("Load graph first\n");
                break;
            case 6:
                if (n > 0){
                    printf("Enter start vertex (0-%d): ", n - 1);
                    scanf("%d", &start);
                    if (start >= 0 && start < n) DFS_Iterative(graph, n, start);
                    else printf("Invalid vertex\n");
                } else printf("Load graph first\n");
                break;
            case 7:
                if (n > 0){
                    printf("Enter start vertex (0-%d): ", n - 1);
                    scanf("%d", &start);
                    if (start >= 0 && start < n) BFS(graph, n, start);
                    else printf("Invalid vertex\n");
                } else printf("Load graph first\n");
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
