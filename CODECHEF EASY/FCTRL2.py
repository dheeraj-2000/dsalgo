t = int(input())

while (t>0) :
    n = int(input())
    fact = 1

    for i in range(1,n+1):
        fact= fact*i

    print(fact)

    t=t-1