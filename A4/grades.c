#include <stdio.h>
#include <math.h>

int main(){
    int num = 0;
    int lowest = 100;
    int highest = 0;
    int failed = 0;
    double sum = 0.0;
    double square_sum = 0.0;
    double students = 0;
    int grades[x`x] = {0};
    
    while(scanf("%d \n", &num)==1){
        grades[num]++;
        sum += num;
        square_sum += (num*num);
        if (num>highest){
            highest = num;
        }
        if (num<lowest){
            lowest = num;
        }
        if (num < 50){
            failed++;
        }
        students++;
    }
    //printf("%d, %d", grades[0], grades[1]);
    double average = sum/students;
    
    double mean_of_squares = square_sum / students;
    double v = (mean_of_squares - average * average) * students / (students - 1);
    double standard_dev = pow(v, 0.5);
    


    printf("The maximal grade is: %d\n", highest);
    printf("The number of students who received the maximal grade is %d\n", grades[highest]);
    printf("The minimal grade is: %d\n", lowest);
    printf("The number of students who received the minimal grade is %d\n", grades[lowest]);
    printf("The course mean is: %.3f\n", (sum/students));
        printf("The standard deviation is: %.3f\n", standard_dev);
    printf("The number of students who failed the course is: %d\n", failed);
    return 0;
}