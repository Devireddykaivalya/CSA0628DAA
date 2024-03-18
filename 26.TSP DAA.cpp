#include <stdio.h>
#define MAX_NODES 10
int cost = 0, n;
int arr[MAX_NODES][MAX_NODES], visited[MAX_NODES];
void Input() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the Cost Matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
        visited[i] = 0; 
    }
}
int least(int c) {
    int min_cost = 999, next_node = 999;
    for (int i = 0; i < n; i++) {
        if (arr[c][i] != 0 && visited[i] == 0 && arr[c][i] < min_cost) {
            min_cost = arr[c][i];
            next_node = i;
        }
    }
    if (next_node != 999) {
        cost += min_cost;
    }
    return next_node;
}
void mincost(int node) {
    visited[node] = 1;
    printf("%d--->", node + 1);
    int next_node = least(node);
    if (next_node == 999) {
        next_node = 0;
        printf("%d", next_node + 1);
        cost += arr[node][next_node];
        return;
    }
    mincost(next_node);
}
int main() {
    Input();
    printf("\n\nThe Path is:\n");
    mincost(0); // Start from node 1
    printf("\n\nMinimum cost is %d\n", cost);
    return 0;
}
