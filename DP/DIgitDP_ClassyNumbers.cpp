#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 7;
const int MOD = 998244353;

ll f(const string& lim, int idx, int non_zero, bool smaller){
    if(non_zero > 3) return 0;
    int sz = lim.size();
    if(idx == sz) return 1;
    // use a 0
    ll res = f(lim, idx + 1, non_zero, smaller ? smaller : (lim[idx] != '0'));
    if(smaller){
        // use digs from 1 to 9
        res += 9 * f(lim, idx + 1, non_zero + 1, 1);
    }
    else{
        ll lesser = lim[idx] - '0' - 1;
        if(lesser > 0) res += lesser * f(lim, idx+1, non_zero + 1, 1);\
        if(lim[idx] != '0') res += f(lim, idx+1, non_zero + 1, 0);
    }
    return res;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << f(to_string(r),0,0,0) - f(to_string(l-1),0,0,0) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}