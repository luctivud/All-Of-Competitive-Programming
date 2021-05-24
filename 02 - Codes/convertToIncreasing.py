N = int(input())
K = int(input())
A = [0] + list(map(int, input().split()))

# Convert A[i] = A[i] - i
for i in range(1, N+1):
	A[i] = A[i] - i

# store sorted A in B to stay working
# with best possible element already
B = [0] + sorted(A[1:])

# dp array 
dp = [0 for x in range(N+1)]

# unreachable state
dp[0] = float('inf')

for i in range(1, N+1):
	for j in range(1, N+1):
		dp[j] = min(dp[j-1], dp[j] + abs(A[i] - B[j]))


# dp[N] represent the ans
print("YES "+str(dp[N]) if dp[N] <= K else "NO")