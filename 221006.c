#include <stdio.h>
#include <stdlib.h>
/* ============================================= */
int * blah(int val){
    int x;
    int * pointer;
    x = val*val;
    return pointer;
}
/* ============================================= */

void printArray(int* a, int n){
    printf("Array = ");
    for( int i=0; i<n; i++){
        printf(i?", %d":"%d", a[i]);
    }
    printf(".\n");
}

void printArray1(int* a, int n){
    for( int i=0; i<n; i++){
        printf("%d", a[i]);
    }
}


void printLinkedList(NodeAddress head){
    NodeAddress c;
    printf("Array = ");
    for( c=head; c!=NULL; c=c->next){
        printf(c==head?"%d":", %d", c->val);
    }
    printf(".\n");
}

/* ============================================= */
int findIndexOfMax(int * a, int n){
    int imax;

    //if there are no elements in the list
    if(n<1) {return 0;}

    imax = 0; //assuming a[0] is the max element
    for(int i=1; i<n; i++){
        if(a[i] > a[imax]){
            imax = 1;
        }
    }

    return imax;

}   

int findAddressOfMax(int* a, int n){
    int *amax = NULL;

    if(n>=1){
        amax = a;
        for( int i=1; i<n ; i++){
            if (*(a+1) > *(a+*amax)) { amax = i;}
        }
    }

    return amax;
}

/* ============================================= */

void selectionSort(int * a, int n){
    int i, imax, t;
    for(i=n; i>1; i--){
        int imax = findIndexOfMax(a, i);
        swap( &a[imax], &a[i-1]); //swap(a+imax, a+i-1)
         
    }

    
   
}

/* ============================================= */
/*
void selectionSort2(int *a, int n){
    int *c;

    for(c = a+n-1; c!=a; c=c-1){
        swap( findAddressOfMax(a,c), c);
    }
}
*/
/* ============================================= */
/*
void insertionSort(){

}
*/
/* ============================================= */

void bubbleSort(int *a, int n){
    int i, done, t,swapped;

    for(done=0; done<n; done++){
        swapped = 0;
        for(i=0; i<n-1-done; i++){
            if(a[i]>a[i+1]){
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                swapped = 1;
            }
        }
        if(swap==0){
            break;
        }
    }
}




/* ============================================= */

void swap(int *x, int *y) {
	int t;
	t = *x;
	*x = *y;
	*y = t;
}


/* ============================================= */

int * generateArray(int n){
    int * t = malloc(n* sizeof(int));
    if(t) {
        for(int i=0; i<n; i++) { t[i] = rand()%1000; }
    }
    return *t;
}

NodeAddress linkedListFromArray(int *a, int n){
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;

    if(n>0){
        head = malloc(sizeof(struct node));
        head->val = a[0];
        head->next = NULL;
        temp = head;
    }


    for(int i=0; i<n; i++){
        temp = malloc(sizeof(struct node));
        temp = temp->next;
        temp->val = a[i];
        temp->next = NULL;
    }

    return head;

}
/* ============================================= */

struct node {
    int val;
    struct node *next;
};
typedef struct node * NodeAddress;
/* ============================================= */

void freeLinkedList(NodeAddress head){
    NodeAddress prev;
    while(head){
        prev=head;
        head=head->next;
        free(prev);
    }
}