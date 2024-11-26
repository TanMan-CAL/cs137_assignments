// #include ...
#include <stdio.h>

//Do not change it.
void printarr(int a[], int len){
    for (int i=0; i<len-1; i++)
       printf("%d ", a[i]);
    printf("%d\n", a[len-1]);
}

void doubleselectionsort(int a[], int len){
    
    for (int swap = 0; swap < (len/2); swap++) {
        int max = swap;
        int min = swap;

        for (int i = swap+1; i < (len-swap); i++){
            if (a[i] < a[min]) {min=i;}
            if (a[i] > a[max]) {max=i;}
        }

        int tempLow = a[min];

        if (a[max] == a[swap]) {
            max = min;
        }
        a[min] = a[swap];
        a[swap] = tempLow;

        int tempHigh = a[max];
        a[max] = a[len-1-swap];
        a[len-1-swap] = tempHigh;

        printarr(a,len);
    }
}

// int main(void) {
   
//     int a[7] = {4, 4, 4, 0, 0, -10, -10};
//     doubleselectionsort(a,7);

//     int a2[5] = {6, 11, 2, -4, -1};
//     doubleselectionsort(a2,5);

//     int a3[10] = {1, 8, 5, 4, 6, 2, 5, 6, 2, 9};
//     doubleselectionsort(a3,10);

//     int a4[8] = {1, 4, 3, 6, 5, 7, 2, 8};
//     doubleselectionsort(a4,8);

//     // 1 8 5 4 6 2 5 6 2 9
//     // 1 2 5 4 6 2 5 6 8 9
//     // 1 2 2 4 6 5 5 6 8 9
//     // 1 2 2 4 5 5 6 6 8 9
//     // 1 2 2 4 5 5 6 6 8 9

//     return 0;
// }
