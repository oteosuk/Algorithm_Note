#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    double n;
    cin >> n;
    if (n == 0) { cout << 0; return 0; }
    double ex = floor(n * 0.15 + 0.5);
    double answer = 0;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = ex; i < n - ex; i++) {
        answer += v[i];
    }
    answer = floor((answer / (n - 2 * ex)) + 0.5);

    cout << answer;

    return 0;
}