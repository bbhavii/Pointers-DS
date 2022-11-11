#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	struct TreeNode * parent;
	int height;
};

typedef struct TreeNode * NodeAddress;

int height(NodeAddress head){
	if(head==NULL){
		return 0;
	}
	return head->height;
	
}

NodeAddress findRoot(NodeAddress x){
	if(x==NULL){
	    return NULL;
    }
	while(x->parent)
	{
		x=x->parent;
	}
	return x;

}

int max(int a, int b){
	return (a>b)?a:b;
}

NodeAddress newNode(int key){

	NodeAddress head = (NodeAddress)(malloc(sizeof(struct TreeNode)));

	head->val=key;
	head->left=NULL;
	head->right=NULL;
	head->parent=NULL;
	head->height=1;

	return head;
}

NodeAddress rightRotate(NodeAddress r){
	NodeAddress l =r->left;
	NodeAddress T2 = r->right;

	l->right=r;
	l->left=T2;

	r->height=max(height(r->left),height(r->right))+1;
	l->height=max(height(l->left),height(l->right))+1;

	return l;
}
NodeAddress leftRotate(NodeAddress l){
	NodeAddress r=l->right;
	NodeAddress T2 = l->left;

	r->left=l;
	l->right=T2;

	r->height=max(height(r->left),height(r->right))+1;
	l->height=max(height(l->left),height(l->right))+1;	

	return r;
}
int getBalance(NodeAddress head){
	if(head==NULL){
		return 0;
	}
	return ((height(head->left))-(height(head->right)));
}

NodeAddress insert(NodeAddress head, int key){
	if(head==NULL){
		return newNode(key);
	}
	if(head->val>key){
		head->left=insert(head->left, key);
	}
	else if(head->val<key){
		head->right=insert(head->right,key);
	}
	else{
		return head;
	}

	head->height=max(height(head->right),height(head->left))+1;

	int balance = getBalance(head);

	if(balance>1 && key<head->left->val){
		return rightRotate(head);
	}
	if(balance<-1 && key>head->right->val){
		return leftRotate(head);
	}
	if(balance>1 && key>head->left->val){
		head->left=leftRotate(head->left);
		return rightRotate(head);
	}
	if(balance<-1 && key<head->left->val){
		head->right=rightRotate(head->right);
		return leftRotate(head);
	}
	return head;
}

void printInOrder(NodeAddress head){
	if(head!=NULL){
		printInOrder(head->left);
		printf("%d ",head->val);
		printInOrder(head->right);
	}
}

int main(){
	NodeAddress head;
	head = insert(head,10);
	head = insert(head,20);
	head = insert(head,30);
	head = insert(head,40);
	head = insert(head,50);
    //printf("balance %d",getBalance(head));
	printInOrder(head);
	head = insert(head,25);
	printf("\nTree is: \n");
	printInOrder(head);
    return 0;
}
