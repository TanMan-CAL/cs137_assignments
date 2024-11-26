// #include ...
#include <stdio.h>
#include <assert.h>


void printfunction(int first, int last){
	printf("Examining indices %d and %d\n", first, last);
}

int ternarylastsearch(int L[], int len, int target){
	int low = 0;
	int high = len-1;
	int mid1 = low + (high-low)/3;
	int mid2 = high - (high-low)/3;
	int last_found = -1;

	while (low <= high) {
		mid1 = low + (high-low)/3;
		mid2 = high - (high-low)/3;
		// printf("%d %d ", low, high);

		printfunction(mid1, mid2);

		if (target == L[mid2]){
			low = mid2 + 1;
			last_found = mid2;
		}
		else if (target == L[mid1]){
			low = mid1 + 1;
			high = mid2 - 1;
			last_found = mid1;

		}
		else if (target > L[mid2]){
			low = mid2 + 1;
		}
		else if (target > L[mid1]){
			low = mid1 + 1;
			high = mid2 - 1;
		}
		else if (target < L[mid1]){
			high = mid1 - 1;			
		}

	}

	return last_found;
}


// int main(void) {
//     int a[10] = {1, 2, 3, 4, 5, 6, 6, 6, 9, 100};
//     assert(7 == ternarylastsearch(a,10,6));
//     printf("\n");
//     int a2[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
//     assert(-1 == ternarylastsearch(a2,10,100));
//     printf("\n");
//     assert(-1 == ternarylastsearch(a2,10,11));
//     printf("\n");
//     assert(0 == ternarylastsearch(a2,10,2));
//     printf("\n");
//     int a3[12] = {6,6,6,6,6,6,6,6,6,6,6,6};
//     assert(11 == ternarylastsearch(a3,12,6));

//     return 0;
// }



