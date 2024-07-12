#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void solve()
{
    ll n;
    cin >> n;
    string s = to_string(n);
    s = s + s + s + s + s + s;
    s.resize(10);
    ll len = log10(n) + 1;
    vector <pair <ll, ll>> ans;
    for(ll i = 1; i <= 10; i++){
        string tmp = s;
        tmp.resize(i);
        ll x = stoll(tmp);
        for(ll a = 1; a <= 10000; a++){
            ll b = len * a - i;
            if(n * a - b == x && b > 0 && b <= 10000){
                ans.push_back({a, b});
            }
            // cout << a << " " << b << " " << x << "\n";
        }
    }
    cout << ans.size() << "\n";
    for(auto [a,b] : ans) cout << a << " " << b << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/1992/problem/E