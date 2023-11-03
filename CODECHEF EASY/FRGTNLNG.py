# cook your dish here
t=int(input())
while t!=0:
    t-=1
    n,k=map(int,input().split())
    l=input().split()
    a={}
    for i in l:
        a[i]="NO"
    for i in range(k):
        aa=input().split()
        for j in aa:
            try:
                if a[j]:
                    a[j]="YES"
            except:
                pass
    for i in l:
        print(a[i],end=" ")
    print()
    
    