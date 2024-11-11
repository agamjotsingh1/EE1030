#include <complex.h>
#include <stdio.h>
#include <stddef.h>

// for square matrix only
compl** hess(compl** A, int m){
    compl** U = meye(m);
    compl** Atemp = mdup(A, m, m);

    for(int i = 0; i < m - 1; i++){
        compl** Pi = mzeroes(m, m);
        for(int j = 0; j < i + 1; j++) Pi[j][j] = 1;

        int msub = m - i - 1;

        compl** x = mzeroes(msub, 1);
        for(int k = i + 1; k < m; k++){
            x[k - i - 1][0] = A[k][i];
        }

        compl rho;
        if(x[0][0] == 0) rho = 0;
        else rho = -(x[0][0])/((compl) cabs(x[0][0]));

        compl** subu = madd(x, mscale(e(msub, 1), msub, 1, -rho*vnorm(x, msub)), msub, 1);
        compl** u = mscale(subu, msub, 1, 1/vnorm(subu, msub));
        compl** Psub = madd(meye(msub), mscale(mmul(u, mT(u, msub, 1), msub, 1, msub), msub, msub, -2), msub, msub);

        for(int j = i + 1; j < m; j++){
            for(int k = i + 1; k < m; k++){
                Pi[j][k] = Psub[j - i - 1][k - i - 1];
            }
        }

        A = mmul(A, Pi, m, m, m);
        A = mmul(Pi, A, m, m, m);
    }

    return A;
}