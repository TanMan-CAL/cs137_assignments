#include <stdio.h>
#include <assert.h>

typedef struct Point{
	int x;
	int y;
} point;

typedef struct Rectangle {
   point bottomLeft;
   int width;
   int height;
} rectangle;

int min(int a1, int a2){
	if (a1<a2){
		return a1;
	}
	return a2;
}

int max(int a1, int a2){
	if (a1>a2){
		return a1;
	}
	return a2;
}


rectangle intersection(rectangle rects[], int n){
	point point1, point2, point3, point4; rectangle final; final = rects[0];

	point1.x= final.bottomLeft.x; // bottom left1
	point1.y= final.bottomLeft.y; 

	point2.x = final.bottomLeft.x + final.width; // top right1
	point2.y = final.bottomLeft.y + final.height;
	//printf("INIT: p1x %d p1y %d p2x %d p2y %d\n", point1.x, point1.y, point2.x, point2.y);

	for (int i=1; i<n; i++){
		point3.x = rects[i].bottomLeft.x; // bottom left2
		point3.y = rects[i].bottomLeft.y;

		point4.x = rects[i].bottomLeft.x + rects[i].width; // top right2
		point4.y = rects[i].bottomLeft.y + rects[i].height;
		//printf("NEW RECT: p1x %d p1y %d p2x %d p2y %d\n", point3.x, point3.y, point4.x, point4.y);

		point1.x = max(point1.x, point3.x);
		point1.y = max(point1.y, point3.y);

		point2.x = min(point2.x, point4.x);
		point2.y = min(point2.y, point4.y);
		//printf("OVERLAP: p1x %d p1y %d p2x %d p2y %d\n", point1.x, point1.y, point2.x, point2.y);

		if (point1.x >= point2.x || point1.y >= point2.y){
			final.bottomLeft.x = 0;
			final.bottomLeft.y = 0;
			final.width = 0;
			final.height = 0;
			return final;
		}

	}

	final.bottomLeft.x = point1.x;
	final.bottomLeft.y = point1.y;
	final.width = point2.x-point1.x;
	final.height = point2.y-point1.y;
	//printf("FINAL: p1x %d p1y %d p2x %d p2y %d w %d h %d\n\n\n", point1.x, point1.y, point2.x, point2.y, final.width, final.height);


	return final; }



// int main(){
	
// 	rectangle result;

// 	rectangle r = {{2,6},3,4};
// 	rectangle s = {{0,7},7,1};
// 	rectangle t = {{3,5},1,6};
// 	rectangle u = {{5,6},3,4};
	
// 	// Test 1
// 	rectangle rects1[2] = {r, s};
// 	result = intersection(rects1, 2);
	
// 	assert(result.bottomLeft.x == 2);
// 	assert(result.bottomLeft.y == 7);
// 	assert(result.width == 3);
// 	assert(result.height == 1);
	

// 	// Test 2
// 	rectangle rects2[3] = {r, s, t};
// 	result = intersection(rects2, 3);
// 	assert(result.bottomLeft.x == 3);
// 	assert(result.bottomLeft.y == 7);
// 	assert(result.width == 1);
// 	assert(result.height == 1);
	
	
// 	// Test 3
// 	rectangle rects3[4] = {r, s, t, u};
// 	result = intersection(rects3, 4);
// 	assert(result.bottomLeft.x == 0);
// 	assert(result.bottomLeft.y == 0);
// 	assert(result.width == 0);
// 	assert(result.height == 0);


// 	return 0;
// }
