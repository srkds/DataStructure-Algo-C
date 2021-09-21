/* - Traversing a single linked list means vising each node of a single linked
     list until the end node is reached 
    - calculate total no of nodes by traversing the linked list.
*/
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

void createLinkedList(struct node *head){
	struct node *current = NULL;
	struct node *previous = NULL;
	previous = head;
	int data,status = 0;
	do {
		printf("\nAdd node yes=1, no=0: ");
		scanf("%d",&status);
		if(!status) break;
		current = malloc(sizeof(struct node));
		printf("\nEnter Data:");
		scanf("%d", &data);
		current->data = data;
		current->link = NULL;
		
		
		previous->link = current;
		previous = current;
	}while(status);
}

void count_of_nodes(struct node *head){
	int count = 0;
	if(head == NULL) printf("Linklist is empty");
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
		count++;
		
		// Printing the node data
		printf("%d \n",ptr->data);
		ptr = ptr->link;
	}
	printf("\n Count of Linst is: %d",count);
}
int main(){
	struct node *head = NULL;
	head = malloc(sizeof(struct node));
	head->data = 10;
	head->link = NULL;
	createLinkedList(head);
	count_of_nodes(head);
	return 0;
}

