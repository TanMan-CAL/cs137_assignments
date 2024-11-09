
#include "vlinteger.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// struct linteger {	linteger is a structure with two elements
//  int length;	        array is always full
// 	int *arr;	        pointer to integers (digits)
// };

struct linteger *vlintegerCreate(void)
{
	struct linteger *t1 = malloc(sizeof(struct linteger));
	t1->arr = NULL; // (*t1).arr
	t1->length = 0;	// no values in t1.
	return t1;
}

void vlintegerPrint(struct linteger *t1)
{
	printf("length=%d\n", t1->length);
	
	for (int i = 0; i < t1->length; ++i)
	{
		printf("%d", t1->arr[i]);
	} 
	printf("\n");
}

void vlintegerDestroy(struct linteger *t1)
{
	if (t1)
	{
		free(t1->arr);	// free the inside array first
		free(t1);	// then free the structure
	}
}

void vlintegerRead(struct linteger *t1)
{	int numReallocate = 10; int a; int i = 0;
	t1->arr = malloc(numReallocate*sizeof(int));


	while(scanf("%d ", &a)){
		if ((t1->length) % 10 == 0){
			numReallocate+=10;
			t1->arr = realloc(t1->arr, numReallocate*sizeof(int));
		}
		t1->arr[t1->length] = a; 
		t1->length++;
	}
}

struct linteger *vlintegerAdd(struct linteger *t1, struct linteger *t2)
{	
	struct linteger *new = vlintegerCreate(); int iteration; int carryover = 0;
	new->length = (t1->length >= t2->length)? t1->length : t2->length;
	int less = (t1->length >= t2->length)? t2->length : t1->length;
	int differnce = (t1->length >= t2->length)? (t1->length - t2->length) : (t2->length - t1->length);
	new->arr = malloc(new->length*sizeof(int));

	// INPUT of 0 before digits
	// int hasZero = 0;

	// for (int i = 0; i < less; i++){
	// 	if ((t1->arr[i] != 0) || (t2->arr[i] != 0)){
	// 		int hasZero = i;
	// 		break;
	// 	}
	// }

	for (int i = new->length-1; i >= 0; i--){
		int temp1 = 0;
		int temp2 = 0;

		if (t1->length >= t2->length){
			if (i < differnce){
				temp1 = t1->arr[i]; 
			}
			else {temp1 = t1->arr[i];
			temp2 = t2->arr[i-differnce];}
		}
		else if (t1->length < t2->length){
			if (i < differnce){
				temp2 = t2->arr[i];
			}
			else {temp1 = t1->arr[i-differnce];
			temp2 = t2->arr[i];}
		}

		int sum = temp1 + temp2 +carryover; 
		carryover = (sum/10);
		new->arr[i]=sum % 10;
	}
	return new;
}


// int main(void) {
//     struct linteger *int1 = vlintegerCreate();
//     printf("Enter the digits separated by a space: \n");
//     vlintegerRead(int1);
//     vlintegerPrint(int1);
//     assert(int1->arr[0] != 0);
//     char c;

//     scanf("%c", &c);
//     struct linteger *int2 = vlintegerCreate();
//     printf("Enter the digits separated by a space: \n");
//     vlintegerRead(int2);
//     vlintegerPrint(int2);
//     assert(int2->arr[0] != 0);
//     scanf("%c", &c);

// 	// ADDING CODE BELOW
//     struct linteger *add = vlintegerAdd(int1, int2);
//     printf("addition\n");
//     vlintegerPrint(add);
//     assert(add->arr[0] != 0);

//     vlintegerDestroy(int1);
//     vlintegerDestroy(int2);
//     vlintegerDestroy(add);

//     return 0;
// }