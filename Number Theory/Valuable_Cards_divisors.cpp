#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll n, x;
    cin >> n >> x;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    bool isdiv[x+1], danger[x+1], check[x+1];
    memset(isdiv, 0, sizeof(isdiv));
    memset(danger, 0, sizeof(danger));
    memset(check, 0, sizeof(check));

    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            isdiv[i] = true;
            isdiv[x / i] = true;
        }
    } 
    vector <ll> have;
    have.push_back(1);
    danger[x] = true;
    check[1] = true;
    ll ans = 1;

    for(auto y : a){
        if(y > x || !isdiv[y]) continue;
        if(!danger[y]){
            vector <ll> temp = have;
            for(auto it : temp){
                if(it * y > x || !isdiv[it * y] || check[it * y]) continue;
                have.push_back(it * y);
                check[it * y] = true;
            }
            for(auto it : have) danger[x / it] = true;
        }
        else{
            ans++;
            memset(danger, 0, sizeof(danger));
            memset(check, 0, sizeof(check));
            have.clear();
            have.push_back(1);
            danger[x] = true;
            check[1] = true;
            if(y <= x && isdiv[y]) have.push_back(y), danger[x / y] = true;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/1992/problem/F