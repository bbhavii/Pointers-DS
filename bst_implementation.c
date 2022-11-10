#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node * left;
    struct node * right;
};

typedef struct node * NodeAddress;


NodeAddress newNode(key){

    NodeAddress node = malloc(sizeof(struct node));

    node->key = key;
    node->right = NULL;
    node->left = NULL;

    return node;
}

NodeAddress insert(NodeAddress node, int key){

    if(node==NULL){
        NodeAddress temp = newNode(key);
        return temp;
    }
    if(key<node->key){
        node->left=insert(node->left,key);
    }
    else{
        node->right=insert(node->right,key);
    }
    return node;
}


NodeAddress search(NodeAddress root, int key){

    if(root->key == key || root==NULL){
        return root;
    }

    if(root->key<key){
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}

void printInOrder(NodeAddress root){
    printf("The tree is: ");
    if(root){
        printInOrder(root->left);
        printf("%d,",root->key);
        printInOrder(root->right);
    }
}

int main(){

    NodeAddress root;
    root = insert(root, 50);
    printInOrder(root);
    return 0;
}