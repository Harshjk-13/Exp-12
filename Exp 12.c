#include <stdio.h>

// Function for Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function for Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function for Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function with menu-driven program
int main() {
    int choice, n, i;
    int arr[100];

    do {
        printf("\nMenu:\n");
        printf("1. Selection Sort\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Enter the number of elements in the array: ");
            scanf("%d", &n);
            printf("Enter the elements of the array:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }

            // Perform sorting based on user choice
            switch (choice) {
                case 1:
                    selectionSort(arr, n);
                    printf("Array sorted using Selection Sort:\n");
                    break;
                case 2:
                    bubbleSort(arr, n);
                    printf("Array sorted using Bubble Sort:\n");
                    break;
                case 3:
                    insertionSort(arr, n);
                    printf("Array sorted using Insertion Sort:\n");
                    break;
            }

            // Display the sorted array
            displayArray(arr, n);
        }

    } while (choice != 4);

    printf("Exiting program.\n");
    return 0;
}
