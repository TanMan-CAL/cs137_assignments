#include <stdio.h>

void numberPairs(int num){ numPrinter(num, -1); }

void numPrinter(int num, int previous) {
    if (num != 0) {
        int digit = num % 10;
        num = num / 10;
        numPrinter(num, digit);
        if (digit != previous) {
            printf("%d%d", digit, digit);
        }   
    }
}
