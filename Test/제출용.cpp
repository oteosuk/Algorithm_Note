#include <iostream>
#include <sstream>

using namespace std;

#define endl '\n'

int main() {
    
    string s;
    getline(cin, s);
    
    int num;
    int cnt = 0;

    stringstream ss(s);

    while (ss >> num) {
        if (num > 0) cnt++;
    }

    cout << cnt;
    
    return 0;
}