#https://codeforces.com/gym/102367/problem/A
def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)

l=[int(num) for num in input().split(" ")]
a2,b2,c2=l
l.sort()
a,b,c=l
mcm=(a*b*c)//(gcd(gcd(a,b),c))

l=[mcm//a for _ in range(1,a+1)]
l2=[]

k=mcm//b
r=k
for x in l:
	while x > 0:
		if x >= r:
			l2.append(r)
			x-=r
			r=k
		else:			
			l2.append(x)
			r-=x
			x-=x
l3=[]
k=mcm//c
r=k
for x in l2:
	while x > 0:
		if x >= r:
			l3.append(r)
			x-=r
			r=k
		else:			
			l3.append(x)
			r-=x
			x-=x
print(len(l3))
a1,b1,c1=1,1,1
sum1,sum2,sum3=0,0,0
a=mcm//a2
b=mcm//b2
c=mcm//c2
for x in l3:
	print(x,a1,b1,c1)
	sum1+=x
	sum2+=x
	sum3+=x
	if sum3%c == 0:
		c1+=1
	if sum2%b == 0:
		b1+=1
	if sum1%a == 0:
		a1+=1
