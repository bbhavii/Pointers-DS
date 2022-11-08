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
    //printf("head %d\n",head->val);
    NodeAddress temp=head;
    while(temp!=NULL && temp->next!=NULL){
    ///printf("temp loop one%d\n",temp->val);
        temp=temp->next;
        //printf("temp loop done%d\n",temp->val);
    }
    //printf("temp %d\n",temp->val);
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
    //printf("head %d\n",head->val);
    NodeAddress pivot=head;
    NodeAddress temp=head;
    NodeAddress start=head;
    int p = end->val;
    //printf("pivot %d\n",pivot->val);
    while(start && start!=end){
        if(start->val<p){
            //printf("pivot cond%d\n",pivot->val);
            pivot=temp;
            
            int t = start->val;
            start->val = temp->val;
            temp->val = t;
            //printf("temp %d\n",temp->val);
            // Visiting the next node
            temp = temp->next;
            //printlinkedList(head);
        }
        start=start->next;
        //printf("temp no switch %d\n",temp->val);
        //printlinkedList(head);
        
    }
    int t = temp->val;
    temp->val = end->val;
    end->val = t;
    //printf("pivot outside %d\n",pivot->val);
    return pivot;
    
}

void quickSort(NodeAddress head, NodeAddress end){
    //printf("head %d\n",head->val);
    
    if (head->val == end->val) {
        //printf("head return %d\n",head->val);
        return;
    }
    NodeAddress pivot = partition(head, end);
    //printf("pivot %d\n",pivot->val);
    if (pivot != NULL && pivot->next != NULL) {
        //printf("sort from %d,%d\n",pivot->next->val,end->val);
        quickSort(pivot->next, end);
        //printlinkedList(head);
    }
 
    if (pivot != NULL && head != pivot) {
        //printf("sort from %d,%d\n",head->val,pivot->next->val);
        quickSort(head, pivot);
        //printlinkedList(head);
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
    
    //printf("head %d \n", head->val);
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
    printf("Selection sort implemented:\n");
}



NodeAddress generatelinkedList(int* a, int n){

    NodeAddress head;
    NodeAddress temp;

    if(n>0){
        head = malloc(sizeof(struct node));
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

    int n =5;
    int* a;
    NodeAddress list,list2,list3;
    a = generateArray(n);
    printArray(a,n);
    list = generatelinkedList(a,n);
    list2 = generatelinkedList(a,n);
    list3 = generatelinkedList(a,n);
    printlinkedList(list);
    NodeAddress end = LastNode(list);
    //printf("end %d", end->val);
    printf("Quick sort implemented:\n");
    quickSort(list,end);
    printlinkedList(list);
    SelectionSort(list2);
    printlinkedList(list2);
    printf("Insertion sort implemented:\n");
    insertionSort(list3);
    printlinkedList(list3);
    return 0;
}