# Given below is the list in which searching operation is done.
list1 = [2, 3, 6, 12, 13, 15, 17, 22, 23, 27]

# The element which is needed to be searched
Number = int(input("Enter the number to search: "))

# Variable 'start' represents the index 0
start=0

# Variable 'end' represents the last index n.
# We use len() function to find the length of list.
end=len(list1)-1
flag = 0

# Since the array is sorted.
while(start<=end and Number>=list1[start] and Number<=list1[end]):

    # This condition becomes true if the array consist of just one element.
    if(start==end):
        if list1[start] == Number:
            print(start)
            flag = 1
        else:
            print("-1")
            
    # To find the mid element of the given array.
    random= start + int(((float(end-start)/(list1[end]-list1[start]))*(Number-list1[start])))
    if list1[random]==Number:
        print(f" The number {Number} is present on the index {random}")
        flag=1
    if list1[random]<Number:
        start= random+1
    else:
        end= random-1
if(flag==0):
    print(f"The number {Number} is not present in the given list!")
