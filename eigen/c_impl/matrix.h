#include <complex.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

typedef double complex compl;

void mprint(compl** mat, int m, int n){
    printf("[");
    for(int i = 0; i < m; i++){
        printf("[");
        for(int j = 0; j < n; j++){
            printf("%lf + %lfi", creal(mat[i][j]), cimag(mat[i][j]));
            if(j != n - 1) printf(", ");
        }
        printf("]");
        if(i != m - 1) printf("\n");
    }
    printf("]\n\n");
}

compl** mzeroes(int m, int n){
    compl** mat = (compl**) malloc(sizeof(compl)*m);
    for(int i = 0; i < m; i++){
        mat[i] = (compl*) malloc(sizeof(compl)*n);

        for(int j = 0; j < n; j++){
            mat[i][j] = 0 + 0*I;
        }
    }
    return mat;
}

compl** meye(int m){
    compl** mat = mzeroes(m, m);
    for(int i = 0; i < m; i++){
        mat[i][i] = 1 + 0*I;
    }
    return mat;
}

compl** mscale(compl** mat, int m, int n, compl k){
    compl** newmat = (compl**) malloc(sizeof(compl)*m);
    for(int i = 0; i < m; i++){
        newmat[i] = (compl*) malloc(sizeof(compl)*n);

        for(int j = 0; j < n; j++){
            newmat[i][j] = k*mat[i][j];
        }
    }
    return newmat;
}

compl** madd(compl** mat1, compl** mat2, int m, int n){
    compl** newmat = (compl**) malloc(sizeof(compl)*m);
    for(int i = 0; i < m; i++){
        newmat[i] = (compl*) malloc(sizeof(compl)*n);

        for(int j = 0; j < n; j++){
            newmat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return newmat;
}

compl** mT(compl** mat, int m, int n){
    compl** newmat = (compl**) malloc(sizeof(compl)*n);
    for(int i = 0; i < n; i++){
        newmat[i] = (compl*) malloc(sizeof(compl)*m);

        for(int j = 0; j < m; j++){
            newmat[i][j] = conj(mat[j][i]);
        }
    }
    return newmat;
}

compl** mmul(compl** mat1, compl** mat2, int m, int n, int r){
    compl** newmat = mzeroes(m , r);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < r; j++){
            for(int k = 0; k < n; k++) {
                newmat[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }

    return newmat;
}

compl** mgetcol(compl** mat, int m, int n, int k){
    compl** newmat = (compl**) malloc(sizeof(compl *)*m);

    for(int i = 0; i < m; i++){
        newmat[i] = (compl*) malloc(sizeof(compl));
        newmat[i][0] = mat[i][k]; 
    }

    return newmat;
}

compl** mdup(compl** mat, int m, int n){
    compl** newmat = (compl**) malloc(sizeof(compl)*m);
    for(int i = 0; i < m; i++){
        newmat[i] = (compl*) malloc(sizeof(compl)*n);

        for(int j = 0; j < n; j++){
            newmat[i][j] = mat[i][j];
        }
    }
    return newmat;
}

compl** vconj(compl** v, int m){
    compl** vconj = (compl**) malloc(sizeof(compl)*m);

    for(int i = 0; i < m; i++){
        vconj[i] = (compl*) malloc(sizeof(compl)*1);
        vconj[i][0] = conj(v[i][0]);
    }

    return vconj;
}

double vnorm(compl** vec, int m){
    compl** norm = mmul(mT(vec, m, 1), vec, 1, m, 1);

    return sqrt(creal(norm[0][0]));
} 

compl** e(int m, int i){
    compl** mat = mzeroes(m, 1);
    mat[i-1][0] = 1;
    return mat;
}

compl*** QR(compl** A, int m, int n){
    compl** Q = mzeroes(m, n);
    compl** R = mzeroes(n, n);
    for(int i = 0; i < n; i++){
        compl** a = mgetcol(A, m, n, i);
        compl** q = mdup(a, m, 1);

        for(int j = 0; j < i; j++){
            compl x = mmul(mT(a, m, 1), mgetcol(Q, m, n, j), 1, m, 1)[0][0];
            q = madd(q, mscale(mgetcol(Q, m, n, j), m, 1, -x), m, 1);
            R[j][i] = x;
        }

        R[i][i] = vnorm(q, m) + 0*I;
        q = mscale(q, m, 1, (compl) 1/vnorm(q, m));

        for(int j = 0; j < m; j++){
            Q[j][i] = q[j][0];
        }
    }

    compl*** ret = (compl***) malloc(sizeof(compl**)*2);
    ret[0] = Q;
    ret[1] = R;
    return ret;
}