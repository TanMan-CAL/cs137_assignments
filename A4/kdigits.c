#include <stdio.h>
#include <assert.h>

int removekdigits(long long int n, int k){
    int digits[10] = {0};
    int factor = 1;
    int sum = 0;
    int increment = 0;
    
    while (n != 0){
        digits[n % 10]++;
        n = n / 10;
    }
    


    for(int i = 9; i >= 0 && k > 0; i--){
        while(digits[i] > 0 && k > 0){
            digits[i]--;
            k--;
        }
    }

    for(int i = 0; i <= 9; i++){
        while(digits[i] > 0){
            sum = sum * 10 + i;
            digits[i]--;
        }
    }

    while (factor != 0){
            if (digits[increment] > 0){
                sum = sum + (increment*factor);
                //printf("%d %d \n", sum, increment);
                factor = factor / 10;
                digits[increment]--;
            }
            else {
                increment++;
            }
    }
    return sum;
}

// int main(){
//     printf("%d",removekdigits(12000, 2));
//     removekdigits(0,0);
//     assert(removekdigits(345267,3)==234);
//     assert(removekdigits(0,0)==0);
//  assert(removekdigits(9,1)==0);
//   assert(removekdigits(871,0)==178);
//  assert(removekdigits(9898989,2)==88899);
// }