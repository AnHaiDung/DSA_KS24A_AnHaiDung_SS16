#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
}Queue;

void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}

void enQueue(Queue *queue, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("khong the cap phat bo nho\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int front(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return -1;
    }
    return queue->front->data;
}

int main(void) {
    Queue queue;
    initQueue(&queue);
    int n;
    int value;
    printf("nhap n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu %d:",i);
        scanf("%d", &value);
        enQueue(&queue, value);
    }
    int result = front(&queue);
    if (result == -1) {
        printf("hang doi rongg\n");
    }else {
        printf("%d\n", result);
    }
    return 0;
}