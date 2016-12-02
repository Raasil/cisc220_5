#include <stdio.h>
#include <stdlib.h>
#include "udll.h"

int main()
{
	union Data data1
	union Data data2
	union Data data3

	data1.i=3;
	data2.f = 6.9;
	data3.c = 'c';

	insert(0,data3);
	insert(0,data2);
	insert(0,data1);

	printf("The length of the list is %d\n", length());

	remove (1);

	printf("After removing the first node, the length of the list is %d\n", length());

	union Data myData = get(0);
	printf("The value in the first position is %d\n", myData.i);

	return 0;
}
