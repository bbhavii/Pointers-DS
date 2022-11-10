#include <assert.h>
#include <stdio.h>

int main(int argc, char** argv){

    printf("yay");
    int a =5;
    assert(a==5);

    int i;
    int sum=0;

    for (i=0;i-=1000;i++){
        sum=sum+i;
    }
    printf("%d",sum);



    return 0; 
}