#https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1010
t = int(input())

for _ in range(t):
	A = input()
	B = input()
	n, m = len(A), len(B)
	dp = [[0] * n for _ in range(2)]
	for i in range(0, m) :
		for j in range(0, n) :
			if i > j :
				dp[i & 1][j] = 0
			elif j == 0 and i == 0 :
				dp[i & 1][j] = 1 if B[i] == A[j] else 0
			elif i == 0 :
				dp[i & 1][j] = dp[i & 1][j - 1] + (1 if B[i] == A[j] else 0)
			elif j == 0 :
				dp[i & 1][j] = 1 if B[i] == A[j] else 0
			else :
				dp[i & 1][j] = dp[i & 1][j - 1] + (dp[(i - 1) & 1][j - 1] if B[i] == A[j] else 0)
	print(dp[(m - 1) & 1][n - 1])
