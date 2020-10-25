#defining the function bubblesort
def bubblesort(list):

# Swap the elements to arrange in order
    for iter_num in range(len(list)-1,0,-1):
        
        # Traverse through all array elements
        for index in range(iter_num):

            # Swap if the element found is greater 
            # than the next element using a temporary variable.
            if list[index]>list[index+1]:
                temp = list[index]
                list[index] = list[index+1]
                list[index+1] = temp

#the given unsorted list(input list)
list = [19,2,31,45,6,11,121,27]
print(f"The given unsorted list: {list}")

#the output sorted list.
bubblesort(list)
print(f"The sorted list is: {list}")
