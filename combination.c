/*
    Date created: 2024-11-28
    Program description:
        A program that generates all combinations of k integers from 1 to N for all 1 <= k <= N.
*/

#include <stdio.h>

int main() {
    int N;
    printf("N: ");
    scanf("%d", &N);
    int nopts[N + 2], option[N + 2][N + 2], start, move, i, j, candidate;
    move = start = 0;
    nopts[start] = 1;
    while (nopts[start] > 0) {
        if (nopts[move] > 0) {
            nopts[++move] = 0;
            // in combination, order does not matter, so it is a good idea to only consider one order
            // this could be the increasing order
            for (candidate = N; candidate >= 1; candidate--)
                // make sure that the candidate picked will be more than the previous (if it exists)
                if (move == 1 || candidate > option[move - 1][nopts[move - 1]])
                    option[move][++nopts[move]] = candidate;
        } else {
            // when backtracking, we transition from one combination to another
            // thus, we print before we backtrack everytime
            for (i = 1; i < move; i++) {
                printf("%d", option[i][nopts[i]]);
                printf(i < move - 1 ? " " : "\n");
            }
            // backtrack
            nopts[--move]--;
        }
    }
    return 0;
}
