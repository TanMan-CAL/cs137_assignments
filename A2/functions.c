#include <stdio.h>

void square (int w) {
    for (int i=1;i<=(w*w); i++){
        printf("%d ", i);
        if ((i%w ==0)){
            printf("\n");
        }   
    }
}

void spiral(int w){
    int i = 1;
    int turnType = 1;
    printf("%d ", (i));

    for (int j = (w-1); j > 0; j--){
        int prior = j;
        int z = 0;
        
        if (prior == (w-1)){
            z = -1;
        }
        for (; z<2; z++){
            for(;j>0;j--) {
            if (turnType == 4){ i = i-w; printf("%d ", i); }
            if (turnType == 3){ i--; printf("%d ", i); }
            if (turnType == 2){ i=i+w; printf("%d ", i); }
            if (turnType == 1){ i++; printf("%d ", i); }
            }

            turnType++;
            if (turnType > 4){
                turnType = 1;
            }

            j = prior;
        }
    }
    printf("\n");
}


void rotation(int w){
    for (int layer = 0; layer < ((w/2)); layer++){
        int a = 1 + layer*(w+1); 
        int b = w + (layer*(w-1));
        int c = w*w - (layer*(w+1));
        int d = w*w - (w-1) - (layer*(w-1));

        printf("%d %d %d %d ", a,b,c,d);
        int iteration = w-(2*layer) - 1;

        for (int i = 1; i<iteration; i++){
            a = a + 1;
            b = b + w;
            c = c - 1;
            d = d - w;
            printf("%d %d %d %d ", a,b,c,d);
        }
    }
    
    if (w % 2 == 1){
        printf("%d ", ((w*w / 2) + 1));
    }
    
    printf("\n");
}