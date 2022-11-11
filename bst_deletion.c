#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node * right;
    struct node * left;
};

typedef struct node * NodeAddress;

NodeAddress newNode(int key){
    NodeAddress temp = malloc(sizeof(struct node));
    temp->key = key;
    temp->right = NULL;
    temp -> left = NULL;

    return temp;
}

NodeAddress insertLeaf(NodeAddress head, int key){
    
    //printf("insert for head %d ",head->key);
    if(head==NULL){
        NodeAddress temp = newNode(key);
        return temp;
    }
    if(head->key<key){
        head->right= insertLeaf(head->right,key);
    }
    else{
        head->left= insertLeaf(head->left,key);
    }
    return head;
}

NodeAddress searchTree(NodeAddress head, int key){
    if (head==NULL || head->key==key){
        return head;
    }
    if(head->key<key){
        return searchTree(head->right,key);
    }
    else{
        return searchTree(head->left,key);
    }
}

void printInOrder(NodeAddress head){
    if(head!=NULL){
        printInOrder(head->left);
        printf("%d ",head->key);
        printInOrder(head->right);
    }
}

NodeAddress minKeyNode(NodeAddress head){

    NodeAddress temp=head;

    while(temp!=NULL && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;

}

NodeAddress maxKeyNode(NodeAddress head){

    NodeAddress temp=head;
    while(temp!=NULL && temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

NodeAddress delete(NodeAddress head, int key){

    if(head==NULL){
        return head;
    }
    if(head->key<key){
        head->right= delete(head->right,key);
    }
    else if(head->key>key){
        head->left= delete(head->left,key);
    }
    else{
        if(head->left==NULL){
            NodeAddress temp= head->right;
            free(head);
            return temp;
        }
        else if(head->right==NULL){
            NodeAddress temp= head->left;
            free(head);
            return temp;
        }
        NodeAddress temp=minKeyNode(head->right);

        head->key=temp->key;
        head->right = delete(head->right,head->key);
        
    }
    return head;
}



int main(){
    NodeAddress root;
    root = insertLeaf(root, 50);
    //printf("root %d", root->key);
    //printInOrder(root);
    root = insertLeaf(root, 40);
    root = insertLeaf(root, 30);
    printInOrder(root);
    root = delete(root, 40);
    printInOrder(root);
    return 0;
}