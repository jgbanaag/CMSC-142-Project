/*
 * Author: Jan Neal Isaac D. Villamin
 * Lab section: T-2L
 * Date created: 2024-10-22
 * Program description:
 * 	A program that generates all permutations of integers from 1 to N.
 * Reference: https://github.com/ajjacildo/lfs/blob/main/lfs.c
 */

#include <stdio.h>

int main() {
	int N;
	printf("Enter N: ");
	scanf("%d", &N);
	int nopts[N + 2], option[N + 2][N + 2], start, move, i, candidate;
	move = start = 0;
	nopts[start] = 1;
	while (nopts[start] > 0) {
		if (nopts[move] > 0) {
			nopts[++move] = 0;
			if (move > N)
				for (i = 1; i < move; i++) {
					printf("%d", option[i][nopts[i]]);
                    printf(i < move - 1 ? " " : "\n");
                }
			for (candidate = N; candidate >= 1; candidate--) {
				for (i = move - 1; i >= 1; i--)
					if (option[i][nopts[i]] == candidate)
                        break;
				if (i == 0)
                    option[move][++nopts[move]] = candidate;
			}
		} else 
            nopts[--move]--;
	}
	return 0;
}
