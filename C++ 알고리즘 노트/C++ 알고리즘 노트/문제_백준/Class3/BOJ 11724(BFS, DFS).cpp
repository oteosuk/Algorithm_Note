#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

//DFS, BFS 문제. 벡터를 이용해서 풀었다. 특징은 v[1001] 로 선언해두고
//v[a].push_back(b); 이런식으로 2차원배열처럼 pushback을 할수있단점이다.

vector<int> v[1001];
int visited[1001];
int N, M;

void DFS(int n) {
    visited[n] = 1;
    for (int i = 0; i < v[n].size(); i++) {
        int idx = v[n][i];
        if (visited[idx] == 0) {
            DFS(idx);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M; // N은 정점의 개수, M은 간선의 개수
    int ans = 0;

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            ans++;
            DFS(i);
        }
    }

    cout << ans << endl;

    return 0;
}