// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
This program contains parts taken from my GitHub which were uploaded on November 8th.
This program is for the creation of a linked list with an extra node, nodek and extra int, k=5, which
points to the next 5th node in a list. 
All the pointers have been checked for functioning and there is an example of some node which
leads to the next to next kth node.
The task of assigning the right 5th node to the node nextk is performed after the creation of the
linked list and definiton of a 5 for each node.
*/


int * generateArray(int a[],int n){

    int *b = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    return b;

}

void printArray(int *a, int n){

    printf("The array is : %d",a[0]);
    for(int i=1;i<n;i++){
        printf(", %d",a[i]);
    }
    printf(".\n");
}

struct node{
    int val;
    struct node * next;
    int k;
    struct node * nextk;
};

typedef struct node * NodeAddress;
//this function is just taken from the last part with conversion of next2 to nextk with assigning k
NodeAddress generateLinkedList(int * a,int n){

    NodeAddress prev;

    NodeAddress head=malloc(sizeof(struct node));
    if(!a){
        return NULL;
    }
    else{
        
        head->val=a[0];
        head->next=NULL;
        head->k=5;
        head->nextk=NULL;
        NodeAddress temp=head;
        temp->next=malloc(sizeof(struct node));
        prev = temp;
        temp=temp->next;
        temp->val=a[1];
        temp->k=5;
        temp->next=NULL;
        temp->nextk=NULL;//the nextk pointer will be assigned after creation of the entire list


        for(int i=2;i<n;i++){
            temp->next=malloc(sizeof(struct node));
            prev=temp;
            temp=temp->next;
            temp->val=a[i];
            temp->k=5;
            temp->next=NULL;
            temp->nextk=NULL;
        }
    } 
    return head;

}

NodeAddress LinkedListReversal(NodeAddress head){
    NodeAddress prev=NULL;
    NodeAddress preprev=NULL;
    NodeAddress current=head;
    NodeAddress n=NULL;
    printf("The list is reversed.\n");
    while(current!=NULL){
        n=current->next;
        current->next=prev;
        //current->next2=preprev;
        //printf("current : %d,%d\n",current->val,n->val);
        preprev=prev;
        prev=current;
        current=n;
        //printf("prev : %d,%d,%d\n",prev->val,current->val,n->val);
        //
    }
    head=prev;
    //printf("head val %d\n",head->val);
    return(head);

}


void printLinkedList(NodeAddress head){
    NodeAddress temp=head;
    printf("The list is: %d(k=%d)",temp->val,temp->k);
    temp=temp->next;
    while(temp){
        printf(", %d", temp->val);
        temp=temp->next;
    }
    printf(" .\n");
}

//this is the function where the nextk pointers are assigned based on the assigned k

NodeAddress arrayToLLWithNextK(int * a, int n){
    NodeAddress head=NULL;
    head = generateLinkedList(a,n);
    //printLinkedList(head);
    NodeAddress temp=head;
    while(temp->next->next!=NULL){
        int check = 0;
        NodeAddress fork=temp;
        if(temp->next->next){
            fork=temp->next->next;
            check=2;
        }
        for(int i=3;i<=temp->k;i++){
            if(fork->next!=NULL){
                fork=fork->next;
                check=i;
            }
        }
        if(check==temp->k){
            temp->nextk=fork;
            //printf("temp %d\n",temp->val);            
        }
        else{
            temp->nextk=NULL;
        }
        temp=temp->next;
    }
    return head;
}


int main(){

    int a[]={1,2,3,4,5,8,15,14,12,11};
    int n=10;
    int * arr=generateArray(a,n);
    printArray(arr,n);
    NodeAddress list = arrayToLLWithNextK(arr,n);
    //printf("head %d\n",list->val);    
    printLinkedList(list);
    //printf("%d\n",list->next2->next2->val);
    //list = LinkedListReversal(list);
    printf("val of node: %d, val %d elements later : %d\n",list->val,list->k,
    list->nextk->val);
    //printf("%d\n",list->next2->next->val);

    return 0;
}