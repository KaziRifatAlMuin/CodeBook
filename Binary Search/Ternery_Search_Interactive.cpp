#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

void solve() {
    int low = 2, high = 999, ans = 2;
    while(low <= high){
        int a = low + (high - low) / 3;
        int b = low + 2 * (high - low) / 3;
        cout << "? " << a << " " << b << "\n";
        cout.flush();

        int x;
        cin >> x;

        if(x == (a * b)){
            low = b + 1;
        }
        else if(x == ((a+1) * (b+1))){
            ans = a;
            high = a - 1;
        }
        else if(x == (a * (b+1))){
            ans = b;
            high = b - 1;
            low = a + 1;
        }
    }

    cout << "! " << ans << "\n";
    cout.flush();
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
// https://codeforces.com/contest/1999/problem/G2