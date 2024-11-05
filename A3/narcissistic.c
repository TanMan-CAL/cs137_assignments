#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

bool narcissist(int n){
    int p = power(n);
    int sum = sums(n, p);
    if (n == sum){
        return true;
    }
    return false;
}

int power(int n){
    if (n != 0){
        n = n / 10;
        return (1 + power(n));
}
    return 0;
}

int multiply(int digit, int p){
    if (p != 0){
        return digit * multiply(digit, p-1);
    }
    return 1;
}

int sums (int n, int p){
    if (n != 0){
        int digit = (n % 10);
        int powered = multiply(digit, p);
        n = n / 10;
        return (powered + sums(n, p));
    }
    return n;
}


// int main(){


//     // int n = 135;
//     // int p = power(n);
//     // int sum = sums(n, p);


//     // printf("%d", sum);
// }

// int main(void) {
//      assert(narcissist(1));
//  assert(narcissist(9));
//  assert(narcissist(153));
//  assert(narcissist(370));
//  assert(narcissist(92727));
//  assert(narcissist(548834));
//  assert(!narcissist(10));
//  assert(!narcissist(92));
//  assert(!narcissist(1535));
//  assert(!narcissist(1234));
//  assert(!narcissist(92726));
// assert(!narcissist(93083));

// return 0;}

