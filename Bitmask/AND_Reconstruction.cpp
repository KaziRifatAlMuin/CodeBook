#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

void solve() {
    ll n;
    cin >> n;
    vector <int> a, b(n-1);
    for(int i = 0; i < n - 1; i++) cin >> b[i];
    a.push_back(b[0]);
    for(int i = 1; i < n - 1; i++){
        a.push_back(b[i] | b[i-1]);
    }
    if(n > 2) a.push_back(b[n-2]);
    else a.push_back(b[0]);
    bool ok = true;
    for(int i = 1; i < n; i++){
        if((a[i] & a[i-1]) != b[i-1]) ok = false;
    }
    if(!ok) cout << -1 << "\n";
    else{
        for(auto x : a){
            cout << x << " ";
        }
        cout << "\n";
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
