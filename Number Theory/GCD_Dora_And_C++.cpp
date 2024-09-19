#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll INF = 1e9 + 7;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector <ll> v(n);
    ll maxi = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        maxi = max(maxi, v[i]);
    }
    ll gcd = __gcd(a,b);
    for(int i = 0; i < n; i++){
        v[i] = v[i] % gcd;
    }
    sort(v.begin(), v.end());
    ll ans = v[n-1] - v[0];
    for(int i = 0; i < n-1; i++){
        ans = min(ans, v[i] + gcd - v[i+1]);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
// https://codeforces.com/contest/2007/problem/C