#include <stdio.h>

int bottom_up(int n) {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;
    
    for (int i = 3; i <= n; i++)
        fib[i] = fib[i - 3] + fib[i - 2];
    
    return fib[n];
}

