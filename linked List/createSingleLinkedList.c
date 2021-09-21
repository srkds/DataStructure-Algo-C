/* SINGLY LINKED LIST
    FUNCTIONS:
    printNodes() - traverse and prints all nodes
    create_linked_list() - creates linked list
    addatbeginning() - insert node at beginning of list
    insertAtEnd() - insert node at end of the list
    insertAtPosition() - insert at certain position in list
    delFirst() - delete first node of list
    delLast() - delete end node
    delAtPosition() - delete the node of given position
    reverseList() - reverse list
    delEntireList() - deletes entire list
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// traversing list and printing nodes
void printNodes(struct node *head, char msg[]){
    printf("\nMSG: %s\n",msg);
    struct node *ptr = head;
    if(head == NULL){
        printf("\nLIST IS EMPTY!");
    } else {
        while(ptr != NULL){
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
    }
}

// adding new nodes to the list
void create_linked_list(struct node *head){
    struct node *current = head, *newnode;
    int status;

    printf("Do you want to Add more node? y(1)/n(0):");
    scanf("%d", &status);

    while(status){
        int val;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter value for current NODE: ");
        scanf("%d",&val);
        newnode->data = val;
        newnode->next = NULL;
        current->next = newnode;
        current = current->next;

        printf("Do you want to Add more node? y(1)/n(0):");
        scanf("%d", &status);
    }
}

// inserting a node at beginning position
struct node* addatbeginning(struct node *head,int value){
    /* Creating new node */
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    /* Adding at beginning */
    newNode->next = head;
    head = newNode;
    return head; // need to return head to reflect on actual head at main
}

// inserting a node at last position
void insertAtEnd(struct node *head, int val){

    // creating newNode
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    /* node for traver till end */
    struct node *ptr = head;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    /* adding node at end */
    ptr->next = newNode;
}

// inserting a node at certain position
void insertAtPosition(struct node *head, int val, int pos){
    /* val - is data
        pos - position to add new node
        head - list
     */

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    struct node *ptr = head;
   
    while(pos != 2){
        ptr = ptr->next;
        pos--;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

/* Delete first node */
struct node* delFirst(struct node *head){
    struct node *ptr = NULL;
    ptr = head;
    head = head->next;
    free(ptr);
    ptr = NULL;
    return head;
}
/* Delete Last node */
void delLast(struct node *head){
    struct node *ptr = head;

    /* reaching to the second last position */
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    free(ptr->next); //releasing last node
    ptr->next = NULL; // setting second last node's next as NULL
}

/* Delete node at particular position */
void delAtPosition(struct node *head, int pos){
    struct node *prev = head;
    struct node *current = head;
    if(head == NULL)
        printf("List Is already Empty");
    else {
        while(pos != 1){
            prev = current;
            current = current->next;
            pos--;
        }
        prev->next = current->next;
        free(current);
        current = NULL;
    }
}

/* reverse list */
struct node* reverseList(struct node *head){
    struct node *prev, *next;
    prev = NULL;
    next = NULL;
    if(head == NULL){
        printf("LIST IS EMPTY");
        return head;
    }
    prev = head;
    head = head->next;
    next = head->next;

    /* For first node */    
    head->next = prev;
    prev->next = NULL;
    
    prev = head;
    head = next;

    /* for rest of the node */
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

/* Deleting Entire List */
struct node* delEntireList(struct node* head){
    struct node *ptr;
    while(head != NULL){
        ptr = head;
        head = head->next;
        free(ptr);
    }
    return head;
}

int main(){
    int val,pos;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    // struct node *traverse = NULL;
    printf("Enter Data for 1st node: ");
    scanf("%d",&val);

    head->data = val;
    head->next = NULL;

    create_linked_list(head);
    printNodes(head, "After Creating List");
    
    printf("\nEnter Value to add at Beginning: ");
    scanf("%d",&val);
    head = addatbeginning(head, val);
    printNodes(head, "After Add At Beginning");

    printf("\nEnter Value to add at End: ");
    scanf("%d",&val);
    insertAtEnd(head,val);
    printNodes(head,"After inserting node at end");

    printf("\nINSERT AT POSITION\nposition: ");
    scanf("%d",&pos);
    printf("\nvalue: ");
    scanf("%d",&val);
    insertAtPosition(head,val,pos);
    printNodes(head, "After Adding value at position");

    head = delFirst(head);
    printNodes(head, "After Deleting First node");

    delLast(head);
    printNodes(head,"After Deleting Last node");

    printf("\nEnter Position to delete:");
    scanf("%d",&pos);
    delAtPosition(head,pos);
    printNodes(head, "After Deleting node at position");

    head = reverseList(head);
    printNodes(head, "After Reversing list");

    head = delEntireList(head);
    printNodes(head, "After Deleting Entire List");

    return 0;
}