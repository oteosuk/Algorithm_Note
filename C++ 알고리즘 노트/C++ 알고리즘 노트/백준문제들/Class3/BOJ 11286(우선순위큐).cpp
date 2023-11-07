#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

#define endl '\n'

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) != abs(b))
			return abs(a) > abs(b); //오름차순
		return a > b; // 오름차순
	}
};

priority_queue<int, vector<int>, compare> pq;

void absHip(int num) {
	if (num == 0) {
		if (!pq.empty()) {
			cout << pq.top() << endl;
			pq.pop();
		}
		else
			cout << 0 << endl;
	}
	else {
		pq.push(num);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	while (N--) {
		int num; cin >> num;
		absHip(num);
	}

	return 0;
}