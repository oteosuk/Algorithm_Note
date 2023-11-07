#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

const int MAX = 1001;
int M, N, ans = 0;
int graph[MAX][MAX];
//�� �� �� ��
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

void bfs(void) {
    while (!q.empty()) {
        // ť���� �����丶�� ������
        int y = q.front().first; // �׷����� ���� ���
        int x = q.front().second; // �׷����� ���� ���
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // ����üũ �� �������丶��üũ
            if ((0 <= nx && 0 <= ny && nx < M && ny < N) && graph[ny][nx] == 0) {
                graph[ny][nx] = graph[y][x] + 1; // �� �̵� �� �丶���� ���� 1�� ���Ѱ��� �־��ش�.
                q.push({ ny, nx });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N; // M ��������, N ��������

    // �丶�� ���� �Է�
    for (int i = 0; i < N; i++) { // ����
        for (int j = 0; j < M; j++) { // ����
            cin >> graph[i][j];
            if (graph[i][j] == 1) { // �����丶��� ť ����
                q.push({ i, j });
            }
        }
    }

    //ó�� 1�� ����(�����丶��)�� �������� BFS ����    
    bfs();

    //������ ���� 0 �� �ִ���, ������ ���� ����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 0�� �����ϸ� -1 ���
            if (graph[i][j] == 0) {
                cout << -1;
                return 0;
            }
            // ���� ���� �ϼ��� graph ĭ ����(bfs�� ���� ����)
            if (ans < graph[i][j]) {
                ans = graph[i][j];
            }
        }
    }
    cout << ans - 1;
    return 0;
}