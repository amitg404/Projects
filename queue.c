#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data;
    struct Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

void enqueue(int data) {
    struct Queue* newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = front->data;
    struct Queue* temp = front;
    if(front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    free(temp);
    return data;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);

    while(front != NULL) {
        printf("%d ", dequeue());
    }
    return 0;
}
