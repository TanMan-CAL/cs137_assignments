#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse the entire string
void reverseString(char *str) {
    size_t length = strlen(str); 
    char *newString = malloc(length*sizeof(char));
    int index = 0;

    for(int i = length-1; i >= 0; i--){
        *(newString+index) = str[i];
        // printf("%d %c %d %c \n", index, *(newString+index), i, str[i]);
        index++;
    }

    for(int i = 0; i < length; i++){
        *(str+i) = *(newString+i);
    }
    free(newString);
}
 
// Function to replace each vowel with the next consonant
void replaceVowels(char *str) {
    size_t length = strlen(str);
    for(int i = 0; i < length; i++){
        int digit = (int) *(str+i);

        if ((digit == 65) || (digit == 69) || (digit == 73) || (digit == 79) || (digit == 85)){
            if (digit == 85){
                digit = 66;
            }
            else{
                digit++;
            }
        }

        *(str+i) = (char)digit;
    }
}
 
// Function to shift each consonant to the right by a number of positions
// equal to its ASCII value modulo 10
void shiftConsonants(char *str) {
    size_t length = strlen(str);
    for (int i = 0; i < length; i++){
        int digit  = (int) *(str+i);
        if (digit == 32){
            continue;
        }
        digit += (digit % 10);
        if (digit > 90){
            digit -= 26;
        }
        *(str+i) = (char)digit;
        // printf("%c", digit);
    }
}
 

 // DO NOT CHANGE MAIN
int main(void) {
    char inputString[101];
 
    // Read the input string
    printf("Enter a string (uppercase letters and spaces only): ");

   scanf("%100[^\n]s", inputString);
   
    // Reverse the entire string
    reverseString(inputString);
    printf("Reversed String: %s\n", inputString);
    
    // Replace vowels with the next consonant
    replaceVowels(inputString);
    printf("Replaced Vowels String: %s\n", inputString);
    
    // Shift consonants to the right
    shiftConsonants(inputString);
    // Print the final result
    printf("Ciphered String: %s\n", inputString);
 
    return 0;
}