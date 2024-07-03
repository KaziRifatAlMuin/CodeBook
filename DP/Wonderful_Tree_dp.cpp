#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector <vector<ll>> adj, dp1;
vector <ll> a, dp;
ll n;
 
void dfs(ll x){
    ll sum = 0;
    dp[x] = 0;
 
    if(adj[x].size() == 0){
        dp1[x].push_back(0);
        dp1[x].push_back(2e9);
        return;
    }
    vector <ll> vec(n+1, 0);
    for(auto i: adj[x]){
        dfs(i);
        sum += a[i];
        dp[x] += dp[i];
        for(int j = 1; j < dp1[i].size(); j++) vec[j] += dp1[i][j];
    }
    if(a[x] > sum){
        ll req = a[x]-sum;
        for(int i = 1; i <= n; i++){
            if(vec[i] < req){
                dp[x] += i*vec[i];
                req -= vec[i];
                vec[i] = 0;
            }
            else{
                dp[x] += i*req;
                vec[i] -= req;
                req = 0;
            }
        }
    }
    else{
        vec[0] = sum - a[x];
    }
    dp1[x].push_back(0);
    for(int i = 0; i < n; i++){
        dp1[x].push_back(vec[i]);
        if(vec[i] >= 1e9) break;
    }
}
 
void solve(){
    cin >> n;
    a.assign(n+1, 0);
    for(int i = 1; i <= n; i++) cin>>a[i];
    adj.assign(n+1, vector<ll>(0));
    for(int i = 2; i <= n; i++){
        ll p;
        cin >> p;
        adj[p].push_back(i);
    }
    dp.assign(n+1,0);
    dp1.assign(n+1, vector<ll>(0));
    dfs(1);
    cout << dp[1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// https://codeforces.com/contest/1987/problem/E