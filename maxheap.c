#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int a[], int n, int h){
    int largest = h;
    int left = h*2 + 1;
    int right = h*2 + 2;

    if(left<n && a[left]>a[largest]){
        largest=left;

    }
    if(right<n && a[right]>a[largest]){
        largest=right;
    }
    if(largest != h){
        swap(&a[h],&a[largest]);

        heapify(a,n,largest);
    }
}

void heapSort(int arr[], int n) {

  // Build max heap
    for (int i = n - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

    // Heapify root element to get highest element at root again

        heapify(arr, i, 0);

    }
    for (int i = n / 2 - 1; i >= 0; i--)

    heapify(arr, n, i);

  // Heap sort



}
/*
void buildHeap(int a[], int n){

    int head = (n/2)-1;
    for(int i=head;i>=0;i--){
        heapify(a,n,i);
    }
}
*/
void printHeap(int a[], int n){
    printf("The heap is: \n");

    for( int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    int a[] = {1,3,2,7,5};
    heapSort(a,5);
    printHeap(a,5);
    return 0;
}
