from math import sqrt
t=int(input())
for i in range(t):
	n,v1,v2=map(int,input().split())
	t1=(n*sqrt(2))/(v1)
	t2=(n*2)/(v2)
	#print(t1,t2)
	if t1<t2:
		print("Stairs")
	else:
		print("Elevator")