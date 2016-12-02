#include<stdlib.h>

#ifndef UDLL_H
#define UDLL_H

// define the union data structure
union Data {
	int a;
	int* ptrA;
	float b;
	float* ptrB;
	char c;
	char* ptrC;
};

// define the Node data structure
struct Node {
	struct Node* prev;
	int type;
	union Data data;
	struct Node* next;
};

static Node head = {NULL,0,{2},NULL};
static Node last = {NULL,0,{0},NULL};
typedef struct Node Node;

void insert(int index, union Data data, int type);
void remove(int index);
union Data get(int index);
int length();

#endif
