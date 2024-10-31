#include <stdio.h>

int main(void) {
    int q, a, m, f;
    scanf("%d %d %d", &q, &a, &m);
    

    int con1 = (50 - (0.05*q) - (0.2*a) - (0.3*m)) / 0.45;
    int con2 = (37.5 - (0.3*m)) /0.45;


    if (con1 > con2){
        printf("%d\n", con1);
    }
    else {
        printf("%d\n", con2);
    }

}