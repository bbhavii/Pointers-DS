#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};
typedef struct node * NodeAddress;

/* ================================================== */
void swap(int *x, int *y) {
	int t;
	t = *x;
	*x = *y;
	*y = t;
}


/* ================================================== */
int * generateArray(int n) {
	int * t = malloc( n * sizeof(int) );
	if(t) {
		for(int i=0; i<n; i++) {t[i] = rand()%1000;}
	}
	return t;
}

NodeAddress linkedListFromArray(int * a, int n) {
	int i;
	NodeAddress head = NULL;
	NodeAddress temp = NULL;

	// special case for head
	if(n>0) {
		head = malloc( sizeof(struct node) );
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}


	for(i=1; i<n; i++) {
		temp->next = malloc( sizeof(struct node) );
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
}

void freeLinkedList(NodeAddress head) {
	NodeAddress prev;
	while(head) {
		prev = head;
		head = head->next;
		free(prev);
	}
}

/* ================================================== */
void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

void printArray1(int *a, int n) {
	for(int i=0; i<n; i++) {
		printf(" %d ", a[i]);
	}
}

void printLinkedList(NodeAddress head) {
	NodeAddress c;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) {
		printf( c==head?"%d":", %d", c->val);
	}
	printf(".\n");
}

/* ================================================== */

int findIndexOfMax(int *a, int n) {
	int imax; // this will contain the address of the largest element encountered.
	int i;

	// error case if there are no elements in the list
	if(n<1) {return -1;}

	imax = 0; // I am assuming that a[0] is the max element
	for(i=1; i<n; i++) {
		if( a[i] > a[imax] ) {
			imax = i;
		}
	}

	return imax;
}

void selectionSort(int *a, int n) {
	int i, imax, t;

	for(i=n; i>1; i=i-1) {
		imax = findIndexOfMax(a, i);
		t = a[imax]; a[imax] = a[i-1]; a[i-1] = t;
	}
}



/* ================================================== */
int main(int argc, char **argv) {
	int * a;
	int n = 10;
	int maxindex;
	int p, q;
	NodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);
	selectionSort(a,n);
	printArray(a,n);

	p = 5;
	q = 10;
	swap(&p, &q);
	printf("%d\n", p);


	free(a);
	freeLinkedList(list);

	return 0;
}