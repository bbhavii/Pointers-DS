#include <stdio.h>

int main(int agrc, char **argv){

    return 0;
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