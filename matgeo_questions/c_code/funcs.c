#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"

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

float **lineGet(int n, float x1, float x2, float a, float b, float c) {
    float **pts = (float **) malloc(sizeof(float *) * n); 

    for(int i = 0; i < n; i++){
        pts[i] = (float *) malloc(sizeof(float) * 2 * n);
        pts[i][0] = x1 + ((x2 - x1)*i)/n; 
        pts[i][1] = -(c + a*pts[i][0])/b; 
    }

    return pts;
}

float **normPlot(int n, int p, float x, float y, float r) {
    float **relpts = (float **) malloc(sizeof(float *) * n); 
    float dx = r/n;

    for(int i = 0; i < n; i++){
        relpts[i] = (float *) malloc(sizeof(float) * 2);

        relpts[i][0] = i*dx; 
        relpts[i][1] = pow(pow(r, p) - pow(i*dx, p), (double) 1/p); 
    }

    return relpts;
}

void free_multi_memory(float **arr, int n){
    for (int i = 0; i < n; i++){
        free(arr[i]);
    }

    free(arr);
}



