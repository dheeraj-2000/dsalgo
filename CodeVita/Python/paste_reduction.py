string_one=input()
string_two=input()
var1={}
var2=[]
j=0
while(j<len(string_two)):
	var1[string_two[j]]=0
	var2.append(string_two[j])
	j+=1
for i in range(len(string_one)):
	if(string_one[i] in var2):
		var1[string_one[i]]+=1
minimum_one=min(var1.values())
result=minimum_one
for i in var1.values():
	result=result+abs(i-minimum_one)
print(result)
