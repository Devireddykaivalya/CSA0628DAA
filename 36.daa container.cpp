#include <stdio.h>

#define MAX_ITEMS 100

typedef struct {
    int width;
    int height;
    int depth;
} Item;

void loadContainers(Item items[], int n, int containerWidth, int containerHeight, int containerDepth) {
    int containerCount = 1;
    int remainingWidth = containerWidth;
    int remainingHeight = containerHeight;
    int remainingDepth = containerDepth;

    for (int i = 0; i < n; i++) {
        if (items[i].width <= remainingWidth &&
            items[i].height <= remainingHeight &&
            items[i].depth <= remainingDepth) {
            printf("Item %d fits into container %d\n", i + 1, containerCount);
            remainingWidth -= items[i].width;
            remainingHeight -= items[i].height;
            remainingDepth -= items[i].depth;
        } else {
            containerCount++;
            remainingWidth = containerWidth;
            remainingHeight = containerHeight;
            remainingDepth = containerDepth;
            printf("Item %d does not fit into container %d. Placed in new container.\n", i + 1, containerCount);
            printf("Item %d fits into container %d\n", i + 1, containerCount);
            remainingWidth -= items[i].width;
            remainingHeight -= items[i].height;
            remainingDepth -= items[i].depth;
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    int itemCount;
    int containerWidth, containerHeight, containerDepth;

    printf("Enter the number of items: ");
    scanf("%d", &itemCount);

    printf("Enter the dimensions of the container (width height depth): ");
    scanf("%d %d %d", &containerWidth, &containerHeight, &containerDepth);

    printf("Enter the dimensions of each item (width height depth):\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d %d", &items[i].width, &items[i].height, &items[i].depth);
    }

    printf("Loading items into containers...\n");
    loadContainers(items, itemCount, containerWidth, containerHeight, containerDepth);

    return 0;
}
