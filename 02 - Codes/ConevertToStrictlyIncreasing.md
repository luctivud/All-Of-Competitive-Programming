<h2> Convert an array into Strictly Increasing Array </h2>
<i> Solution by Udit Gupta </i>

</br>
<br>

<h3> Problem Statement </h3>

Given an array consisting of <b> N </b> elements namely from A<sub>1</sub> to A<sub>N</sub>. You have to convert this array to <strong>strictly increasing </strong> array in not more than <strong> K</strong> cost. 
Operations allowed :
1. Increase an element by 1.
2. Decrease an element by 1.

Cost of each operation is 1 unit.

</br>

<h3> Constraints </h3>

- <b> N < 3000 </b>
  
- <b> K < 5000 </b>
  
- <b> |A<sub>i</sub>| < 10<sup>9</sup> </b> for all i from 1 to N.
  
</br>

<h4> Expected Time Complexity : O(N<sup>2</sup>) </h4>
  
  </hr>
  </br>
  
<br>

<h3> Solution </h3>

<h4> Observation </h4>
  <p>
    
  1. After solving a few examples on pen and paper, we get to see that a greedy solution would fail on cases like [8, 1, 2, 3, 4] or [7, 1, 5, 2, 4, 8, 6].
  
  2. Another key observation is that in the transformed array which is strictly increasing, we will find that  there is atleast one element which remains unchanged. 
  </p>
  
<h4> Deduction </h4>

The problem statement above can be translated into simpler terms by stating that 

for each i from _1_ to _N-1_,  &nbsp; **A<sub>i</sub> &nbsp; < &nbsp; A<sub>i+1</sub>**

Now we shall work on simplifying it further and deducing a general formula for all terms, 

- **A<sub>i</sub> &nbsp; &le; &nbsp; A<sub>i+1</sub> - 1**

- Subtracting i from both sides, 

- **A<sub>i</sub>-i &nbsp; &le; &nbsp; A<sub>i+1</sub>-1-i**

_or_

- **A<sub>i</sub>-i &nbsp; &le; &nbsp; A<sub>i+1</sub>-(i+1)**

This is the general formulation which should work for all indices in range [1, N].
i.e.  

The sequence represented by (A<sub>i</sub>-i) &nbsp; &forall; &nbsp; i &isin; [1, N] should be a **non decreasing sequence**.

To achieve this we take use of dynamic programming and brute force our way to make the subsequent array element equal to the previous one if not or leaving it as it is depending on the previous dp state. 

This idea, here, comes from observation 2 and we can even end up converting the whole array to a single element. 

<p style = "padding-left: 50pt;">
DP transition states:

- **dp[j] = min(dp[j-1], dp[j] + abs(A[i] - B[j]))** &nbsp; &forall; &nbsp; i, j &isin; [1, N]. 

Please note that the array **A** here is the converted array represented by (A<sub>i</sub>-i) &nbsp; &forall; &nbsp; i &isin; [1, N] and **B** is its sorted version. 

Our final answer that represents the minimum cost is stored in the final index of our **dp** array which represents the optimal array till last index of **A**.
</p>

If our minimum cost is not more than **K** then we can certainly achieve the optimal solution.

Note : This dp solution can be made more state verbose by storing the brute forced optimal substructure into their respective states in dp[i][j] but I prefer it this way. 

<details>
  <summary>Python Code</summary>
<p>

```python
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
```
  
</p>
</details>

<details>
  <summary>C++ Code</summary>
<p>

```cpp
#include<iostream>
#include<vector>
#include<algorithm>

signed main() {
	long long N, K;
	std::cin >> N >> K;

	std::vector<long long> A(N+1, 0ll);
	for (long long i = 1ll; i <= N; i++) {
		std::cin >> A.at(i);
		A.at(i) -= i;
	}

	// sorted version of A
	std::vector<long long> B{A};
	std::sort(B.begin() + 1ll, B.end());

	// dp array
	std::vector<long long> dp(N+1, 0ll);
	dp.at(0) = (long long) 1e9;

	for (long long i = 1ll; i <= N; i++) {
		for (long long j = 1ll; j <= N; j++) {
			dp.at(j) = std::min(dp.at(j-1), dp.at(j) + llabs(A.at(i) - B.at(j)));
		}
	}

	if (dp.at(N) <= K) {
		std::cout << "YES " << dp.at(N);
	} else {
		std::cout << "NO";
	}

	return 0;
}
```
  
</p>
</details>




Time Complexity : O(N<sup>2</sup>)

Space Complexity : O (N)




  
  
