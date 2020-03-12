#https://www.spoj.com/problems/BRKSTRNG/
#Status: TLE
import sys
N = 1010

class InputManager() :
	
	def __init__(yo, stream) :
		yo.iterator = iter(stream)
		yo.empty = False
		yo.flush_line = True
		yo.last_line = ''
	
	def get_next(yo) :
		try :
			yo.last_line = next(yo.iterator)
			yo.flush_line = False
		except StopIteration :
			yo.empty = True
			yo.flush_line = True
			yo.last_line = ''
	
	def has_next(yo) :
		if yo.flush_line :
			yo.get_next()
		return not yo.empty
		
	def next_line(yo) :
		if yo.flush_line :
			yo.get_next()
		yo.flush_line = True
		return yo.last_line

dp = [[0] * N for _ in range(N)]
pos = [[0] * N for _ in range(N)]
		
def f(i, j) :
	if i == 0 :
		return A[j]
	return A[j] - A[i - 1]

if __name__ == '__main__' :
	io = InputManager(sys.stdin)
	while io.has_next() :
		n, m = map(int, io.next_line().split())
		A = list(map(int, io.next_line().split()))
		m += 1
		A.append(n)
		
		# Knuth-Yao Optimization
		for k in range(m) :
			for i in range(m - k) :
				j = i + k
				if i == j :
					dp[i][j] = 0
					pos[i][j] = i
				else :
					pos_left = pos[i][j - 1]
					pos_right = pos[i + 1][j]
					best_pos = pos_left
					for p in range(pos_left, min(pos_right + 1,j)) :
						if dp[i][p] + dp[p + 1][j] < dp[i][best_pos] + dp[best_pos + 1][j] :
							best_pos = p
					dp[i][j] = dp[i][best_pos] + dp[best_pos + 1][j] + f(i,j)
					pos[i][j] = best_pos
		print(dp[0][m - 1])

