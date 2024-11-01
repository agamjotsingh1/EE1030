from matrix import Matrix, zeroes
from cmath import sqrt

def QR(A: Matrix):
    Q = zeroes(A.size)
    R = zeroes((A.size[1],)*2)

    for i in range(A.size[1]):
        a = A[:, i]
        q = a
        for j in range(0, i):
            q = q - (a.T@Q[:, j])*Q[:, j]
            R[j, i] = a.T@Q[:, j]

        R[i, i] = q.norm()
        q = q/q.norm()
        Q[:, i] = q.T.mat[0]

    return (Q, R)

def two_block_complex(A: Matrix):
    a, b, c, d = A[0, 0], A[0, 1], A[1, 0], A[1, 1]
    D = (a + d)**2 - 4*(a*d - b*c)
    return ( ((a+d) + sqrt(D))/2, ((a+d) - sqrt(D))/2)
