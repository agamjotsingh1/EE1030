from cmath import sqrt

def zeroes(size):
    mat = [[0 for _ in range(size[1])] for _ in range(size[0])]
    return Matrix(mat)

def eye(size):
    mat = zeroes((size, size))
    for i in range(size):
        mat[i, i] = 1
    return mat

class Matrix:
    def __init__(self, mat):
        self.mat = mat
        self.size = (len(mat), len(mat[0]))
        self.ptr = (0, 0)

    def __setitem__(self, index, value):
        i, j = index
        if isinstance(i, slice):
            for n in range(self.size[0]):
                self.mat[n][j] = value[n]
        else:
            self.mat[i][j] = value

    def __getitem__(self, index):
        i, j = index
        if isinstance(i, slice):
            mat = zeroes((self.size[0], 1)).mat
            for n in range(self.size[0]):
                mat[n][0] = self.mat[n][j]
            return Matrix(mat)
        elif isinstance(j, slice):
            return Matrix([self.mat[i][j]])
        return self.mat[i][j] 

    def __repr__(self):
        s = ""
        if self.size == (1, 1):
            s = str(self[0, 0])
        else:
            for col in self.mat:
                s += str(col) + "\n"
            s = "[" + s.strip() + "]"
        
        return s

    def __matmul__(self, B):
        A = self
        mat = Matrix([[sum(A[i, k]*B[k, j] for k in range(B.size[0])) for j in range(B.size[1]) ] for i in range(A.size[0])])
        if mat.size == (1, 1):
            return mat[0, 0]
        return mat

    def __add__(self, B):
        A = self
        return Matrix([[A[i, j] + B[i, j] for j in range(self.size[1])] for i in range(self.size[0])])

    def __sub__(self, B):
        A = self
        return Matrix([[A[i, j] - B[i, j] for j in range(self.size[1])] for i in range(self.size[0])])

    def __mul__(self, k):
        A = self
        return Matrix([[k * A[i, j] for j in range(self.size[1])] for i in range(self.size[0])])

    def __rmul__(self, k):
        A = self
        return Matrix([[k * A[i, j] for j in range(self.size[1])] for i in range(self.size[0])])

    def __truediv__(self, k):
        A = self
        return Matrix([[A[i, j]/k for j in range(self.size[1])] for i in range(self.size[0])])

    # Transpose of the matrix
    @property
    def T(self):
        mat = zeroes(tuple(reversed(self.size)))

        for i in range(self.size[0]):
            for j in range(self.size[1]):
                mat[j, i] = self[i, j].conjugate()

        return mat
        
    def norm(self):
        inprod = self.T@self
        return sqrt(inprod)