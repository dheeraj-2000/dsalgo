import time
def selection_sort(a):
    for i in range(len(a)-1):
        minindex=i
        for j in range(i+1,len(a)):
            if a[j]<a[minindex]:
                minindex=j
        if i!=minindex:
            a[i],a[minindex]=a[minindex],a[i]

list1=[6,3,1,5,9,8]
seconds=time.time()
selection_sort(list1)
print(list1)
print(time.time()-seconds)

list2=[2,3,5,39,11,8,9,166,45,23]
seconds=time.time()
selection_sort(list2)
print(list2)
print(time.time()-seconds)

list3=[1,2,3,4,5,6,7,8,9,10]
seconds=time.time()
selection_sort(list3)
print(list3)
print(time.time()-seconds)

list4=[10,9,8,7,6,5,4,3,2,1]
seconds=time.time()
selection_sort(list4)
print(list4)
print(time.time()-seconds)


list5=[6]
seconds=time.time()
selection_sort(list5)
print(list5)
print(time.time()-seconds)
