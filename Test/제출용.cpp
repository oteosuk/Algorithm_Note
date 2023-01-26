#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	vector<pair<int, int>> p(N);

	for (int i = 0; i < N; i++) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p.begin(), p.end(), compare);

	int temp = 0, cnt = 0;

	for (int i = 0; i < N; i++) {
		if (temp <= p[i].first) {
			temp = p[i].second;
			cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}