/*
    Date created: 2024-11-28
    Program description:
        A program that finds a subsets of an array of integers that sum to a particular target sum.
*/

#include <stdio.h>

// a function that takes in an array of integers of length N and a target sum
int subset_sum(int a[], int N, int target) { 
    // dp[j] = 1 if it is possible to get the sum j using the first i elements, 0 otherwise
    // previous[j] = a[i] => i is minimized and dp[j] = 1 and dp[j - a[i]] = 1
    int dp[target + 1], previous[target + 1], i, j;
    for (j = 0; j <= target; j++)
        dp[j] = 0;
    for (j = 0; j <= target; j++)
        previous[j] = -1;
    dp[0] = 1;
    for (i = 0; i < N; i++) {
        // reverse sum processing so that dp[j] only depends on the previous iteration's values
        for (j = target; j >= 0; j--) {
            // take a[i] case
            if (j >= a[i]) {
                dp[j] |= dp[j - a[i]];
                // set the last element that makes the sum j to be a[i] if it is possible to make j - a[i]
                if (previous[j] == -1 && dp[j - a[i]])
                    previous[j] = a[i];
            }
            printf("%d ", dp[j]);
        }
        printf("\n");
    }
    if (!dp[target])
        return 0;
    // if the target sum is achievable, retrieve the subset that sums to it
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