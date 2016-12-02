# ifndef UDLL_C
# define UDLL_C

// a structure that holds the node
struct Node {
   union Data data;
   struct Node *next; // points to the next node
   struct Node *prev; // points to the previous node
   int len;
};

// a union that holds the data of the node
union Data {
   int a;
   int* ptrA;
   float b;
   float* ptrB;
   char c;
   char* ptrC;
};

// call all the functions that were asked in the assignment
void insert(int pos, union Data data);
void remove(int index);
union Data get(int ind);
int length();

#endif
