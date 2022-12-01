#include <stdio.h>
#include <stdlib.h>


/*
You can have 2 ways to access a list:
FIFO - First In First Out - Queue
LIFO - Last In First Out - Stack

Insertion is the same, only extraction is different.

Stack of positive numbers only.

*/

struct stackType{
    int * data;
    int size;
    int top;
};

typedef struct stackType * StackAddress;

StackAddress initStack(){
    StackAddress s = malloc(sizeof(struct stackType));
    s->top = -1;
    s->size=100;
    s->data = malloc(s->size*sizeof(int));
    return s;
}

void freeStack(StackAddress s){
    free(s->data);
    free(s);
}

int insertStack(StackAddress s, int val){
    if(s->top==(s->size-1)) {return -1;}
    if(val<0) {return -2;} //says stack is full
    s->data[(s->top+1)] = val;
    s->top=s->top+1;
    return val;
}

int extractStack(StackAddress s){
    if(s->top<0) return -1; //stack is empty
    int val = s->data[s->top];
    s->top=s->top-1;
    return val;
}

int main(){
    StackAddress s = initStack();

    insertStack(s,10);
    insertStack(s,20);
    insertStack(s,30);
    insertStack(s,555);

    printf("%d\n",extractStack(s));
    printf("%d\n",extractStack(s));
    printf("%d\n",extractStack(s));
    printf("%d\n",extractStack(s));

    freeStack(s);
    return 0;
}