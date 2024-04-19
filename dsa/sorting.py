from random import randint


def quick_sort(a: list, start: int, stop: int):
    if stop - start < 1:
        return

    pivot = a[start]
    idx = start
    for k in range(start + 1, stop + 1):
        if a[k] < pivot:
            idx += 1
            a[idx], a[k] = a[k], a[idx]
    a[start], a[idx] = a[idx], a[start]
    quick_sort(a, start, idx)
    quick_sort(a, idx + 1, stop)


def merge_sort(a: list, start: int, stop: int):
    if stop - start < 1:
        return

    middle = int((stop + start) / 2)
    merge_sort(a, start, middle)
    merge_sort(a, middle + 1, stop)

    tmp = []
    m = start
    n = middle + 1
    while m <= middle and n <= stop:
        if a[m] <= a[n]:
            tmp.append(a[m])
            m += 1
        else:
            tmp.append(a[n])
            n += 1
    while m <= middle:
        tmp.append(a[m])
        m += 1
    while n <= stop:
        tmp.append(a[n])
        n += 1
    for k in range(len(tmp)):
        a[start + k] = tmp[k]


def heapify(a: list, n: int, idx: int):
    largest = idx
    left = idx * 2 + 1
    right = idx * 2 + 2

    if left < n and a[left] > a[largest]:
        largest = left
    if right < n and a[right] > a[largest]:
        largest = right

    if largest != idx:
        a[idx], a[largest] = a[largest], a[idx]
        heapify(a, n, largest)


def heap_sort(a: list, start: int, stop: int):
    n = stop - start + 1
    idx = int(n / 2) - 1
    while idx >= 0:
        heapify(a, n, idx)
        idx -= 1

    for idx in range(n - 1, 0, -1):
        a[0], a[idx] = a[idx], a[0]
        heapify(a, idx, 0)


def bubble_sort(a: list, start: int, stop: int):
    for idx in range(stop, start, -1):
        for k in range(start, idx):
            if a[k] > a[k+1]:
                a[k], a[k+1] = a[k+1], a[k]


def insertion_sort(a: list, start: int, stop: int):
    for idx in range(start + 1, stop + 1):
        tmp = a[idx]
        k = idx - 1
        while k >= start and a[k] > tmp:
            a[k + 1] = a[k]
            k -= 1
        a[k + 1] = tmp


def selection_sort(a: list, start: int, stop: int):
    for idx in range(start, stop + 1):
        smallest = idx
        for k in range(idx + 1, stop + 1):
            if a[k] < a[smallest]:
                smallest = k
        a[smallest], a[idx] = a[idx], a[smallest]


def print_array(a: list, title: str):
    print(f"{title}:")
    print(a)


def main() -> int:
    n = 32
    origin = []
    for idx in range(n):
        origin.append(randint(0, 100))

    print_array(origin, "origin array")

    a = origin.copy()
    quick_sort(a, 0, n - 1)
    print_array(a, "quick sort")

    a = origin.copy()
    merge_sort(a, 0, n - 1)
    print_array(a, "merge sort")

    a = origin.copy()
    heap_sort(a, 0, n - 1)
    print_array(a, "heap sort")

    a = origin.copy()
    bubble_sort(a, 0, n - 1)
    print_array(a, "bubble sort")

    a = origin.copy()
    selection_sort(a, 0, n - 1)
    print_array(a, "selection sort")

    a = origin.copy()
    insertion_sort(a, 0, n - 1)
    print_array(a, "insertion sort")

    return 0


if __name__ == "__main__":
    exit(main())
