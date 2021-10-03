#This is a Python 3 program for Binary Search using recursive method.

#In this program, it will return the index of the number(Which we are searching for).
#If number not present it will return -1.

#Given Array of Numbers

array = [1, 3, 5, 13, 14, 15, 23, 19, 30, 35]

#Element to be Searched
search_element = int(input("Enter the Number To Be Searched: "))


def binary_search(array, low, high, search_element):
    #condition for checking base case

    if (high >=low):
        mid = (high + low) // 2

        #if the element is present at the middle itself
        if (array[mid] == search_element):
            return mid

        #if the element is smaller than mid, then the number only be present in left subarray.
        elif array[mid] > search_element:
            return binary_search(array, low, mid - 1, search_element)

        #else the element can be present only in right subarray
        else:
            return binary_search(array, mid + 1, high, search_element)

    else:
        # Else element not present in the array.
        return -1

result = binary_search(array, 0, len(array)-1, search_element)

if (result != -1):
    print(f"Element is present at index {result}")
else:
    print("Element is not present in the given array")
