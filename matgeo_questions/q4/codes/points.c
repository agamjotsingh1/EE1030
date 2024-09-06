#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

float **pointsGet(){
    float **pts = (float **) malloc(sizeof(float *) * 3); 

    for (int i = 0; i < 3; i++) {
        pts[i] = (float *) malloc(sizeof(float) * 3 * 2);
    }

    // A
    pts[0][0] = 7;
    pts[0][1] = -4;
    /// B1
    pts[1][0] = 9;
    pts[1][1] = 0;
    // B2
    pts[2][0] = 5;
    pts[2][1] = 0;

    return pts; 
}


float **circleGet(int n, float x, float y, float r) {
    float **pts = (float **) malloc(sizeof(float *) * n); 
    float theta = 0;

    for(int i = 0; i < n; i++){
        pts[i] = (float *) malloc(sizeof(float) * 2 * n);
        pts[i][0] = x + r*cos(theta);
        pts[i][1] = y + r*sin(theta);
        theta += 2*PI/n;
    }

    return pts;
}

void free_multi_memory(float **arr, int n){
    for (int i = 0; i < n; i++){
        free(arr[i]);
    }

    free(arr);
}