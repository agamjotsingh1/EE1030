#include<stdio.h>

int main(){
    FILE *ptr;  // declaring a file pointer
    ptr = fopen("plot.txt", "w"); // creating a new file to write into

    fprintf(ptr, "1 2\n");
    fprintf(ptr, "7 0\n");
    return 0;
}