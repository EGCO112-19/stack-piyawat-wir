
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value);
char pop(StackPtr s);
void pop_all(StackPtr s);


void push(StackPtr s, char value) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if (new_node) { //memory available
        new_node->data = value;
        new_node->nextPtr = s->top;
        s->top = new_node;
        s->size++;
    }
}
char pop(StackPtr s) {
    Node *top = s->top;
    char value = 0;
    if (s->top != NULL) { //Stack not empty
        value = top->data;
        s->top = top->nextPtr;
        free(top);
        s->size--;
    }
    return value;
}
void pop_all(StackPtr s) {
    while (s->size > 0)
        printf("popping %c\n", pop(s));
}

#endif
