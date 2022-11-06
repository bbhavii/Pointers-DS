#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int x =*a;
    *a=*b;
    *b=x;
}

void printArray1(int* t,int n){

    printf("The array is : %d",t[0]);
    for(int i=1;i<n;i++){
        printf(", %d",t[i]);
    }
}

void printArray(int * a, int n) {
	printf("Array = ");
	for(int i=0; i<n; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}

int * generateArray(int n){
    int *t = malloc(n*(sizeof(int)));
    if(t){
        for(int i=0;i<n;i++){
            t[i]=rand()%1000;
        }
    }
    return t;
}



int main(int argc, char **argv) {
    
    int j=5;
    int *i=&j;
    int q=6;
    // printf("%d\n",j);
    // printf("%x\n",*i);
    // printf("%d\n",q);
    srand(time(NULL));

    int n =5;
    int *a = generateArray(n);

    swap(&j,&q);
    printf("%d\n",*a);
    printArray(a,n);
    // free(a);

    return 0;
}
