#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Element found, return its index
        }
    }
    return -1;  // Element not found
}

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;  // Element found, return its index
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice, target, result;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            break;
        }

        printf("Enter the target element: ");
        scanf("%d", &target);

        switch (choice) {
            case 1:
                result = linearSearch(arr, n, target);
                break;
            case 2:
                result = binarySearch(arr, 0, n - 1, target);
                break;
            default:
                printf("Invalid choice. Please choose 1, 2, or 3.\n");
                continue;
        }

        if (result != -1) {
            printf("Element found at index: %d\n", result);
        } else {
            printf("Element not found in the array.\n");
        }
    }

    return 0;
}
