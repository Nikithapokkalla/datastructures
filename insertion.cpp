#include <stdio.h>
void insertSorted(int arr[], int size, int element) {
    int i = size - 1;
    while (i >= 0 && arr[i] > element) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int elementToInsert = 5;

    printf("Original array: ");
    printArray(arr, size);
    insertSorted(arr, size, elementToInsert);

    printf("Array after insertion: ");
    printArray(arr, size + 1);

    return 0;
}

