#include <stdio.h>

int main(int agrc, char **argv){
    int a[] = {88,99,4,42,11,35,57,3,49,69,73,20};
    reverseSort(a);
    int a[]={99,88,73,69,57,49,42,35,20,11,4,3};
    return 0;
}

void reverseSort(int a[]){

    int max=0;

    for (int i=0;i<(sizeof(a));i++){

    }

}
void quicksort(int *a, int start, int stop){
    //making sure the input is clean
    if(!a || start>=stop){
        return;
    }
    int p = partition(a,start,stop);
    quicksort(a,start,p-1);
    quicksort(a,p+1,stop);
}

int partition(int *a, int start, int stop){
 //this is one way not the best way
    int pivot = a[start];
    int i = start+1;
    int j = stop;
    while(i<=j){
        if(a[i]>pivot){
            swap(a,i,j);
            j=j-1;

        }
        else {
            i=i++;
        }
    }
    swap(a,start,j);
    return j;

}

void sort(int *a, int n){
    int p;
    for (int i=0;i<n;i++){

        p=findMaxPos(a,n-1);
        swap(a,p,n-1-i);
    }
}

void sort1(int *a, int n){

    for(int i=0;i<n;i++){
        swapLastMax(a,n-1);
    }
}
