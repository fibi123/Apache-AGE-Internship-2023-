#include <stdio.h>

#define MAX_SIZE 100

int memo[MAX_SIZE];

int recurrence(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (memo[n] != -1)
        return memo[n];
    else {
        memo[n] = recurrence(n - 3) + recurrence(n - 2);
        return memo[n];
    }
}

