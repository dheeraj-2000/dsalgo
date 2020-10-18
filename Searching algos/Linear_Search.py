#List in which we want to perform the Linear Search
array = [1, 2, 3, 5, 7, 9, 11, 15, 19, 34, 35]

#The element which need to be searched
search_element = int(input("Enter the number to search: "))

#defining the function
def linearsearch(array, search_element):                
   for item in range(len(array)):          
      if array[item] == search_element:                 #If the given item is equal to the search element
         return item                                    #then, it will return the index
   return -1                                            #if search element not found in the array it will return -1
result = linearsearch(array, search_element)            #function call
if (result != -1):                                      #output for the above given conditions
    print(f"Element is present at index {result}")
else:
    print("Element is not present in the given array")

