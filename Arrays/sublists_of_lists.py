def sublists(l): 
    b = []   
    arr = [b] 
    for i in range(len(l)): 
        old = arr[:] 
        new = l[i] 
        for j in range(len(arr)): 
            arr[j] = arr[j] + [new] 
        arr = old + arr       
    return arr
l = [1, 2, 3, 4] 
print(sublists(l)) 
