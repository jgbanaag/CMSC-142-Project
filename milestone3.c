/*
    Date created: 2024-11-28
    Program description:
        A program that finds all subsets of an array of integers that sum to a particular target sum.
*/

#include <stdio.h>

// a function that takes in an array of integers of length N and a target sum
// it prints the distinct subsets that sum to the target and returns the number of such subsets
int subset_sum(int a[], int N, int target, int b[]) {
    // remove a[i] if b[i] = 1
    int removed_count = 0, i, target0 = target;
    for (i = 0; i < N; i++) {
        removed_count += b[i];
        target -= b[i] * a[i];
    }
    printf("%d\n", removed_count);
    int new_a[N - removed_count], real_index[N - removed_count], count = 0;
    for (i = 0; i < N; i++)
        if (!b[i]) {
            new_a[count] = a[i];
            real_index[count++] = i;
        }
    int N0 = N;
    N -= removed_count;
    int nopts[N + 2], option[N + 2][N + 2], start, move, j, candidate, found = 0;
    move = start = 0;
    nopts[start] = 1;
    while (nopts[start] > 0) {
        if (nopts[move] > 0) {
            nopts[++move] = 0;
            for (candidate = N; candidate >= 1; candidate--)
                if (move == 1 || candidate > option[move - 1][nopts[move - 1]])
                    option[move][++nopts[move]] = candidate;
        } else {
            // since before a backtrack, we get a unique combination
            // we use the combination as indices to generate a subset
            // get the sum
            int sum = 0;
            for (i = 1; i < move; i++)
                sum += new_a[option[i][nopts[i]] - 1];
            // then check if the sum equals the target sum
            if (sum == target) {
                printf("%d = ", target0);
                for (i = 0; i < N0; i++)
                    if (b[i]) {
                        if (i > 0)
                            printf(" + ");
                        printf("a[%d]", i);
                    }
                // print the subset in terms of their indices
                for (i = 1; i < move; i++) {
                    if (removed_count && i == 1)
                        printf(" + ");
                    int index = real_index[option[i][nopts[i]] - 1];
                    printf("a[%d]", index);
                    printf(i < move - 1 ? " + " : " = ");
                }
                for (i = 0; i < N0; i++)
                    if (b[i]) {
                        if (i > 0)
                            printf(" + ");
                        printf("%d", a[i]);
                    }
                // print the subset in terms of their actual values
                for (i = 1; i < move; i++) {
                    if (removed_count && i == 1)
                        printf(" + ");
                    int index = option[i][nopts[i]] - 1;
                    printf("%d", new_a[index]);
                    printf(i < move - 1 ? " + " : "\n");
                }
                // increase the number of subsets found
                found++;
            }
            nopts[--move]--;
        }
    }
    return found;
}
    
int main() {
    int N;
    printf("N: ");
    scanf("%d", &N);
    printf("Array: ");
    int a[N], i;
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("Picked: ");
    int b[N];
    for (i = 0; i < N; i++)
        scanf("%d", &b[i]);
    int target;
    printf("Target sum: ");
    scanf("%d", &target);
    printf("Result:\n");
    printf("Number of subsets found: %d\n", subset_sum(a, N, target, b));
    return 0;
}
