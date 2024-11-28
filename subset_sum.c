#include <stdio.h>

int subset_sum(int a[], int N, int target) {
    int nopts[N + 2], option[N + 2][N + 2], start, move, i, j, candidate, found = 0;
    move = start = 0;
    nopts[start] = 1;
    while (nopts[start] > 0) {
        if (nopts[move] > 0) {
            nopts[++move] = 0;
            for (candidate = N; candidate >= 1; candidate--)
                if (move == 1 || candidate > option[move - 1][nopts[move - 1]])
                    option[move][++nopts[move]] = candidate;
        } else {
            int sum = 0;
            for (i = 1; i < move; i++)
                sum += a[option[i][nopts[i]] - 1];
            if (sum == target) {
                printf("%d = ", target);
                for (int i = 1; i < move; i++) {
                    int index = option[i][nopts[i]] - 1;
                    printf("a[%d]", index);
                    printf(i < move - 1 ? " + " : " = ");
                }
                for (int i = 1; i < move; i++) {
                    int index = option[i][nopts[i]] - 1;
                    printf("%d", a[index]);
                    printf(i < move - 1 ? " + " : "\n");
                }
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
    int target;
    printf("Target sum: ");
    scanf("%d", &target);
    printf("Result:\n");
    printf("Number of subsets found: %d\n", subset_sum(a, N, target));
    return 0;
}
