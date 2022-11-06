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

void swapq(int *a, int i, int j){
    //printf("sent %d, %d\n",a[i],a[j]);
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
    //printf("swapped %d, %d\n",a[i],a[j]);
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

void insertionSort(int *a, int n){
    
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            if(a[j]<a[j-1]){
                swap(&a[j],&a[j-1]);
            }
        }
    }
}

int partition1(int *a, int start, int stop,int n){
    int p = a[start];
    int i = start+1;
    int j = stop;
    while(i<j){
        if(a[i]>p){
            //printf("to swap %d,%d\n", a[i],a[j]);
            swapq(a,i,j);
            j=j-1;
        }
        else{
            i=i+1;
        }
    }
    //printf("to swap %d,%d\n", a[i],a[j]);
    swapq(a,start,j);
    //printArray(a,n);
    return j;
}

void quickSort1(int *a, int start, int stop, int n){
    
    if(start<stop){
        int p = partition1(a, start,stop,n);
        //printf("%d, %d\n", p,a[p]);
        quickSort1(a,start,p-1,n);
        quickSort1(a,p+1,stop,n);
        //printArray(a,n);
    }
}

void quickSort(int *a, int start, int stop){
    //making sure the input is clean
    if(!a || start>=stop){
        return;
    }
    int p = partition(a,start,stop);
    quickSort(a,start,p-1);
    quickSort(a,p+1,stop);
}

int partition(int *a, int start, int stop){
 //this is one way not the best way
    int pivot = a[start];
    int i = start+1;
    int j = stop;
    while(i<=j){
        if(a[i]>pivot){
            swapq(a,i,j);
            j=j-1;

        }
        else {
            i=i++;
        }
    }
    swapq(a,start,j);
    return j;

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
    int *c;
    int *d;
    printf("The new array\n");
    a=generateArray(n);
    printArray(a,n);
    printf("Selection Sorting\n");
    selectionSort(a,n);
    printArray(a,n);
    printf("The new array\n");
    c=generateArray(n);
    printArray(c,n);
    printf("Insertion Sorting\n");
    insertionSort(c,n);
    printArray(c,n);
    printf("The new array\n");
    d=generateArray(n);
    printArray(d,n);
    printf("Quick Sorting\n");
    quickSort1(d,0,n-1,n);
    printArray(d,n);
    

    return 0;
}