#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

//DFS, BFS ����. ���͸� �̿��ؼ� Ǯ����. Ư¡�� v[1001] �� �����صΰ�
//v[a].push_back(b); �̷������� 2�����迭ó�� pushback�� �Ҽ��ִ����̴�.

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

    cin >> N >> M; // N�� ������ ����, M�� ������ ����
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