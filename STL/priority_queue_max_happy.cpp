#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll n, x, money = 0;
    cin >> n >> x;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];
    priority_queue <ll> q;
    for(ll i = 0; i < n; i++, money += x){
        if(v[i] <= money){
            q.push(v[i]);
            money -= v[i];
        }
        else if(!q.empty() && q.top() > v[i]){
            money = money + q.top() - v[i]; 
            q.pop();
            q.push(v[i]);
        }
    }
    cout << q.size() << "\n";
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