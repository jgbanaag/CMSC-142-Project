/*
 * Author: Jan Neal Isaac D. Villamin
 * Lab section: T-2L
 * Date created: 2024-10-22
 * Program description:
 * 	A program that generates all combinations of k integers from 1 to N for all 1 <= k <= N.
 */

#include <stdio.h>

int main() {
	int N;
	printf("Enter N: ");
	scanf("%d", &N);
	int nopts[N + 2], option[N + 2][N + 2], start, move, i, j, candidate;
	move = start = 0;
	nopts[start] = 1;
	while (nopts[start] > 0) {
		if (nopts[move] > 0) {
			nopts[++move] = 0;
			// in combination, order does not matter
			// hence, we just need one order of a particular combination
			// thus, it is a good idea to maintain an increasing order (sorted order)
			// therefore, only add a candidate that is greater than the previous selected candidate
			for (candidate = N; candidate >= 1; candidate--)
                if (move == 1 || candidate > option[move - 1][nopts[move - 1]])
                    option[move][++nopts[move]] = candidate;
		} else {
			// when backtracking, we transition from one combination to the other
			// thus, we print before everytime we backtrack
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
