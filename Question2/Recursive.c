#include <stdio.h>

int recurrence(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return recurrence(n - 3) + recurrence(n - 2);
}

