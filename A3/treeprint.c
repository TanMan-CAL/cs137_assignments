#include <stdio.h>

void tree(int n){
    topPrintTop(n);
    topPrintMiddle(2*n + 1, n-1, 1);
    topPrintBottom(n);
    basePrint(n,n);
}

void topPrintTop(int n){
    dot(1);
    space((2*n + 1 - 3)/2);
    star(1);
    space((2*n + 1 - 3)/2);
    dot(1);
    printf("\n");
}
void topPrintBottom(int n){
    star(1);
    cross(2*n -1);
    star(1);
    printf("\n");
}
void topPrintMiddle(int width, int height, int middleSpaces){
    if (height != 0 ){
    int base = height; // special case for first/last row
    dot(1);
    space((width-middleSpaces-4)/2);
    cross(1);
    space(middleSpaces);
    cross(1);
    space((width-middleSpaces-4)/2);
    dot(1);

    printf("\n");
    middleSpaces = middleSpaces +2;
    topPrintMiddle(width, height - 1, middleSpaces);
    }
}
void basePrint(int n, int length){
    if (length != 0 ){
        int base = (2*n) -1; // with considertion of dots
        int trunk = n;
        if (n%2==1){ trunk = (n+1)/2; }
        else { trunk = n/2; }
        int width = trunk;
        if (width%2==0){ width++; }
        
        dot(1);
        space((base-width)/2);

        line(1);
        if (width != 1){
            space(width-2);
            line(1);
        }

        space((base-width)/2);
        dot(1);
        printf("\n");
        basePrint(n, length-1);
    }
}

void star(int length){
    if (length != 0 ){
        star(length-1);
        printf("*");
    }
}
void cross(int length){
    if (length != 0 ){
        cross(length-1);
        printf("+");
    }
}
void dot(int length){
    if (length != 0 ){
        dot(length-1);
        printf(".");
    }
}
void space(int length){
    if (length != 0 ){
        space(length-1);
        printf(" ");
    }
}
void line(int length){
    if (length != 0 ){
        line(length-1);
        printf("|");
    }
}