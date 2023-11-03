# cook your dish here
t=int(input())
while t!=0:
    n=int(input())
    a=input()
    b=input()
    a0=a1=b0=b1=0
    for i in range(n):
        if a[i]=='0':
            a0+=1
        else:
            a1+=1
        if b[i]=='0':
            b0+=1
        else:
            b1+=1
    if b1==a1 and a0==b0:
        print('YES')
    else:
        print('NO')
    t-=1