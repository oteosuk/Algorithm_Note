#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;
    vector<int> sortv;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
        sortv.push_back(a);
    }

    sort(sortv.begin(), sortv.end());
    sortv.erase(unique(sortv.begin(), sortv.end()), sortv.end());

    for (int i = 0; i < N; i++) {
        cout << lower_bound(sortv.begin(), sortv.end(), v[i]) - sortv.begin() << " ";
    }


    return 0;
}