#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

priority_queue<int, vector<int>, greater<int>> pq;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int temp; cin >> temp;

        if (temp == 0) {
            if (pq.empty()) {
                cout << 0 << endl;
            }
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else {
            pq.push(temp);
        }
    }

    return 0;
}