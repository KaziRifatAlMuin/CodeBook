#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n), pre(n+1);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pre[i+1] = pre[i] + v[i];
    }
    string s;
    cin >> s;
    ll ans = 0;
    for(int l = 0, r = n-1; l < r;){
        if(s[l] != 'L') l++;
        if(s[r] != 'R') r--;
        if(s[l] == 'L' && s[r] == 'R'){
            ans += (pre[r+1] - pre[l]);
            l++;
            r--;  
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2000/problem/D