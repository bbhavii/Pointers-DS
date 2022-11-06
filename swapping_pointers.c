#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *p, int *q){

    int *t=*p;
    *p=*q;
    *q=t;

}

void swap1(int *p, int *q){

    int *t=&p;
    *p=&q;
    *q=t;

}

int main(){

    int * p;
    int * q;
    
    p=5;
    q=12;
    printf("p %p , %d\n",p,p);
    printf("q %p , %d\n",q,q);
    swap(&p,&q);
    printf("p %p , %d\n",p,p);
    printf("q %p , %d\n",q,q);

    swap1(&p,&q);
    printf("p %p , %d\n",p,p);
    printf("q %p , %d\n",q,q);
    return 0;
}
