#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node * next;
    
};

typedef struct node * NodeAddress;

NodeAddress generateList(int a[],int n){
    NodeAddress head=malloc(sizeof(struct node));
    if(!a){
        return NULL;
    }
    head->val=a[0];
    head->next=NULL;
    NodeAddress temp=head;
    for(int i=1;i<n;i++){
        temp->next=malloc(sizeof(struct node));
        temp=temp->next;
        temp->val=a[i];
        temp->next=NULL;
    }
    return head;
}

void printhalf(NodeAddress head){
    NodeAddress temp=head;
    NodeAddress count=head;
    printf("The first half is : %d", temp->val);
    temp=temp->next;
    count=count->next->next;
    while(count){
        printf(", %d",temp->val);
        temp=temp->next;
        count=count->next->next;
    }
    printf(". \n");
}

int main(){
    int a[] = {1,2,3,4,5,6};
    int n=6;
    NodeAddress list;
    list=generateList(a,n);
    printhalf(list);
    return 0;
}