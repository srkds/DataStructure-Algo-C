/*
    STACK IMPLEMENTATION
    isEmpty()
    push()
    pop()
    peep()
*/

#include<stdio.h>
#include<stdlib.h>
#define p(msg,var) printf(msg,var)
#define TRUE 1
#define FALSE 0

struct node{
    int data;
    struct node *prev;
};

int isEmpty(struct node *top){
    if(top == NULL){
        return TRUE;
    } else {
        return FALSE;
    }
}

struct node* push(struct node *top, int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    if(top == NULL){
        top = newNode;
        return top;
    }
    newNode->prev = top;
    top = newNode;
    return top;
}

int pop(struct node **top){
    if(isEmpty(*top)){
        printf("\nSTACK UNDERFLOW!");
        return -1;
    } 
    int value;
    struct node *ptr = *top;
    value = ptr->data;
    *top = ptr->prev;
    free(ptr);
    ptr = NULL;
    return value;
}

int peep(struct node *top){
    if(isEmpty(top)){
        printf("\nSTACK IS EMPTY!");
        return -1;
    }
    return top->data;
}

int main(){
    struct node *top = NULL;
    int val;
    
    val = peep(top);
    p("\nAfter peep %d",val);

    top = push(top,25);
    val = peep(top);
    p("\nAfter push top val: %d",val);

    top = push(top,65);
    top = push(top,75);
    top = push(top,85);

    val = pop(&top);
    p("\nPOP %d",val);
    val = pop(&top);
    p("\nPOP %d",val);
    val = pop(&top);
    p("\nPOP %d",val);
    val = pop(&top);
    p("\nPOP %d",val);
    val = pop(&top);
    p("\nPOP %d",val);
    
    return 0;
}