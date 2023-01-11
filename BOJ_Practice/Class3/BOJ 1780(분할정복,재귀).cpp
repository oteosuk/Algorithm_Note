#include <iostream>

using namespace std;

#define endl '\n'

int ans1, ans2, ans3; // 0으로 해줘야할까 말까
int paper[2187][2187];

void cut(int x, int y, int size) {
	int temp = paper[x][y];

	if (size == 1) {
		if (temp == -1) ans1++;
		else if (temp == 0) ans2++;
		else ans3++;

		return;
	}

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (paper[i][j] != temp) {
				if (size >= 3) {
					size = size/3;
					for (int k = 0; k < 3; k++) {
						for (int p = 0; p < 3; p++) {
							cut(x + size * k, y + size * p, size);
						}
					}
				}
				return;
			}
		}
	}

	if (temp == -1) ans1++;
	else if (temp == 0) ans2++;
	else ans3++;

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int size;
	cin >> size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> paper[i][j];
		}
	}

	cut(0, 0, size);

	cout << ans1 << endl << ans2 << endl << ans3;

	return 0;
}