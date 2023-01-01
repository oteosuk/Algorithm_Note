#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;

	int ans = 0;
	string num;
	bool minus = false;

	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size() || s[i] == '-' || s[i] == '+') {
			if (minus) {
				ans -= stoi(num);
				num = "";
				minus = true;
			}
			else {
				ans += stoi(num);
				num = "";
			}
		}
		else 
			num += s[i];
	}

	cout << ans;

	return 0;
}