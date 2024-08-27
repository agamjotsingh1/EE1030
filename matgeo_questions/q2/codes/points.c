struct points{
    int A[2];
    int B[2];
};

struct points get(){
    struct points temp;
    temp.A[0] = 1;
    temp.A[1] = 2;
    temp.B[0] = 7;
    temp.B[1] = 0;
    return temp;
}