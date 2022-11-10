#include <stdio.h>
#include <stdlib.h>


int func(int x, int y);

int (* pointer) (int x,int y);

void blah(int *a, int (* func)(int * x), int n){
    for(int i=0;i<n;i++){
        func(a[i]);
    }
}

//if you don't know what type your pointer is, then you can use void * 
//we have to compare the two variables but we cannot send a function so we send a pointer
void qsort(void * base, size_t n, size_t size, int ( * compare)(const void * a, const void * b)){
//you make the a,b const so that you don't mess with them
//you know the size of the function that you wrote so you don't need that



}

//since we can treat functions as pointers, we can have an array of functions




int main(){

    int (* say) (const char *);
    say = puts;
    //you can put this in an if-else, where you can have a function do multiple different things
    //but you call the same function
    //everything, input and output type should match
    say("hello");

    int a[100];
    int i = -23964923;
    printf("%d\n",a[i]);
    //int ( * table[UCHAR_MAX +1](int));

    int c;
   // for (i=0;i<UM,i++){
       // table[i]=putchar;
   // }

    return 0;
}