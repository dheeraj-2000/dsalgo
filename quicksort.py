quickSort(arr[], low, high) 
{
    if (low < high) 
    {
    pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
    }
}
