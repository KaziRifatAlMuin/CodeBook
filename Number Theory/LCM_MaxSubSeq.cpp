#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
const int N = 3e5 + 7;
const long long INF = 1e18 + 7;

void solve() 
{
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    set <ll> st(v.begin(), v.end());
    auto __lcm = [&](ll a, ll b){ return a / __gcd(a,b) * b;};
    ll lcm = 1;
    for(auto x : v){
        lcm = __lcm(lcm, x);
        if(lcm > mod){
            cout << n << "\n";
            return;
        }
    }
    vector <ll> dv;
    for(int i = 1; i * i <= lcm; i++){
        if(lcm % i == 0){
            dv.push_back(i);
            if(lcm / i != i) dv.push_back(lcm / i);
        }
    }
    ll ans = 0;
    for(auto d : dv){
        ll cnt = 0;
        ll cur_lcm = 1;
        for(auto x : v){
            if(d % x == 0){
                cnt++;
                cur_lcm = __lcm(cur_lcm, x);
                if(st.count(cur_lcm) == 0) ans = max(ans, cnt);
            }
        }
    }
    cout << ans << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/1977/problem/C