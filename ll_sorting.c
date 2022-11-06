#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int val;
    struct node * next;

};

typedef struct node * NodeAddress;

int * generateArray(int n){

    int *a = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    return a;

}
/*
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
*/

NodeAddress LastNode(NodeAddress head){
    printf("head %d\n",head->val);
    NodeAddress temp =head;
    while(temp!=NULL && temp->next!=NULL){
        printf("temp loop%d\n",temp->val);
        temp=temp->next;
    }
    printf("temp %d\n",temp->val);
    return temp;
}
/*void quickSort1(int *a, int start, int stop, int n){
    
    if(start<stop){
        int p = partition1(a, start,stop,n);
        //printf("%d, %d\n", p,a[p]);
        quickSort1(a,start,p-1,n);
        quickSort1(a,p+1,stop,n);
        //printArray(a,n);
    }
}
*/
NodeAddress partition(NodeAddress head,NodeAddress end){
    NodeAddress pivot=head;
    NodeAddress temp=head;
    
    while(temp && temp!=end){
        if(temp->val<end->val){
            pivot=head;
            
            int t = head->val;
            head->val = temp->val;
            temp->val = t;
 
            // Visiting the next node
            temp = temp->next;
        }
        
    }
    int t = head->val;
    head->val = end->val;
    end->val = t;
    return pivot;
    
}

void quickSort(NodeAddress head, NodeAddress end)
{
    if (head == end) {
        return;
    }
    NodeAddress pivot = partition(head, end);
 
    if (pivot != NULL && pivot->next != NULL) {
        quickSort(pivot->next, end);
    }
 
    if (pivot != NULL && head != pivot) {
        quickSort(head, pivot);
    }
}

void insertionSort(NodeAddress head){
    //printf("head isort: %d\n",head->val);
    for(NodeAddress temp=head;temp!=NULL;temp=temp->next){
        //printf("temp loop1: %d\n",temp->val);
        for(NodeAddress temp2=head;temp2!=NULL;temp2=temp2->next){
            //printf("temp loop2: %d\n",temp2->val);
            //printf("yay");
            if(temp2 && !temp2->next){
                //printf("temp loop2 temp null: %d\n",temp2->val);
                break;
            }
            else if(temp2->next->val<temp2->val && temp2->next != NULL){
                //printf("temp loop2 switch: %d\n",temp2->val);
                int t=temp2->next->val;
                temp2->next->val=temp2->val;
                temp2->val=t;
            }
            //printf("temp loop2:\n");
            //printlinkedList(head);
        }
        //printlinkedList(head);
    }
    
}

void swap(NodeAddress a, NodeAddress b){
    NodeAddress temp;
    int t;
    t=a->val;
    a->val=b->val;
    b->val=t;
}

NodeAddress findNodeMin(NodeAddress head){
    NodeAddress min,temp;
    min = head;
    temp = head;
    while(temp){
        if(min->val>temp->val){
            min = temp;
            
            if(temp->next == NULL){
                return min;
            }
            else{
                temp=temp->next;
            }
        }
        
        else{
            temp=temp->next;
        }
    }
    return min;
}

void SelectionSort(NodeAddress head){
    
    printf("head %d \n", head->val);
    NodeAddress min,temp,temp2;
    temp=head;
    
    while(temp){
        if(temp->next==NULL){
            min=findNodeMin(temp);
            int t=min->val;
            min->val=temp->val;
            temp->val=t;
            
        }
        else{
            min = findNodeMin(temp);
            //temp2->val=temp->val;
            //swap(min,temp);
            int t=min->val;
            min->val=temp->val;
            temp->val=t;
            
            //printlinkedList(head);
        }
        temp=temp->next;
    }
    printf("The list is sorted.\n");
}



NodeAddress generatelinkedList(int* a, int n){

    NodeAddress head;
    NodeAddress temp;

    if(n>0){
        head = malloc(sizeof(int));
        head->val = a[0];
        head->next = NULL;
        temp = head ;
    }
    for(int i=1;i<n;i++){
        temp->next = malloc(sizeof(struct node));
        temp = temp->next;
        temp->val = a[i];
        temp->next=NULL;
    }
    return head;
}

void FreeLinkedList(NodeAddress head){
    NodeAddress temp;
    while(head){
        temp=head;
        head= head->next;
        free(temp);
    }
}

void printlinkedList(NodeAddress head){
    printf("The list is: %d",head->val);
    NodeAddress temp = head->next;
    while(temp){
        printf(", %d",temp->val);
        temp = temp->next;
    }
    printf(".\n");
}

void printArray(int * a, int n){
    printf("The array is: %d",a[0]);
    for(int i=1;i<n;i++){
        printf(", %d",a[i]);
    }
    printf(".\n");
}

int main(){

    int n =7;
    int* a;
    NodeAddress list;
    a = generateArray(n);
    printArray(a,n);
    list = generatelinkedList(a,n);
    printlinkedList(list);
    NodeAddress end = LastNode(list);
    printf("end %d", end->val);
    quickSort(list,end);
    printlinkedList(list);
    return 0;
}