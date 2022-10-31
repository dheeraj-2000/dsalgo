#include <iostream>
using namespace std;
#include <climits>
#include <algorithm>
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swap2(int* data, int a,  int b)
{
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

void insertion(int arr[],int n)
{
    // pick an eleement and swap it untill it can't be swapped more.
    int i,j,temp;

    for (i=1; i<n; i++)
    {
        j = i;
        while (arr[j] < arr[j-1] && j>0) // agr upar wala bda hai then swap 
        {
          // swap arr[j] with arr[j-1]
          
            swap(arr[j],arr[j-1]);
            j=j-1;  // because swap hokr element moves up and we want to swap that particular element only
          
        }
        
    }
}


void bubble(int arr[],int n)
// swap adjacenent elements untill they can't be swapped any more
// order (n^2)
{
    int numswaps;

    do
    {
        // The number of swaps in this run through the loop starts at zero
        numswaps = 0; // if numswaps is 0 then list is sorted

        for (int i=1; i<n; i++)
        {
            if(arr[i] < arr[i-1])
            {
                swap(arr[i], arr[i-1]);
                // Increment the number of swaps we did
                numswaps++;
            }
        }
    } while (numswaps > 0); // exit if the number of swaps is zero
}

void selection(int arr[],int n)
// find the least element and swap it to starting pos
{
    for (int i = 0; i < n-1; i++)
    {
        int min = arr[i];
        int minpos = i;

        for(int j=i+1;j<n;j++)
        {
            if(min > arr[j])
            {
                min = arr[j];
                minpos = j;
            }
        }
        swap(arr[i], arr[minpos]); // ismei swap bahar as we need to first find the least element in the whole array.
    }
}

void quicksort(int* data, int left, int right)
{
    // Return if there's only a single element
    if (left >= right)
        return;

    // If there are only two elements the sort is trivial
    if (left == right-1)
    {
        if (data[left] > data[right])
            swap2(data, left, right);
        return;
    }

    // We have the pivot as the first element, and we need to sort the
    // rest of the array into a part less than the pivot and a part
    // greater then the pivot.
    int last = left;
    int pivot = data[left];
    // And rearrange the array into the two parts
    for (int i = left+1; i <= right; i++)
    {
        if (data[i] < data[left])
        {
            last += 1;
            swap2(data, last, i);
        }
    }
    swap2(data, left, last);

    // Now recurse to sort the two partitions
    quicksort(data, left, last-1);
    quicksort(data, last+1, right);
}

void merge(int arr[], int n)
{
    // If the array length is 1 there is nothng to do
    if (n == 1)
        return;
    // If the array length is 2 the sort is trivial
    if (n == 2)
        if (arr[0] > arr[1])
            swap(arr[0], arr[1]);

    // For array lengths > 2 split the array in two
    int mid = n/2;
    int len_left = mid;
    int len_right = n - mid;
    int left[len_left];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < n; i++)
        right[i-mid] = arr[i];

    // Sort the sub arrays
    merge(left, len_left);
    merge(right, len_right);

    // Merge the sub arrays
    int l = 0, r = 0, a = 0;
    while (l < len_left && r < len_right)
    {
        if (left[l] < right[r])
            arr[a++] = left[l++];
        else
            arr[a++] = right[r++];
    }
    // At this point we have reached the end of one of the arrays, so we
    // just need to copy in the elements from the other array
    if (l >= len_left) // this is true if we reached the end of left[]
    {
        // Copy the remaining elements from the right[] array
        while (r < len_right)
            arr[a++] = right[r++];
    }
    else // this is if we reached the end of right[]
    {
        // Copy the remaining elements from the left[] array
        while (l < len_left)
            arr[a++] = left[l++];
    }
}

/*Print sorted array*/
void printarr(int arr[],int n){
    int i;
 cout<<"Sorted Array: \n";
    for(i=0;i<n;i++){
    cout<<"arr["<<i<<"]: "<<arr[i]<<endl;
    }

}

int main(){
    int n,i ;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
    cout<<"Enter the "<<i<<"th element: ";
    cin>>arr[i];
    }
    char input = ' ';
    std::cout << "1) insertion sort\n";
    std::cout << "2) bubble\n";
    std::cout << "3) selection sort\n";
    std::cout << "4) quicksort\n";
    std::cout << "5) merge sort\n";
        while(input != 'x'){
        std::cout << ">";
        std::cin >> input;
        switch(input){
            case '1':
                    insertion(arr,n);
                    printarr(arr,n);
  
                break;
            case '2':
                    bubble(arr,n);
                    printarr(arr,n);
                break;
            case '3':
                    selection(arr,n);
                    printarr(arr,n);
                break;
            case '4':
                    quicksort(arr,0,n);
                    printarr(arr,n);
                break;
            case '5':
                merge(arr,n);
                printarr(arr,n);
                break;
            case 'x':
                break;
            default:
                std::cout << "Invalid input\n";
                break;
        }
        }
    return 0;
}
