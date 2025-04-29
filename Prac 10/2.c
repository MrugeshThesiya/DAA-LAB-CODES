#include <stdio.h>

int calcPeak(int *A, int n)
{
    int s = 0;
    int e = n - 1;
    int m;

    while (s <= e)
    {
        m = (e - s) / 2 + s;
        if (A[m] > A[m + 1])
        {
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }

    return m;
}

int main()
{
    int A[] = {1, 2, 3,5,3,2};
    int size = sizeof(A) / sizeof(A[0]);

    int pi = calcPeak(A, size);

    printf("The peak is at %d which is %d.", pi, A[pi]);

    return 0;
}
