# cook your dish here
t=int(input())
while t!=0:
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a=list(map(lambda x:x+k,a))
    count=0
    for i in a:
        if i%7==0:
            count+=1
    print(count)
    t-=1