#include <iostream>

using namespace std;

#define endl '\n'

// 재귀함수를 이용한 분할정복 문제

int paper[128][128];
int w = 0, b = 0;

void solve(int y, int x, int size) {

    int check = paper[y][x]; // 0이면 하얀색, 1이면 파란색

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (check == 0 && paper[i][j] == 1) {
                check = 2; // 2는 사분면으로 잘라야한다는 의미
            }
            else if (check == 1 && paper[i][j] == 0) {
                check = 2;
            }
            if (check == 2) {
                solve(y, x, size / 2); // 왼쪽위
                solve(y, x + size / 2, size / 2); // 오른쪽 위
                solve(y + size / 2, x, size / 2); // 왼쪽 아래
                solve(y + size / 2, x + size / 2, size / 2); // 오른쪽 아래
                return;
            }
        }
    }
    if (check == 0)
        w++;
    if (check == 1)
        b++;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << w << endl;
    cout << b << endl;

    return 0;
}