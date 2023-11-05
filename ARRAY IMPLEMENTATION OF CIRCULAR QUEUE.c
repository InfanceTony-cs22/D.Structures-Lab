#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Check if the queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Enqueue (add) an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = value;
}

// Dequeue (remove) an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1);
    }
    int value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return value;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeued: %d\n", dequeue());

    enqueue(40);
    enqueue(50);

    while (!isEmpty()) {
        printf("Dequeued: %d\n", dequeue());
    }

    return 0;
}
