#include <stdio.h>

#define INF 999999

int main() {
    int n, i, j;
    int graph[20][20];
    int selected[20] = {0};
    int edges = 0, totalCost = 0;
    int min, x = -1, y = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
}

    selected[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");
    printf("Edge\tWeight\n");

    while (edges < n - 1) {
        min = INF;
        x = -1;
        y = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
}
                }
            }
        }

        if (x == -1) {
            printf("Graph is disconnected!\n");
            return 0;
        }

        printf("%d - %d\t%d\n", x, y, min);

        totalCost += min;
        selected[y] = 1;
        edges++;
    }

    printf("Total cost of MST: %d\n", totalCost);

    return 0;
}
