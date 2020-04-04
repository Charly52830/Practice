fact = [0]*27
fact[0] = 1
for i in range(1,27):
	fact[i] = i * fact[i-1]

for i in range(1,27) :
	for j in range(1,9):
		print("mapa[mp(%d,%d)] = %d;"%(i,j,fact[i]/(fact[j]*fact[i-j])))
