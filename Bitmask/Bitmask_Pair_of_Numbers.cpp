#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;
#define SetBit(x, k) (x |= (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) ((x >> k) & 1ll)

void solve() {
    ll x;
    cin >> x;
    if(x & 1){
        cout << -1 << "\n";
        return;
    }
    // a + b = (a ^ b) + 2(a & b)
    // 2(a ^ b) = (a + b) = (a ^ b) + 2(a & b) -> a & b = (a ^ b) / 2 = x/2;
    // a = a ^ b + (a & b) = x + x/2 (Assume all xor bits set in a, unset in b)
    // b = (a & b) = x/2 (a & b is added in both side cause they are set in both)
    int a = x + x / 2, b = x / 2;
    if((a ^ b) == x && a + b == 2 * x) cout << a << " " << b << "\n";
    else cout << -1 << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/1790/E