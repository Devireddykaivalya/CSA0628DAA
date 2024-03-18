#include <stdio.h>
#define MAX_SIZE 100
void insertNumber(int arr[], int *size, int num, int pos) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    (*size)++;
}
int main() {
    int arr[MAX_SIZE];
    int size = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int num, pos;
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    printf("Enter the position to insert (0-indexed): ");
    scanf("%d", &pos);
    insertNumber(arr, &size, num, pos);
    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
