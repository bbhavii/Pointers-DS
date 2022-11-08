#include <stdio.h>
#include <stdlib.h>


NodeAddress findRoot(NodeAddress x){
	if(x==NULL){
	    return NULL;
    }
	while(x->parent)
	{
		x=x->parent;
	}

}

typedef struct TreeNode * NodeAddress;

struct TreeNode{
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
	struct TreeNode * parent;
	int height;
};

int main(){
    return 0;
}