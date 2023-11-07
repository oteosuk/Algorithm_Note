#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 101;

#define endl "\n"

int N, M;
int graph[MAX][MAX];
int Connect[MAX];
int Result_BFS[MAX];
bool visit[MAX];

void BFS(int a)
{
    queue<int> Q;
    Q.push(a);
    visit[a] = true;

    while (Q.empty() == 0)
    {
        int x = Q.front();
        Q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (graph[x][i] == 1 && visit[i] == false)
            {
                visit[i] = true;
                Q.push(i);
                Connect[i] = Connect[x] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    while (M--) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        BFS(i);
        for (int j = 1; j <= N; j++)
        {
            Result_BFS[i] = Result_BFS[i] + Connect[j]; // 케빈 베이컨 수 구하기
        }
        memset(visit, false, sizeof(visit));
        memset(Connect, 0, sizeof(Connect));
    }

    int min = Result_BFS[1];
    int person = 1;
    for (int i = 2; i <= N; i++)
    {
        if (min > Result_BFS[i])
        {
            min = Result_BFS[i];
            person = i;
        }
    }

    cout << person << endl;

    return 0;
}