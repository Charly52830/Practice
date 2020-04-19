#https://omegaup.com/arena/omegacup4/#problems/PSP-y-tamanos-relativos
from math import *

def covariance(x, y) :
	x_mean = mean(x) 
	y_mean = mean(y)
	sum = 0
	n = len(x)
	for i in range(n) :
		sum += (x[i] - x_mean) * (y[i] - y_mean)
	return sum / n

def stdev(elems) :
	elems_mean = mean(elems)
	sum = 0
	n = len(elems)
	for i in elems :
		sum += (i - elems_mean) ** 2
	return sqrt(sum / (n-1))

def mean(elems) :
	sum = 0;
	for i in elems : 
		sum += i
	return sum / len(elems)

n = int(input())
X=[]
while n > 0 :
	k=float(input())
	X.append(log(k))
	n-=1

st = stdev(X)
avg = mean(X)
ln_vs = avg - 2 * st
ln_s = avg - st
ln_m = avg
ln_l = avg + st
ln_vl = avg + 2 * st

print("%.2lf"%(exp(ln_vs)))
print("%.2lf"%(exp(ln_s)))
print("%.2lf"%(exp(ln_m)))
print("%.2lf"%(exp(ln_l)))
print("%.2lf"%(exp(ln_vl)))
