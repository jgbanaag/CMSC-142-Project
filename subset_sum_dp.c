/*
    Date created: 2024-11-28
    Program description:
        A program that finds all subsets of an array of integers that sum to a particular target sum.
*/

#include <stdio.h>

#define MAX_SUM 1000

// a function that takes in an array of integers of length N and a target sum
int subset_sum(int a[], int N, int target) {
    int dp[2][MAX_SUM + 1];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j <= MAX_SUM; j++)
            dp[i & 1][j] = 0;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= MAX_SUM; j++)
            // either we don't take a[i] or we take a[i]
            dp[i & 1 ^ 1][j] = dp[i & 1][j] | (j >= a[i] ? dp[i & 1][j - a[i]] : 0);
    return dp[N & 1][target];
}
    
int main() {
    int N;
    printf("N: ");
    scanf("%d", &N);
    printf("Array: ");
    int a[N], i;
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    int target;
    printf("Target sum: ");
    scanf("%d", &target);
    printf("Subset sum exists: %d\n", subset_sum(a, N, target));
    return 0;
}
