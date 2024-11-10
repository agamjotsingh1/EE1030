#include <complex.h>
#include <stdio.h>
#include <stddef.h>
#include "matrix.h"

double complex cnum(double real, double imag){
    return (double complex) (real + imag*I);
}

int main(){
    int m = 3;
    compl** mat = mzeroes(m, m);

    mat[0][0] = cnum(1, 0), mat[0][1] = cnum(2, 0), mat[0][2] = cnum(3, 0);
    mat[1][0] = cnum(0, 0), mat[1][1] = cnum(2, 0), mat[1][2] = cnum(1, 0);
    mat[2][0] = cnum(1, 0), mat[2][1] = cnum(0, 0), mat[2][2] = cnum(1, 0);

    int n = 15;
    for(int i = 0; i < n; i++){
        compl*** temp = QR(mat, m, m);
        compl** Q = temp[0];
        compl** R = temp[1];
        
        mat = mmul(R, Q, m, m, m);
    }

    mprint(mat, m, m);
}