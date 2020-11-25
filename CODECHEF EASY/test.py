# cook your dish here
while True:
    n = int(input())
    if n == 0:
        break
    else:
        count = 1
        a = list(map(int, input().split()))
        for i in range(n):
            if (a[int(a[i])-1] != i+1):

                count = 0
                print("not ambiguous")
                break
        if count != 0:
            print("ambiguous")


