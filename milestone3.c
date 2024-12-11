/*
    Date created: 2024-11-28
    Program description:
        A program that finds all subsets of an array of integers that sum to a particular target sum.
*/

#include <stdio.h>

#define INF 1000000

// a function that takes in an array of integers of length N and a target sum
// it prints the distinct subsets that sum to the target and returns the number of such subsets
int subset_sum(int a[], int N, int b[], int M, int target) {
    // remove elements from a that are in b by marking them as INFINITY
    int c[N - M], real_index_initial[N], real_index_remaining[N - M], initial_sum = 0, i, j, k;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (a[j] == b[i]) {
                a[j] = INF;
                initial_sum += b[i];
                real_index_initial[i] = j;
            }
        }
    }
    // build the new array c that contains the remaining elements and also store their real indices
    for (i = 0, k = 0; i < N && k < N - M; i++) {
        if (a[i] != INF) {
            c[k] = a[i];
            real_index_remaining[k++] = i;
        }
    }
    int nopts[N - M + 2], option[N - M + 2][N - M + 2], start, move, candidate, found = 0;
    move = start = 0;
    nopts[start] = 1;
    while (nopts[start] > 0) {
        if (nopts[move] > 0) {
            nopts[++move] = 0;
            for (candidate = N - M; candidate >= 1; candidate--)
                if (move == 1 || candidate > option[move - 1][nopts[move - 1]])
                    option[move][++nopts[move]] = candidate;
                else
                    break;
        } else {
            int sum = 0;
            for (i = 1; i < move; i++)
                sum += c[option[i][nopts[i]] - 1];
            if (initial_sum + sum == target) {
                printf("%d = (", target);
                for (i = 0; i < M; i++) {
                    if (i > 0)
                        printf(" + ");
                    printf("%d", b[i]);
                }
                printf(")");
                for (i = 1; i < move; i++) {
                    if (i == 1)
                        printf(" + (");
                    if (i > 1)
                        printf(" + ");
                    printf("%d", c[option[i][nopts[i]] - 1]);
                    if (i == move - 1)
                        printf(")");
                }
                printf(" = (");
                for (i = 0; i < M; i++) {
                    if (i > 0)
                        printf(" + ");
                    printf("a[%d]", real_index_initial[i]);
                }
                printf(")");
                for (i = 1; i < move; i++) {
                    if (i == 1)
                        printf(" + (");
                    if (i > 1)
                        printf(" + ");
                    printf("a[%d]", real_index_remaining[option[i][nopts[i]] - 1]);
                    if (i == move - 1)
                        printf(")\n");
                }
                printf("\n");
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
    printf("M: ");
    int M;
    scanf("%d", &M);
    printf("Initial set: ");
    int b[M];
    for (i = 0; i < M; i++)
        scanf("%d", &b[i]);
    int target;
    printf("Target sum: ");
    scanf("%d", &target);
    printf("Result:\n");
    printf("Formula: <target> = (<initial sum>) + (<solution sum>)\n\n");
    printf("Number of subsets found: %d\n", subset_sum(a, N, b, M, target));
    return 0;
}
