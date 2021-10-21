arr = [1,2,3,2,4,6,3,7,3,9,7,0,6,8,5,4]  #random array
new_arr = []  #temporary array

for elem in arr:
    if elem not in new_arr:
        new_arr.append(elem)
        
arr = new_arr
