#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    ll gcd = 0;
    for(auto x : v){
        gcd = __gcd(gcd, x);
    }
    if(n == 1){
        if(v[0] < k) cout << k << "\n";
        else cout << k - 1 << "\n";
        return;
    }
    if(gcd == 1){
        cout << n + k - 1 << "\n";
        return;
    }
    ll maxi = gcd * (n - 1);
    ll in = (gcd - 1) * (n - 1);
    if(k <= in){
        ll seg = k / (gcd - 1);
        if(k % (gcd - 1) != 0) seg++;
        ll add = (k % (gcd - 1));
        if(k % (gcd - 1) == 0) add = gcd - 1;
        ll ans =  (gcd * (seg - 1)) + add;
        cout << ans << "\n";
    }
    else{
        cout << maxi + k - in << "\n";
    }
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
// https://codeforces.com/contest/2008/problem/G