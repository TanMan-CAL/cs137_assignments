#include <math.h>
#include <stdio.h>
#define PI acos(-1)

double trapezoidal(double (*f)(double), double a, double b, double epsilon, int n){
    double area1 = 100000.0;
    double area2 = 0.0;

    while (((area1-area2) >= epsilon) || ((area2-area1) >= epsilon)) {
        area1 = area2;
        area2 = 0.0;
        double difference = (b - a)/n;
        double first = a;

        for (int i = 0; i < n; i++){
            double second = first + difference;
            double trapezoid = ((f(second) + f(first))/2) * difference;
            area2 = area2 + trapezoid;
            // printf("%f %f %f %d\n", first, second, difference, n);
            
            first = first + difference;
        }
        n = 2*n;
    }
    return area2;
}

// int main(){
//     printf("%f\n",(trapezoidal(f1, 5, 10, 0.00001, 2) - 291.667));
// }