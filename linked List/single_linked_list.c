#include<stdio.h>
#include<stdlib.h>

// link == next: pointer to next node
// data: value or data of current node
struct node{
	int data;
	struct node *link;
};

int main(){
	// head: is a start node of the linked list
	// which contains the address of the first node of linked list
	struct node *head = malloc(sizeof(struct node));
	head->data = 10;
	head->link = NULL;
	
	// creating 2nd node
	struct node *current = malloc(sizeof(struct node));
	current->data = 20;
	current->link = NULL;
	
	// assigning address of 2nd node to link of the 1st node
	head->link = current;
	
	// creating 3rd node by resuing current pointer
	current = malloc(sizeof(struct node));
	current->data = 30;
	current->link = NULL;
	
	// linking 2nd node to 3rd node
	head->link->link = current;
	
	printf("1st node Data: %d \n", head->data);
	printf("2nd node data: %d \n",head->link->data);
	printf("3rd node data: %d \n",head->link->link->data);
	
	
	return 0;
}
