#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int find(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

double calculateAverage(int arr[], int n) {
    if (n == 0) return 0;
    int jumlah = 0;
    for (int i = 0; i < n; i++) {
        jumlah += arr[i];
    }
    return (double)jumlah / n;
}

int findMedian(int arr[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    sort(temp, n);
    return (n % 2 == 0) ? (temp[n / 2 - 1] + temp[n / 2]) / 2 : temp[n / 2];
}

int findMode(int arr[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) temp[i] = arr[i];
    sort(temp, n);
    int mode = temp[0], max = 1, hitung = 1;
    for (int i = 1; i < n; i++) {
        if (temp[i] == temp[i - 1]) hitung++;
        else hitung = 1;
        if (hitung > max) {
            max = hitung;
            mode = temp[i];
        }
    }
    return mode;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

void reverseArray(int arr[], int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}