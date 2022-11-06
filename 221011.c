
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * generateArray(int n){

    int *a = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    return a;

}

void swap(int* a, int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

void swap1(int *x, int *y) {
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

void selectionSort(int* a, int n){
    int imin;

    for(int i=0;i<n;i++){
        imin = findMin(a,i,n);
        //int t = a[i];
        //a[i]=a[imin];
        //a[imin]=t;
        swap(&a[imin],&a[i]);

    }

}

int findMin(int *a,int i, int n){
    int min=i;
    for(i;i<n;i++){
        if(a[min]>a[i]){
            min = i;
        }
    }
    //printf("%d \n",min);
    return min;
}

void printArray(int *a, int n){

    printf("The array is : %d",a[0]);
    for(int i=1;i<n;i++){
        printf(", %d",a[i]);
    }
    printf(".\n");
}

int main(){

    int n=5;
    int *a;
    a=generateArray(n);
    printArray(a,n);
    //printf("Sorting");
    selectionSort(a,n);
    printArray(a,n);

    return 0;
}