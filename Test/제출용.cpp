#include <iostream>

using namespace std;

#define endl '\n'

using ll = long long;
const int mod = 1000000007;

int dp[10000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;

	dp[0] = 1;

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1];

		if (i - M >= 0) 
			dp[i] = (dp[i] + dp[i - M]) % mod;
	}

	cout << dp[N];
    
	return 0;
}