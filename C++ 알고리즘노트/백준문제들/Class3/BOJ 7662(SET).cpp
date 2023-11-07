#include <iostream>
#include <set>

using namespace std;

#define endl '\n'

int T, k, n;
char c;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> k;
		multiset<int> ms; // 기본 오름차순
		while (k--) {
			cin >> c >> n;
			if (c == 'I') {
				ms.insert(n);
			}
			else if (c == 'D') {
				if (ms.empty()) {
					continue;
				}
				else if (n == 1) {
					auto it = ms.end();
					it--;
					ms.erase(it);
				}
				else if (n == -1) {
					ms.erase(ms.begin());
				}
			}
		}
		if (ms.empty()) {
			cout << "EMPTY" << endl;
		}
		else {
			auto end_it = ms.end();
			end_it--;
			cout << *end_it << " " << *ms.begin() << endl;
		}
	}

	return 0;
}