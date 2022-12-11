#include <iostream>

using namespace std;

#define endl '\n'

int main() {

    int N, K;
    cin >> N >> K;

    int cnt = 0;

    while (K--) {
        int a;
        cin >> a;
        cnt += (a + 1) / 2;
    }
    if (cnt >= N) cout << "YES";
    else cout << "NO";

    return 0;
}