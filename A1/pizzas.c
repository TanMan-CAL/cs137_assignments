#include <stdio.h>

int main (void){
    int num, slicesPP, slicesE;

    scanf("%d %d %d", &num, &slicesPP, &slicesE);

    int total = num * slicesE;

     
    int cond;
    if (total % slicesPP == 0){
        cond = total / slicesPP;
    } else {
        cond = (total / slicesPP) + 1;
    }
    
    printf("%d\n", cond);



}   