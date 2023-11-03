t=int(input())
for i in range(t):
	a,b=map(int,input().split())
	sum=0
	z=[]
	while (a!=0 or b!=0 ):
		x=a%10
		y=b%10
		z.insert(0,(x+y)%10)
		if a!=0:
			a=int(a/10)
		if b!=0:
			b=int(b/10)
	for i in range (len(z)):
		sum=sum+z[i]*(10**(len(z)-i-1))
	print(sum)
