#include <stdio.h>

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}




void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("Original array for Bubble Sort: ");
    printArray(arr1, n1);

    bubbleSort(arr1, n1);

    printf("Sorted array after Bubble Sort: ");
    printArray(arr1, n1);

    int arr2[] = {64, 25, 12, 22, 11};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\nOriginal array for Selection Sort: ");
    printArray(arr2, n2);

    selectionSort(arr2, n2);

    printf("Sorted array after Selection Sort: ");
    printArray(arr2, n2);

    int arr3[] = {12, 11, 13, 5, 6};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    printf("\nOriginal array for Insertion Sort: ");
    printArray(arr3, n3);

    insertionSort(arr3, n3);

    printf("Sorted array after Insertion Sort: ");
    printArray(arr3, n3);

    return 0;
}
