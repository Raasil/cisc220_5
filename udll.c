#include<stdlib.h>
#include "udll.h"

// 10107233 - Nicole Fitzgerald (ninkle) 10183626 - Raasil Khan (Raasil) 10161819 - Stefan Sokic (StefanSokic) 10102143 - Sabrina Quazi (sabrinaquazi)

//A function to inserts nodes at various places
void insert(int index, union Data data, int type) {
       
	Node myNode = {NULL, type, data, NULL};
	Node* newNode;
	newNode = malloc(sizeof(myNode));
	(*newNode) = myNode;

	
	if (head.next == NULL) {
		head.next = newNode;
		last.prev = newNode;
	}
        Node* ptr = NULL;
        Node* ptr2 = NULL;
        
	int i;
        
	//if the position is in the first half of the list, it will go forwads
	if (index <= length() / 2) {
                ptr = &head;
                ptr2 = (*ptr).next;
                for (i = 0; i < index - 1; i++) {
                        ptr=(*ptr).next;
                        secPtr=(*secPtr).next;
                }
                (*newNode).next = secPtr;
                (*newNode).prev = ptr;
                (*ptr).next = newNode;
                (*secPtr).prev = newNode;
        } 

	else {
                ptr = &last;
                for (i = 0; i < length() - index; i++) {
                        ptr=(*ptr).prev;
                        secPtr=(*(*ptr).prev).prev;
                } 
                (*newNode).next = secPtr;
                (*newNode).prev = ptr;
                (*ptr).next = newNode;
                (*secPtr).prev = newNode;
        } 

        head.data.d++;
} 


// removes a node from the list at the specified index
 
void remove(int ind) {
        Node* ptr = NULL;
        Node* secPtr = NULL;
        
	int i;
        if (ind <= length() / 2) {
                ptr = &head;
                secPtr = &head;
                for (i = 0; i < ind - 1; i++) {
                        ptr=(*ptr).next;
                        secPtr=(*(*ptr).next).next;
                } 
                (*ptr).next = secPtr;
                (*secPtr).prev = ptr;
        } 
         else {
                ptr = &last;
                for (i = 0; i < length() - ind; i++) {
                        ptr=(*ptr).prev;
                        secPtr=(*(*ptr).prev).prev;
                } 
                (*ptr).prev = secPtr;
                (*ptr2).next = ptr;
        }
        head.data.d--;
} 




//returns length of the linked list
int length() {
	return head.data.d;
}

union Data get(int ind) {
	Node* ptr = NULL;
	int i;
	if (ind <= length() / 2) {
		ptr = &head;
		for (i = 0; i < ind; i++) {
			ptr=(*ptr).next;
		} 
		return (*ptr).data;
	} else {
		ptr = &last;
		for (i = 0; i < length() - ind - 1; i++) {
			ptr=(*ptr).prev;
		} 
		return (*ptr).data;
	}
} 
