#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAX 1001

int N, M, V;
bool visited[MAX];
int map[MAX][MAX];
queue<int> q;

void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void DFS(int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

void BFS(int v) {
    q.push(v);
    visited[v] = 1;
    cout << v << " ";

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int w = 1; w <= N; w++) {
            if (map[v][w] == 1 && visited[w] == 0) {
                q.push(w);
                visited[w] = 1;
                cout << w << " ";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    while (M--) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    DFS(V);
    cout << endl;

    reset();
    BFS(V);

    return 0;
}