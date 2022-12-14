#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

int main() {

    int N; cin >> N;
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        string s;
        s = to_string(i);

        for (int j = 0; j < s.size(); j++) {
            sum += s[j] - '0';
        }
        if (i % sum == 0) cnt++;
    }

    cout << cnt;

    return 0;
}