#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct FlexData {
	bool isInt;
	int value_int;
	double value_double;
}FlexData;

FlexData flexDivide(FlexData a, FlexData b){
    FlexData divi;

    if ((a.isInt) && (b.isInt)){
        divi.isInt = true;
        divi.value_int = a.value_int/b.value_int;
    }
    else if ((a.isInt == 0) && (b.isInt == 0)){
        divi.isInt = false;
        divi.value_double = a.value_double/b.value_double;
    }
    else if (b.isInt == 0){ // b not int
        divi.isInt = false;
        divi.value_double = a.value_int/b.value_double;
    }
    else{ // a not
        divi.isInt = false;
        divi.value_double = a.value_double/b.value_int;
    }
    return divi;
}

// int main(void){
//     FlexData n1 = {true, 17, 0};
//     FlexData n2 = {true, 5, 0};
//     FlexData d1 = {false, 0, 14.3};
//     FlexData d2 = {false, 0, 2.4};

//     FlexData r1 = flexDivide(n1,n2);
//     FlexData r2 = flexDivide (d1,d2);
//     FlexData r3 = flexDivide (n1,d2);
//     assert(r1.isInt);
//     assert(!r2.isInt);
//     assert(!r3.isInt);
//     assert(3==r1.value_int);    
//     printf("%lf\n", r2.value_double);
//     printf("%lf\n", r3.value_double);

//     return 0;
// }

// /*
// output:
// 5.958333
// 7.083333
// */