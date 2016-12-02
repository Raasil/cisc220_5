#include<stdlib.h>
#include<stdio.h>
#include "udll.h" 

// 10107233 - Nicole Fitzgerald (ninkle) 10183626 - Raasil Khan (Raasil) 10161819 - Stefan Sokic (StefanSokic) 10102143 - Sabrina Quazi (sabrinaquazi)

int main() {
	printf("TEST FUNCTION: \n");
	
	printf("The value of the head node: %d\n",head.data.d);
	printf("The value of the last node:  %d\n",last.data.d);

	printf("Adding an integer of value 6 at index 2 results in: \n");
	
	union Data data;
	int myint = 6;
	data.d = myint;
	int type = 0;
	int index = 2;
	
	insert(index, data, type);
	data = get(1);
	printf("Value stored at index 1: %d\n",data.d);
	printf("Length of the list: %d\n",length());

	printf("Adding an integer pointer at index 1 results in: \n");
	data.ptrd = &myint;
	type = 1;
	index = 1;

	printf("Removing the node at index 1 results in: \n");
	removeNode(1);
	data = get(0);
	printf("The value stored at index 1 of the list is now %s\n",data.ptrc);
	data = get(2);
	printf("The value stored at index 2 of the list is now %p\n",data.ptrd);
	printf("The length of the list is now %d\n",length());
	
	return 0;
} // end main
