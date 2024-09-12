#include <stdlib.h>

float **pointsGet(){
    float **pts = (float **) malloc(sizeof(float *) * 3); 

    for (int i = 0; i < 3; i++) {
        pts[i] = (float *) malloc(sizeof(float) * 3);
    }


    pts[0][0] = 2;
    pts[0][1] = -1;
    pts[0][2] = 2;

    pts[1][0] = (float) 2/3;
    pts[1][1] = (float) -1/3;
    pts[1][2] = (float) 2/3;

    pts[2][0] = 0; 
    pts[2][1] = 0; 
    pts[2][2] = 0; 

    return pts; 
}

float **lineFromPts(int n, float x1, float y1, float z1, float x2, float y2, float z2) {
    float **pts = (float **) malloc(sizeof(float *) * n); 

    for(int i = 0; i < n; i++){
        pts[i] = (float *) malloc(sizeof(float) * 3);
        pts[i][0] = x1 + ((x2 - x1)*i)/n; 
        pts[i][1] = y1 + ((y2 - y1)*i)/n; 
        pts[i][2] = z1 + ((z2 - z1)*i)/n; 
    }

    return pts;
}

void free_multi_memory(float **arr, int n){
    for (int i = 0; i < n; i++){
        free(arr[i]);
    }

    free(arr);
}