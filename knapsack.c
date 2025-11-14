#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapRec(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n-1] > W) 
        return knapRec(W, wt, val, n-1);
    else
        return max(val[n-1] + knapRec(W - wt[n-1], wt, val, n-1),
                   knapRec(W, wt, val, n-1));
}

int main() {
    int val[] = {60, 100, 120, 50};
    int wt[]  = {10, 20, 30, 40};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("Maximum value = %d\n", knapRec(W, wt, val, n));
    return 0;
}
