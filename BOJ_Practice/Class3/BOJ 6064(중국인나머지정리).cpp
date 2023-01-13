#include <iostream>

using namespace std;

#define endl '\n'

int gcd(int a, int b) // 최대공약수
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) // 최소공배수
{
	return (a * b) / gcd(a, b);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;

	while (N--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int ans = -1;
		for (int i = x; i <= lcm(M, N); i += M) {
			int temp = i % N;
			if (temp == 0)
				temp = N;

			if (temp == y) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}