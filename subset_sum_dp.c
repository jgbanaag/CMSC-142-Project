/*
    Date created: 2024-11-28
    Program description:
        A program that finds all subsets of an array of integers that sum to a particular target sum.
*/

#include <stdio.h>

// a function that takes in an array of integers of length N and a target sum
int subset_sum(int a[], int N, int target) { 
    int max_sum = 0, i, j;
    for (i = 0; i < N; i++)
        max_sum += a[i];
    int dp[2][max_sum + 1], previous[max_sum + 1];
    for (i = 0; i <= N; i++)
        for (j = 0; j <= max_sum; j++)
            dp[i & 1][j] = 0;
    dp[0][0] = 1;
    for (i = 0; i < N; i++)
        for (j = 0; j <= max_sum; j++) {
            // first case is don't take a[i]
            dp[i & 1 ^ 1][j] = dp[i & 1][j];
            // second case is take a[i]
            if (j >= a[i]) {
                dp[i & 1 ^ 1][j] |= dp[i & 1][j - a[i]];
                // set the last element that makes the sum j to be a[i]
                previous[j] = a[i];
            }
        }
    // retrieve the subset the sums to the target
    if (!dp[N & 1][target])
        return 0;
    printf("%d = ", target);
    int current_sum = target;
    while (current_sum > 0) {
        printf("%d", previous[current_sum]);
        // subtract the last term and recurse to the subtracted sum
        current_sum -= previous[current_sum];
        if (current_sum == 0)
            break;
        printf(" + ");
    }
    printf("\n");
    return 1;
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
    printf("Result:\n");
    printf("Subset sum exists: %d\n", subset_sum(a, N, target));
    return 0;
}
