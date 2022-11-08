// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
};

typedef struct node * NodeAddress;

NodeAddress generateLinkedList(int a[],int n){

    NodeAddress head=malloc(sizeof(struct node));
    if(!a){
        return NULL;
    }
    else{
        
        head->val=a[0];
        head->next=NULL;
        NodeAddress temp=head;

        for(int i=1;i<n;i++){
            temp->next=malloc(sizeof(struct node));
            temp=temp->next;
            temp->val=a[i];
            temp->next=NULL;
        }
    }
    return head;

}

NodeAddress LinkedListReversal(NodeAddress head){
    NodeAddress prev=NULL;
    NodeAddress current=head;
    NodeAddress n=NULL;
    printf("The list is reversed.\n");
    while(current!=NULL){
        n=current->next;
        current->next=prev;
        //printf("current : %d,%d\n",current->val,n->val);
        prev=current;
        current=n;
        //printf("prev : %d,%d,%d\n",prev->val,current->val,n->val);
        //
    }
    head=prev;
    printf("head val %d\n",head->val);
    return(head);
}

void printLinkedList(NodeAddress head){
    NodeAddress temp=head;
    printf("The list is: %d",temp->val);
    temp=temp->next;
    while(temp){
        printf(", %d", temp->val);
        temp=temp->next;
    }
    printf(" .\n");
}

int main(){

    int a[]={1,2,3,4,5};
    NodeAddress list = generateLinkedList(a,5);
    printLinkedList(list);
    list = LinkedListReversal(list);
    printf("head %d\n",list->val);
    printLinkedList(list);

    return 0;
}