/*
    Date created: 2024-11-28
    Program description:
        A program that generates all combinations of k integers from 1 to N for all 1 <= k <= N.
*/

#include <stdio.h>

void print_array(char *label, int a[6], int n) {
    printf("%s:\n", label);
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) printf("- ");
        else printf("%d ", a[i]);
    }
    printf("\n");
}

void print_2darray(char *label, int a[6][6], int n) {
    printf("%s:\n", label);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j][i] == -1) printf("- ");
            else printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}

void print_move(int move) {
    printf("Move: %d\n", move);
}

int main() {
    int N;
    printf("N: ");
    scanf("%d", &N);
    int nopts[N + 2], option[N + 2][N + 2], start, move, i, j, candidate;
    for (i = 0; i < N + 2; i++)
        for (j = 0; j < N + 2; j++)
            option[i][j] = -1;
    for (i = 0; i < N + 2; i++)
        nopts[i] = -1;
    move = start = 0;
    nopts[start] = 1;
    while (nopts[start] > 0) {
        printf("While loop:\n");
        print_2darray("Option", option, N + 2);
        print_array("N Options", nopts, N + 2);
        print_move(move);
        if (nopts[move] > 0) {
            printf("If-block:\n");
            nopts[++move] = 0;
            // in combination, order does not matter, so it is a good idea to only consider one order
            // this could be the increasing order
            for (candidate = N; candidate >= 1; candidate--) {
                // make sure that the candidate picked will be more than the previous (if it exists)
                if (move == 1 || candidate > option[move - 1][nopts[move - 1]])
                    option[move][++nopts[move]] = candidate;
                else
                    break;
                print_2darray("Option", option, N + 2);
                print_array("N Options", nopts, N + 2);
                print_move(move);
            }
        } else {
            // when backtracking, we transition from one combination to another
            // thus, we print before we backtrack everytime
            printf("Printed: ");
            for (i = 1; i < move; i++) {
                printf("%d", option[i][nopts[i]]);
                printf(i < move - 1 ? " " : "\n");
            }
            // backtrack
            nopts[--move]--;
        }
    }
    printf("End:\n");
    print_2darray("Option", option, N + 2);
    print_array("N Options", nopts, N + 2);
    print_move(move);
    return 0;
}
