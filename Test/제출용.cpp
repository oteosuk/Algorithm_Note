#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<pair<int, int>> p(N);

	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}

	return 0;
}