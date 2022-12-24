#include <iostream>

using namespace std;

#define endl '\n'

int N, r, c;
int ans;

void Z(int y, int x, int size)
{
    if (y == r && x == c)
    {
        cout << ans << '\n';
        return;
    }

    if (r < y + size && r >= y && c < x + size && c >= x)
    {
        // ¿ÞÂÊÀ§ Å½»ö
        Z(y, x, size / 2);
        // ¿À¸¥ÂÊÀ§ Å½»ö
        Z(y, x + size / 2, size / 2);
        // ¿ÞÂÊ¾Æ·¡ Å½»ö
        Z(y + size / 2, x, size / 2);
        // ¿À¸¥ÂÊ¾Æ·¡ Å½»ö
        Z(y + size / 2, x + size / 2, size / 2);
    }
    else
    {
        ans += size * size;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
<<<<<<< Updated upstream
=======

    int N; cin >> N;


>>>>>>> Stashed changes

    cin >> N >> r >> c;
    
    Z(0, 0, (1 << N));

    return 0;
}