#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

char* merge(char* s1, char* s2) {
    size_t s1Length = strlen(s1); 
    size_t s2Length = strlen(s2); 
    char *masterString = calloc((s1Length+s2Length+3), sizeof(char));
    // need to init first value to null so knows where to start adding from
    int i = 0; int c = 0;
    int j = -1; int d = -1;

    while (i < s1Length || c < s2Length){

        if (i < s1Length){
            for(;*(s1+i) && *(s1 +i) != ' '; i++);

            if (*(s1 + i) == ' '){
                strncat(masterString, s1+ j+1, i-j-1);
                strcat(masterString, " ");
                j = i;
            }
            else if (s1Length == i){
                strncat(masterString, s1+ j+1, i-j);
                strcat(masterString, " ");
            }
            i++;
        }    

        if(c < s2Length){
            for(;*(s2+c) && *(s2+c) != ' '; c++);

            if (*(s2+c) == ' '){
                strncat(masterString, s2+ d+1, c-d-1);
                strcat(masterString, " ");  
                d = c;
            }
            else if (s2Length == c){
                strncat(masterString, s2+ d+1, c-d);
                strcat(masterString, " ");
            }
            c++;
        }

    }
    size_t length = strlen(masterString);
    masterString[length-1] = '\0';
    return masterString;
}

// int main(void){
        
//     char s1[] = "The brown jumps the dog";
//     char s2[] = "quick fox over lazy";
//     char *s = merge(s1, s2);
//     assert(!strcmp(s, "The quick brown fox jumps over the lazy dog"));
//     free(s);
    
//     char s3[] = "the brown";
//     char s4[] = "quick fox is sleeping today";  
//     s = merge(s3,s4);
//     assert(!strcmp(s, "the quick brown fox is sleeping today"));
//     free(s);
    
//     char* s5 = "happy to you";
//     char* s6 = "birthday";  
//     s = merge(s5,s6);
//     assert(!strcmp(s, "happy birthday to you"));
//     free(s);

//     return 0;
// }