#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* Function to get the maximum value from an array */
int getMax(int *array, size_t size) {
    int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

/* Function to perform counting sort based on the digit position */
void countingSort(int *array, size_t size, int exp) {
    int output[size];
    int count[10] = {0};

    for (size_t i = 0; i < size; i++) {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

/* Radix Sort function */
void radix_sort(int *array, size_t size) {
    if (size < 2 || array == NULL) {
        return;
    }

    int max = getMax(array, size);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10) {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}
