#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define endl "\n"

int N, M;
int graph[101][101];

void floyd() //i에서 j로 가는 최단거리 구하기
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j) continue;
                else if (graph[i][k] != 0 && graph[k][j] != 0)
                {
                    if (graph[i][j] == 0) graph[i][j] = graph[i][k] + graph[k][j];
                    else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
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

    floyd();

    int result = INT_MAX;
    int person;
    for (int i = 1; i <= N; i++)
    {
        int temp = 0;
        for (int j = 1; j <= N; j++)
        {
            temp = temp + graph[i][j]; // 케빈 베이컨 수 구하기
        }

        if (temp < result)
        {
            result = temp;
            person = i;
        }
    }

    cout << person << endl;

    return 0;
}