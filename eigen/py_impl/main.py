from matrix import *
from funcs import *

A = Matrix([[2+3j, 1-1j, 5 + 2j], [-4 + 1j, 3 + 0j, 3 - 5j], [3 - 10j, 4 + 9j, -1 + 8j]])
n = 20
tol = 10e-3

for i in range(n):
    s = A[A.size[0] - 1, A.size[0] - 1]
    #Q, R = QR(A - s*eye(A.size[0]))
    #A = R@Q + s*eye(A.size[0])
    Q, R = QR(A)
    A = R@Q

for i in range(A.size[0] - 1):
    if abs(A[i + 1, i]) > tol:
        complex_block = Matrix([[A[i, i], A[i, i+1]], [A[i+1, i], A[i + 1, i + 1]]])

        A[i, i], A[i + 1, i + 1] = two_block_complex(complex_block)

print(A)
