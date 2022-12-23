#include <iostream>

using namespace std;

#define endl '\n'

// ����Լ��� �̿��� �������� ����

int paper[128][128];
int w = 0, b = 0;

void solve(int y, int x, int size) {

    int check = paper[y][x]; // 0�̸� �Ͼ��, 1�̸� �Ķ���

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (check == 0 && paper[i][j] == 1) {
                check = 2; // 2�� ��и����� �߶���Ѵٴ� �ǹ�
            }
            else if (check == 1 && paper[i][j] == 0) {
                check = 2;
            }
            if (check == 2) {
                solve(y, x, size / 2); // ������
                solve(y, x + size / 2, size / 2); // ������ ��
                solve(y + size / 2, x, size / 2); // ���� �Ʒ�
                solve(y + size / 2, x + size / 2, size / 2); // ������ �Ʒ�
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