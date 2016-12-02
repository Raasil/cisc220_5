#include<string.h>
#include <"udll.h">
#include <stdio.h>
#include <stdlib.h>

struct node 
{
 int data;
 struct node *next;
};

/* inserts a new node at the beginning of the list */
void push(struct node** head_ref, int new_data)

	struct node* new_node = (struct node*) malloc(sizeof(struct node)) ;
	new_node->data = new_data;
	new_node-> = (*head_ref);
	(*head_ref) = new_node;

/* Inserts a node after the given node */

void insertAfter(struct node* prev_node, int new_data)

	if (prev_node == NULL)
	{
	 printf("the given previous node cannot be NULL");
	 return;
	}

	struct node* new_node =(struct node*) malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;

/* adds a node to the end of the list */

void append(struct node** head_ref, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	struct node *last = *head_ref; 
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	while (last->next = new_node;
	return;
	}

/* prints the linked list */
void printList(struct node *node)
{
	while (node != NULL)
	{
		printf(" %d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct node* head = NULL;
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);
	printf("\n Created Linked List is: ");
	printList(head);

	return 0;
}
