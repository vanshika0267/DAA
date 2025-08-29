#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubbleSort(int arr[], int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

int selectionSort(int arr[], int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
    return swaps;
}

int insertionSort(int arr[], int n) {
    int swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
    }
    return swaps;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

void fillRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

int main() {
    srand(time(0));
    int sizes[] = {10, 100};

    for (int s = 0; s < 2; s++) {
        int n = sizes[s];
        int arr[n], temp[n];

        printf("\n--- Sorting %d elements ---\n", n);
        fillRandomArray(arr, n);

        copyArray(arr, temp, n);
        clock_t start = clock();
        int swaps = bubbleSort(temp, n);
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Bubble Sort -> Time: %.8f sec, Swaps: %d\n", time_taken, swaps);

        copyArray(arr, temp, n);
        start = clock();
        swaps = selectionSort(temp, n);
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Selection Sort -> Time: %.8f sec, Swaps: %d\n", time_taken, swaps);

        copyArray(arr, temp, n);
        start = clock();
        swaps = insertionSort(temp, n);
        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Insertion Sort -> Time: %.8f sec, Shifts: %d\n", time_taken, swaps);
    }

    return 0;
}
