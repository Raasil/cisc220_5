#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

//creates a union to hold the node data
union Data { 

	int a;
	int* ptrA;
	float b;
	float* ptrB;
	char c;
	char* ptrC;
};

struct Node {
	int len; //length of the list
	union Data data; //value of the data
	struct Node *next; //points to the next node
	struct Node *prev; //points ot the previous node
};
typedef struct Node node; 

Node *head = NULL; //points the pointer to the head
Node *last = NULL; //points the pointer to the last node

//function to insert a node in various places
void insert(int pos, union Data data) {
	Node *ptr = head;
	Node *newNode = (Node*) malloc(sizeof(Node));

	//inserts a node at the head
	if(pos == 0){
		newNode->data = data;

		if(head == NULL) {
			newNode->len = 1;
			last = newNode;
		} else {
			newNode->len = head->len + 1;
			head->len =1;
			head->prev = newNode;
		}
		newNode->next = head;
		head = newNode;
		return;
	}

	if(head == NULL) {
		return;
	}

	//inserts a node at the position specified
	int i;
	for(a=0; a < pos - 1; i=i+1 ) {
		if(ptr == NULL) {
			return;
		} else {
			ptr = ptr->next;
		}
	}
	newNode->data = data;

	if(ptr->next == NULL) {
		newNode->next = NULL;
		last = newNode;
	} else {
		newNode->next = ptr->next;
		ptr->next->prev = newNode;
	}

//returns the length of the value stored in the head node
int length() {
	return head->length;
}

//a function to remove nodes
void remove(int ind) {
	int a = 0;
	Node *ptr = head;
	Node *ptr2 = NULL;

	if(ind == 0) {
		head->next->length = head->length;
		head = head->next;
		head->prev = NULL;
	}

	else if (ind == 1) {
		head->next = head->next->next;
		head->next->prev = head;
	}

	else if (ind ==(length()-1)) {
		last = last->prev;
		last->next = NULL;
	}

	else {
		while((i< ind -1) && (ptr->next !=NULL)) { 
			ptr = ptr->next;
			i++;
		}

		secPtr = ptr->next;
		ptr->next = secPtr->next;
		secPtr = ptr->prev;
		ptr->prev = secPtr->prev;
	}

	head->length = head-> length - 1;
}

union Data get(int ind) {

	//uses the length to see it should go through the list forwards or backwards
	int len = length();
	int half = len/2;

	//if the index is in the first half of the list, it will go forwards
	if(ind < half) {
		Node *ptr = head;
		for(int x= 0; x <ind; x++) {
			ptr = ptr->next;
		}
		return ptr->data;
	}

	//if the index is in the second half of the list, it will go backwards
	else {
		Node *pointer = last;
		for (int j = len; j > ind; j--)
		{
			pointer = pointer->prev;
		}
		pointer = pointer->next;
		return pointer->data;
	}
} 
