#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e3 + 7;

ll nc2(ll n){
    return n * (n - 1) / 2;
}

ll nc3(ll n){
    return n * (n - 1) * (n - 2) / 6;
}

ll nc4(ll n){
    return n * (n - 1) * (n - 2) * (n - 3) / 24;
}


void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    if(k >= 2) ans += nc2(n);
    if(k >= 3) ans += 2 * nc3(n);
    if(k >= 4){
        ans += 3 * nc4(n); 
        ans += (nc2(n) * nc2(n - 2));
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://codeforces.com/gym/302977/problem/F