#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

const int MAX = 1001;
int M, N, ans = 0;
int graph[MAX][MAX];
//상 하 좌 우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q;

void bfs(void) {
    while (!q.empty()) {
        // 큐에서 익은토마토 꺼내기
        int y = q.front().first; // 그래프의 높이 담당
        int x = q.front().second; // 그래프의 가로 담당
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위체크 및 안익은토마토체크
            if ((0 <= nx && 0 <= ny && nx < M && ny < N) && graph[ny][nx] == 0) {
                graph[ny][nx] = graph[y][x] + 1; // 그 이동 전 토마토의 값에 1을 더한값을 넣어준다.
                q.push({ ny, nx });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N; // M 가로정보, N 높이정보

    // 토마토 정보 입력
    for (int i = 0; i < N; i++) { // 높이
        for (int j = 0; j < M; j++) { // 가로
            cin >> graph[i][j];
            if (graph[i][j] == 1) { // 익은토마토면 큐 삽입
                q.push({ i, j });
            }
        }
    }

    //처음 1인 곳들(익은토마토)을 기점으로 BFS 시작    
    bfs();

    //끝나고 나서 0 이 있는지, 없으면 정답 추출
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 0이 존재하면 -1 출력
            if (graph[i][j] == 0) {
                cout << -1;
                return 0;
            }
            // 가장 높은 일수의 graph 칸 추출(bfs가 끝난 지점)
            if (ans < graph[i][j]) {
                ans = graph[i][j];
            }
        }
    }
    cout << ans - 1;
    return 0;
}