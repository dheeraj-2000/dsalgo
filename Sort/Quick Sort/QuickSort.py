# Quicksort function using recursive.
# Quicksort based on divide-and-conquer algorithm
# Average time complexity is O(NlogN)
def quicksort(arr, start, end):
    if start >= end:
        return

    # Choose pivot to end of elements.
    pivot = arr[end]

    # Find elements smaller than pivot, then Move to left side.
    i = start - 1
    for j in range(start, end):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[end] = arr[end], arr[i + 1]     # Move pivot to center

    # Divide to two partition.
    quicksort(arr, start, i)    # Smaller than pivot
    quicksort(arr, i + 2, end)  # Bigger than pivot

arr = [52, 17, 19, 3, 22, 8, 2, 41, 23]
print(f"The given unsorted list: {arr}")

quicksort(arr, 0, len(arr) - 1)
print(f"The sorted list is: {arr}")
