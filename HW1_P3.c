#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Queue {
    int element[105];
    int front;
    int rear;
};

void initializeQueue(struct Queue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

void enqueue(struct Queue* queue, int newElement) {
    queue->element[queue->rear] = newElement;
    queue->rear++;
}

int dequeue(struct Queue* queue) {
    queue->front++;
    return queue->element[queue->front - 1];
}

bool isEmpty(struct Queue* queue) {
    return queue->front == queue->rear;
}

int main() {
    int m;
    scanf("%d", &m);
    int A[105][105];
    int visited[105];
    int inQueue[105];
    int output[105];
    int idx = 0;

    for (int i = 1; i <= m; i++) {
        visited[i] = 0;
        inQueue[i] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    struct Queue explore;
    initializeQueue(&explore);

    enqueue(&explore, 1);
    inQueue[1] = 1;

    while (!isEmpty(&explore)) {
        int cur = dequeue(&explore);

        visited[cur] = 1;
        output[idx++] = cur;

        for (int j = 1; j <= m; j++) {
            if (A[cur][j] == 1 && visited[j] == 0 && inQueue[j] == 0) {
                enqueue(&explore, j);
                inQueue[j] = 1;
            }
        }
    }

    for (int i = 0; i < idx; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}
