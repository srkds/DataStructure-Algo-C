#include<stdio.h>
#include<stdlib.h>
#define EMPTY "LIST IS EMPTY\n"
#define MSG(m) printf("\n%s\n",m)

struct node{
    int data;
    struct node *next;
};

/* Traverse and prints all the nodes of list */
void printNodes(struct node *tail, char msg[]){
    MSG(msg);
    if(tail == NULL){
       // If list is empty
       printf(EMPTY); 
    } else {
        // ptr points to first node of the list
        struct node *ptr = tail->next;
        do{
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }while(ptr != tail->next);
    }
}

/* Inserting a new node to a empty list */
struct node* addtoEmpty(struct node *tail, int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode;
    tail = newNode;
    return tail;
}

/* Inserting a new Node at End of List */
struct node* addAtEnd(struct node *tail, int data){
    if(tail == NULL){
        return addtoEmpty(tail,data);
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    // newNode's next points to first node
    newNode->next = tail->next;     
    tail->next = newNode;
    tail = newNode;
    return tail;
}

/* Creating a new List */
struct node* createList(struct node* tail, int size){
    if(size == 0){
        MSG("You entered 0 nodes to add in list");
        return tail;
    }

    int data,i;

    if(tail == NULL){
        printf("Enter Data for Node 1: ");
        scanf("%d",&data);
        tail = addtoEmpty(tail,data);
    }
    for(i = 1; i < size; i++){
        printf("Enter Data for Node %d: ",i+1);
        scanf("%d",&data);
        tail = addAtEnd(tail,data);
    }
    return tail;
}

/* Inserting new node at Beginning of list */
struct node* addAtBeginning(struct node *tail, int data){
    if(tail == NULL){
        tail = addtoEmpty(tail, data);
        return tail;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}

/* Inserting new node at certain position */
struct node* addAtPosition(struct node *tail, int data, int pos){
    if(pos == 0){
        return tail;
    }
    if(pos == 1){
        return addAtBeginning(tail,data);
    }

    // ptr points to first node of the list
    struct node *ptr = tail->next;
    while(pos > 2 && ptr->next != tail){
        ptr = ptr->next;
    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    // if it is at end of list
    if(ptr == tail){
        newNode->next = tail;
        ptr->next = newNode;
        return tail;  
    }

    newNode->next = ptr->next;

    ptr->next = newNode;
    return tail;
}

/* Deleting node at biginning of list */
struct node* deleteAtBeginning(struct node *tail){
    if(tail == NULL){
        return tail;
    }
    if(tail->next == tail){
        free(tail);
        tail = NULL;
    }
    struct node *ptr = tail->next;
    tail->next = ptr->next;
    free(ptr);
    ptr = NULL;
    return tail;
}

/* Deletes node at the end of list */
struct node* deleteAtEnd(struct node *tail){
    if(tail == NULL){
        return tail;
    }
    if(tail == tail->next){
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node *ptr = tail->next;
    while(ptr->next != tail){
        ptr = ptr->next;
    }
    ptr->next = tail->next;
    free(tail);
    tail = ptr;
    return tail;
}

struct node* deleteAtPosition(struct node *tail, int pos){
    if(pos == 0){
        return tail;
    }
    if(tail == NULL){
        return tail;
    }
    struct node *ptr = tail->next, *delNode;
    while(pos > 2){
        ptr = ptr->next;
        pos--;
    }
    if(ptr->next == tail){
        ptr->next = tail->next;
        free(tail);
        tail = ptr;
        return tail;
    }
    delNode = ptr->next;
    ptr->next = ptr->next->next;
    free(delNode);
    return tail;
}

/* Gives Total count of nodes in the list */
int count(struct node *tail){
    int count = 0;
    if(tail == NULL){
        return 0;
    }
    struct node *ptr = tail->next;
    do{
        count++;
        ptr = ptr->next;
    }while(ptr != tail->next);
    return count;
}

/* returns the value that we want to search */
int searchElement(struct node *tail, int key){
    if(tail == NULL){
        printf(EMPTY);
        return;
    }
    struct node *ptr = tail->next;
    do{
        if(ptr->data == key){
            printf("Data: %d",ptr->data);
            return;
        }
        ptr = ptr->next;
    }while(ptr != tail->next);
    printf("\nElement Not Found.");
    return;
}

int main(){
    printf("CIRCULAR SINGLY LINKED LIST\n");
    struct node *tail;
    tail = NULL;
    int size;

    printNodes(tail, "Before any addition to list");

    printf("How Many Element you want to Insert into List: ");
    scanf("%d",&size);
    tail = createList(tail,size);
    printNodes(tail,"After Creating List");

    // tail = addtoEmpty(tail,10);
    // printNodes(tail,"After Adding Node to Empty List");

    // tail = addAtEnd(tail,20);
    // printNodes(tail, "After Adding Node at End of the List");

    tail = addAtBeginning(tail, 32);
    printNodes(tail, "After Adding newNode at beginning of the list");

    tail = addAtEnd(tail, 77);
    printNodes(tail, "After Adding newNode at End of the list");

    tail = addAtPosition(tail, 45,5);
    printNodes(tail, "After Adding NewNode at certain position");

    tail = deleteAtBeginning(tail);
    printNodes(tail, "After Deleting node at beginning of list");

    tail = deleteAtEnd(tail);
    printNodes(tail,"After Deleting node at end of list");

    tail = deleteAtPosition(tail, 3);
    printNodes(tail, "After Deleting Node at certain position.");

    printf("\nNo of Nodes in list: %d\n", count(tail));
    searchElement(tail,90);

    return 0;
}