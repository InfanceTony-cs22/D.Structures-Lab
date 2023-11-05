#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1; // Initialize front
int rear = -1;  // Initialize rear

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
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = value;
}

// Dequeue (remove) an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1); // Exit the program on error
    }
    int value = queue[front];
    if (front == rear) {
        // If there's only one element in the queue, reset front and rear
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

    while (!isEmpty()) {
        printf("Dequeued: %d\n", dequeue());
    }

    return 0;
}
