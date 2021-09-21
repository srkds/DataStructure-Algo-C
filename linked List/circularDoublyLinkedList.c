#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void printNodes(struct node *tail, char msg[]){
    printf("\n%s",msg);
    if(tail == NULL){
        printf("\nLIST IS EMPTY!");
        return;
    }
    struct node *ptr = tail->next;
    printf("\n");
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != tail->next); // again reach to 1st node
}

struct node* addInEmpty(struct node *tail, int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    tail = newNode;
    tail->next = tail;
    tail->prev = tail;

    return tail;
}

struct node* addAtBeginning(struct node *tail, int data){
    if(tail == NULL){
        return addInEmpty(tail,data);
    }

    struct node *ptr = tail->next;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->next = ptr;
    newNode->prev = ptr->prev;

    tail->next = newNode;
    ptr->prev = newNode;

    return tail;

}

struct node* addAtEnd(struct node *tail, int data){
    if(tail == NULL){
        return addInEmpty(tail,data);
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    newNode->next = tail->next;
    newNode->prev = tail;
    tail->next = newNode;

    tail = newNode;
    return tail;
}

struct node* addAtPosition(struct node *tail, int data, int pos){
   if(pos < 1){
       printf("\nPLEASE ENTER VALID POSITION");
       return tail;
   }
   if(pos == 1){
       return addAtBeginning(tail,data);
   }

    struct node *ptr = tail->next;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    while(pos > 1){
        ptr = ptr->next;
        pos--;
    }
    
    newNode->next = ptr;
    newNode->prev = ptr->prev;

    ptr->prev->next = newNode;
    ptr->prev = newNode;

   return tail;
}

/* Creates a list of given size */
struct node* createList(struct node *tail, int size){
    if(size == 0){
        return tail;
    }

    int data,i;

    printf("\nEnter value for node 1: ");
    scanf("%d",&data);
    tail = addInEmpty(tail,data);

    for(i = 2; i <= size;i++){
        printf("\nEnter value for node %d: ", i);
        scanf("%d",&data);
        tail = addAtEnd(tail,data);
    }
    return tail;
}

struct node* delAtBeginning(struct node *tail){
    struct node *delThis = tail->next;

    tail->next = delThis->next;
    delThis->next->prev = tail;

    free(delThis);
    delThis = NULL;
    return tail;
}

struct node* delAtEnd(struct node *tail){
    struct node *ptr = tail->prev; // previous node of tail
    ptr->next = tail->next;
    tail->next->prev = ptr;

    free(tail);

    tail = ptr;
    return tail;
}

struct node* delAtPosition(struct node *tail, int pos){
    if(pos == 0){
        printf("Enter A valid position!");
        return tail;
    }
    if(tail == NULL){
        return tail;
    }
    struct node *ptr = tail->next;
    while(pos > 1){
        ptr = ptr->next;
        pos--;
    }

    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;

    free(ptr);
    ptr = NULL;
    return tail;
}

struct node* delEntireList(struct node *tail){
    if(tail == NULL){
        return tail;
    }
    struct node *ptr;
    tail->next->prev = NULL;
    while(ptr != NULL){
        ptr = tail->prev;
        free(tail);
        tail = ptr; 
    }
    return NULL;
}

int main(){
    printf("CIRCULAR DOUBLY LINKED LIST");

    int size;
    struct node *tail;
    tail = NULL;

    printNodes(tail, "Before Creating List");

    printf("\nEnter size of list you want to create: ");
    scanf("%d",&size);
    tail = createList(tail,size);
    printNodes(tail, "After Creating Circular doubly linked list");

    tail = addAtBeginning(tail, 66);
    printNodes(tail,"After Adding element at beginning of the list");

    tail = addAtEnd(tail,70);
    printNodes(tail,"After Adding new Node at End of the list");

    tail = delAtBeginning(tail);
    printNodes(tail, "After Deleting First node of list");

    tail = delAtEnd(tail);
    printNodes(tail, "After Deleting Last node of list");

    tail = delAtPosition(tail,3);
    printNodes(tail, "After Deleting node at position 3");

    tail = delEntireList(tail);
    printNodes(tail, "After Deleting Entire List");

    return 0;
}