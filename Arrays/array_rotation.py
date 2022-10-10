def left_rotateArray(a,d):
    temp = []
    n=len(a)
    
    for i in range(d,n):
        temp.append(a[i])
        
    i = 0
    
    for i in range (0,d):
        temp.append(a[i])
        
    a=temp.copy()
    return a
 
arr = [6, 4, 5, 9, 2]
print("Array after rotation: ", end=' ')
print(left_rotateArray(arr, 2))
