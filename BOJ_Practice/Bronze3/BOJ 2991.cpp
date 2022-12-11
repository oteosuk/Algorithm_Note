#include <iostream>

using namespace std;

#define endl '\n'

int A, B, C, D;

void dogattack(int x) {
    int cnt = 0;

    if (x % (A + B) != 0 && x % (A + B) <= A) {
        cnt++;
    }
    if (x % (C + D) != 0 && x % (C + D) <= C) {
        cnt++;
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C >> D;
    int P, M, N;
    cin >> P >> M >> N;

    dogattack(P);
    dogattack(M);
    dogattack(N);

    return 0;
}