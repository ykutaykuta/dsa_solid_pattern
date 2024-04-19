#include <iostream>
#include <stdlib.h>
#define N 32

using namespace std;

void quick_sort(int *a, int n) {
    if (n < 2) {
        return;
    }

    int pivot = a[0];
    int idx = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] < pivot) {
            swap(a[idx++], a[i]);
        }
    }
    swap(a[0], a[--idx]);
    quick_sort(a, idx);
    quick_sort(a + idx + 1, n - idx - 1);
}

void merge_sort(int *a, int n) {
    if (n < 2) {
        return;
    }

    int middle = n / 2;
    merge_sort(a, middle);
    merge_sort(a + middle, n - middle);

    int *tmp = new int[n];
    int  i = 0, j = middle, k = 0;
    while (i < middle && j < n) {
        if (a[i] < a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while (i < middle) {
        tmp[k++] = a[i++];
    }
    while (j < n) {
        tmp[k++] = a[j++];
    }
    copy(tmp, tmp + n, a);
    delete[] tmp;
}

void heapify(int *a, int n, int idx) {
    int l = idx * 2 + 1;
    int r = idx * 2 + 2;
    int largest = idx;
    if (l < n && a[l] > a[largest]) {
        largest = l;
    }
    if (r < n && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != idx) {
        swap(a[largest], a[idx]);
        heapify(a, n, largest);
    }
}

void heap_sort(int *a, int n) {
    for (int i = n / 2 - 1; i>=0; i--)  {
        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void bubble_sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n-i; j++) {
            if (a[j-1] >= a[j]) {
                swap(a[j-1], a[j]);
            }
        }
    }
}

void selection_sort(int *a, int n) {
    for (int i = 0; i < n; i++) {
        int sel = i;
        for(int k = i+1; k < n; k++) {
            if (a[k] < a[sel]) {
                sel = k;
            }
        }
        swap(a[sel], a[i]);
    }
}

void insertion_sort(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int j = i-1;
        int tmp = a[i];
        while (j >= 0 && a[j] > tmp) {
            a[j+1] = a[j];
            j--;
        }
        a[++j] = tmp;
    }
}

void print_array(int *a, int n, const char *title) {
    printf("%s: \n", title);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";
}

int main() {
    int origin[N], a[N];

    for (int i = 0; i < N; i++) {
        origin[i] = rand() % 100;
    }
    print_array(origin, N, "origin");

    copy(origin, origin + N, a);
    bubble_sort(a, N);
    print_array(a, N, "bubble sort");

    copy(origin, origin + N, a);
    insertion_sort(a, N);
    print_array(a, N, "insertion sort");

    copy(origin, origin + N, a);
    selection_sort(a, N);
    print_array(a, N, "selection sort");

    copy(origin, origin + N, a);
    quick_sort(a, N);
    print_array(a, N, "quick sort");

    copy(origin, origin + N, a);
    merge_sort(a, N);
    print_array(a, N, "merge sort");

    copy(origin, origin + N, a);
    heap_sort(a, N);
    print_array(a, N, "heap sort");

    return 0;
}