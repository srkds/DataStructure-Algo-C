/* 
    DOUBLY LINKED LIST
    FUNCTIONS:
    printNodes()
    addInEmptyList()
    insertAtBeginning()
    insertAtEnd()
    insertAfterPosition()
    createList()
    delFirst()
    delLast()
    delAtPosition()
    reverseList()
    delEntireList()

 */

#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void printNodes(struct node *head, char msg[]){
    printf("\n%s\n",msg);
    struct node *ptr = head;

    if(head == NULL){
        printf("LIST IS EMPTY!");
    } else {
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

/* add new node in empty list */
struct node* addInEmptyList(struct node *head, int data){
    head = (struct node*)malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = data;
    head->next = NULL;

    return head;
}


/* Inserting new node at beginning of the list */
struct node* insertAtBeginning(struct node *head, int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = head;

    head = newNode;
    return head;    
}

/* Inserting new node at end of the list */
void insertAtEnd(struct node *head, int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *ptr = NULL;
    ptr = head;
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
}

/* Inserting node after position */
void insertAfterPosition(struct node *head, int data, int pos){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    struct node *ptr = head;
    while(pos != 1){
        ptr = ptr->next;
        pos--;
    }
    newNode->next = ptr->next;
    newNode->prev = ptr;

    newNode->next->prev = newNode;
    ptr->next = newNode;
}

/* Creating New List */
struct node* createList(struct node *head, int n){
    int data;
    if(n == 0){
        return head;
    }
    if(head == NULL){
        printf("\nValue: ");
        scanf("%d", &data);
        head = addInEmptyList(head,data);
    }
    while(n != 1){
        printf("\nValue:");
        scanf("%d",&data);
        insertAtEnd(head,data);
        n--;
    }
    return head;
}

/* Delete first node */
struct node* delFirst(struct node *head){
    if(head == NULL){
        printf("LIST IS EMPTY!");
        return head;
    }
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

/* Delete last node */
void delLast(struct node *head){
    if(head == NULL){
        printf("LIST IS EMPTY!");
    } else {
        struct node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        ptr = NULL;
    }
}
/* Delete at certain position */
void delAtPosition(struct head *head, int pos){
    struct node *ptr = head;
    while(pos != 1){
        ptr = ptr->next;
        pos--;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;

    free(ptr);
    ptr = NULL;
}

/* Reverse list */
struct node* reverseList(struct node *head){
    struct node *prevNode, *nextNode;
    prevNode = nextNode = NULL;
    prevNode = head;
    nextNode = prevNode->next;
    prevNode->next = NULL;
    prevNode->prev = nextNode;

    while(nextNode != NULL){
        nextNode->prev = nextNode->next;
        nextNode->next = prevNode;
        prevNode = nextNode;
        nextNode = nextNode->prev;
    }
    head = prevNode;
    return head;
}

/* Delete Entire List */
struct node* delEntireList(struct node *head){
    while(head->next != NULL){
        head = head->next;
        free(head->prev);
    }
    free(head);
    head = NULL;
    return head;
}

int main(){
    printf("\n DOUBLY LINKED LIST \n");

    int n,pos,data;
    struct node *head = NULL;

    printf("How many no of nodes you want to add? :");
    scanf("%d",&n);
    head = createList(head,n);
    printNodes(head,"After Creating list");

    insertAtEnd(head,30);
    printNodes(head,"After inserting node at end.");

    head = insertAtBeginning(head, 60);
    printNodes(head, "After inserting node at beginning.");

    printf("\nEnter postion:");
    scanf("%d",&pos);
    printf("\nEnter Value: ");
    scanf("%d",&data);
    insertAfterPosition(head,data,pos);
    printNodes(head,"After inserting node after given position");
    
    head = reverseList(head);
    printNodes(head, "After revercing list");

    head = delFirst(head);
    printNodes(head, "After Deleting first node");

    delLast(head);
    printNodes(head,"After Deleting last node");

    printf("\nEnter position to delete node:");
    scanf("%d",&pos);
    delAtPosition(head,pos);
    printNodes(head, "After deleting at certain position");

    head = delEntireList(head);
    printNodes(head, "After Deleting entier list");

    return 0;   
}