#include <stdio.h>
#include <limits.h>

#define N 10

int costMatrix[N][N];
int minCost = INT_MAX;
int minAssignment[N];

void copyArray(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int calculateCost(int assignment[], int n) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}

void branchAndBound(int currentCost, int level, int assignment[], int n) {
    if (level == n) {
        if (currentCost < minCost) {
            minCost = currentCost;
            copyArray(minAssignment, assignment, n);
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (assignment[i] == -1) {
            assignment[i] = level;
            int newCost = currentCost + costMatrix[level][i];
            if (newCost < minCost) {
                branchAndBound(newCost, level + 1, assignment, n);
            }
            assignment[i] = -1; 
        }
    }
}

int main() {
    int n;

    printf("Enter the number of tasks/resources (N <= 10): ");
    scanf("%d", &n);

    printf("Enter the cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    int assignment[N];
    for (int i = 0; i < N; i++) {
        assignment[i] = -1; 
    }

    branchAndBound(0, 0, assignment, n);

    printf("Minimum cost: %d\n", minCost);
    printf("Assignment: ");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", i, minAssignment[i]);
    }
    printf("\n");

    return 0;
}
