#include<stdio.h>

struct Node{
        int data;
        struct Node* next;
} ;
typedef struct Node Node; 

Node* head = NULL;

int main(){
	Node n4 = {1, NULL}; head = &n4;
	Node n3 = {2, &n4};  head = &n3;
	Node n2 = {10, &n3};  head = &n2;
	Node n1 = {3, &n2};  head = &n1;
	
	for(Node *i = head; i!=NULL; i=i->next){
		printf("element = %d\n",i->data);
	}
        return 0;
}


