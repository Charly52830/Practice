t = int(input())

while t :
	s, k= input().split(' ')
	k = int(k)
	A = []
	digitos = "0123456789"
	num = 0
	for c in s :
		if c in digitos :
			num = num * 10 + int(c)
		else :
			if num == 0 :
				num = 1
			A.append((num, c))
			num = 0
	
	length = 0
	for n, _ in A :
		length += n
	if length <= k :
		ans = ""
		for n, c in A :
			ans += (c) * n
	else :
		ans = "unfeasible"
	
	print(ans)
	
	t -= 1

