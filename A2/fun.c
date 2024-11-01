#include <stdio.h>

int isSophieGermainPrime(int p){
    int primeOrNot = 1;

    for (int i = 2; i<(p/2); i++){
        if (p % i == 0){
            primeOrNot = 0;
            break;
        }
    }
    for (int j = 2; j<(((2*p)+1)/2); j++){
        if (((2*p)+1) % j == 0){
            primeOrNot = 0;
            break;
        }
    }
    return primeOrNot;
}

int base2nat (int bs, int num){
    int sum = 0;
    int factor = 1;
    while (num != 0){
        int remainder = num % 10;
        sum = sum + (remainder*factor);
        num = num / 10;
        factor = factor*bs;
    }
    // printf("%d\n", sum);
    return sum;
}


int nat2base(int bs, int num) {
    int sum = 0;
    int i=1;
    while (num != 0){
        int remainder = num % bs;
        sum = sum + (remainder*i);
        num = num / bs;
        i=i*10;
    }
    // printf("%d\n", sum);
    return sum;
}