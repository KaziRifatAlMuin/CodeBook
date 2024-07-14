#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 305;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll dis[n][n];
    ll const inf = 1e17;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a; cin >> a;
            // if(i == j) dis[i][j] = 0 -> this is not aplicable for this problem
            if(a) dis[i][j] = 1;
            else dis[i][j] = inf;
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }


    ll q;
    cin >> q;
    while(q--){
        ll s, t;
        cin >> s >> t;
        s--, t--;
        s = s % n, t = t % n;
        if(dis[s][t] == inf) cout << -1 << "\n";
        else cout << dis[s][t] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://atcoder.jp/contests/arc159/tasks/arc159_a?lang=en