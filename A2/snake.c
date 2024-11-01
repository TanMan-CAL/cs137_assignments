#include <stdio.h>

int main(void){
    int length; 
    scanf("%d", &length);
    int spacesPre = 1;
    int body = 3;
    int spacesAfter = length - body - 1;
    int jump = 0;
    
    while (spacesAfter != -1){
        
        for(int a = 0; a<spacesPre; a++){
            printf("_");
        }
        
        for(int b = 0; b<body; b++){
            if (b==(body-1)){
                printf("H");
            } else {
                printf("X");
            }
        }

        int count = 1;
        if (length%2==0){
            count = 0;
        }

        int spacing = length -  (body + spacesPre) + count;
        for(int c = 0; c<spacesAfter; c++){
            if ((spacing % 2) == 0){
                printf("_");
            } else {
                printf(".");
            }
            spacing--;
        }

        if ((jump % 2) ==0){
            spacesPre++;
            spacesAfter--;
            jump++;
        } else {
            spacesAfter--;
            body++;
            jump++;
        }

        printf("\n");

    }
}