n,k=map(int, input().split())
t=0
for i in range(n):
	a=int(input())
	if a%k==0:
		t+=1
print(t)