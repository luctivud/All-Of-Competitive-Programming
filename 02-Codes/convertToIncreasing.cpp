#include<bits/stdc++.h>

using namespace std;

signed main() {
	long long N, K;
	cin >> N >> K;

	vector<long long> A(N+1, 0ll);
	for (long long i = 1ll; i <= N; i++) {
		cin >> A.at(i);
		A.at(i) -= i;
	}

	// sorted version of A
	vector<long long> B{A};
	sort(B.begin() + 1ll, B.end());

	// dp array
	vector<long long> dp(N+1, 0ll);
	dp.at(0) = (long long) 1e9;

	for (long long i = 1ll; i <= N; i++) {
		for (long long j = 1ll; j <= N; j++) {
			dp.at(j) = min(dp.at(j-1), dp.at(j) + llabs(A.at(i) - B.at(j)));
		}
	}

	if (dp.at(N) <= K) {
		cout << "YES " << dp.at(N);
	} else {
		cout << "NO";
	}

	return 0;
}