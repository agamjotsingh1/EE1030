#include <complex.h>
#include <stdio.h>
#include <stddef.h>
#include "matrix.h"
#include "hess.h"

double complex cnum(double real, double imag){
    return (double complex) (real + imag*I);
}

int main(){
    int m = 4;
    compl** mat = mzeroes(m, m);

    mat[0][0] = cnum(1, -1), mat[0][1] = cnum(2, 3), mat[0][2] = cnum(-1, 4), mat[0][3] = cnum(5, -2);
    mat[1][0] = cnum(3, 2), mat[1][1] = cnum(4, -1), mat[1][2] = cnum(2, 1), mat[1][3] = cnum(-3, 3);
    mat[2][0] = cnum(-2, 1), mat[2][1] = cnum(1, -3), mat[2][2] = cnum(3, 0), mat[2][3] = cnum(4, 2);
    mat[3][0] = cnum(5, 0), mat[3][1] = cnum(-1, -2), mat[3][2] = cnum(4, -1), mat[3][3] = cnum(3, 1);
    /*mat[0][0] = cnum(1, 0), mat[0][1] = cnum(2, 3), mat[0][2] = cnum(-1, 4);
    mat[1][0] = cnum(3, 2), mat[1][1] = cnum(4, -1), mat[1][2] = cnum(2, 1);
    mat[2][0] = cnum(-2, 1), mat[2][1] = cnum(1, -3), mat[2][2] = cnum(3, 0);*/


    mat = hess(mat, m);
    mprint(mat, m, m);
    //mprint(mmul(mat, mat, m, m, m), m, m);
    /*
    int n = 15;
    for(int i = 0; i < n; i++){
        compl*** temp = QR(mat, m, m);
        compl** Q = temp[0];
        compl** R = temp[1];
        
        mat = mmul(R, Q, m, m, m);
    }*/
   

    //mprint(mat, m, m);
}