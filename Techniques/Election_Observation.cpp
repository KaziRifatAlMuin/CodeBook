#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e5 + 7;
long long const INF = 1e18 + 7;

void solve()
{
    int n, k;
    pair <int, int> winner = {0,0};
    cin >> n >> k;
    vector <ll> v(n), pre(n+1);
    pre[0] = k;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pre[i+1] = pre[i] + v[i];
        if(v[i] > winner.second) winner.first = i, winner.second = v[i];
    }
    for(int i = 0; i < n; i++){
        if(i == 0 && v[i] + k >= winner.second) cout << 0 << " ";
        else if(pre[1] < v[i] && i == winner.first) cout << 0 << " ";
        else if(pre[i+1] >= winner.second){
            cout << i << " ";
        }
        else{
            cout << i + 1 << " ";
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}