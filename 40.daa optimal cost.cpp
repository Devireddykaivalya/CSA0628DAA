#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 10

int graph[MAX_SIZE][MAX_SIZE];
int minCost = INT_MAX;
int optimalPath[MAX_SIZE];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void findPermutations(int arr[], int start, int n) {
    if (start == n - 1) {
        int currentCost = 0;
        for (int i = 0; i < n - 1; i++) {
            currentCost += graph[arr[i]][arr[i + 1]];
        }
        currentCost += graph[arr[n - 1]][arr[0]]; // Return to the starting city

        if (currentCost < minCost) {
            minCost = currentCost;
            for (int i = 0; i < n; i++) {
                optimalPath[i] = arr[i];
            }
        }
        return;
    }

    for (int i = start; i < n; i++) {
        swap(&arr[start], &arr[i]);
        findPermutations(arr, start + 1, n);
        swap(&arr[start], &arr[i]); // backtrack
    }
}

int main() {
    int n;

    printf("Enter the number of cities (maximum 10): ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int cities[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        cities[i] = i;
    }

    findPermutations(cities, 0, n);

    printf("Optimal cost: %d\n", minCost);
    printf("Optimal path: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", optimalPath[i]);
    }
    printf("\n");

    return 0;
}
