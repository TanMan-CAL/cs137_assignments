#include <stdio.h>

int main(void) {
    int num, denom;
    scanf("%d %d", &num, &denom);
    
    int div = num / denom;
    int rem = num % denom;
    
    int final;
    if (num == 0) {
        final = 0;

    } else if (rem == 0) {
        final = div;

    } else if ((num < 0 && denom > 0) || (num > 0 && denom < 0)) {
        final = div - 1;
        
    } else {
        final = div + 1;
    }
    
    printf("%d\n", final);
    return 0;
}
