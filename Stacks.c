#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int data;
    struct Stack* next;
};

struct Stack* createStack() {
    return NULL;
}

void push(struct Stack** top, int data) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Stack** top) {
    if(*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    int data = (*top)->data;
    struct Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

int main() {
    struct Stack* top = createStack();
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);

    while(top != NULL) {
        printf("%d ", pop(&top));
    }
    return 0;
}
