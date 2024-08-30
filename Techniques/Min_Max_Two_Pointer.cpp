#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

void solve() {
    int n, x, y; 
    cin >> n;
    vector <int> a(n), b(n), dmin, dmax, ab(n), cnt(n), pre(n), maxx(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    for(int i = n - 1, j = n - 1; i >= 0;){
        if(b[j] >= a[i]){
            ab[i] = j;
            j = max(0, j - 1);
        }
        else{
            j++;
            i--;
        }
        if(j == 0 && b[j] >= a[i]){
            ab[i] = j;
            i--;
        }
        if(i == 0 && j == 0){
            ab[i] = j;
            break;
        }
        // cout << i << " " << j << "\n";
    }
    ll maxi = b[n-1];

    // for(auto x : ab){
    //     cout << x << " ";
    // }
    // cout << "\n";

    for(int i = n - 1; i >= 0; i--){
        cnt[ab[i]]++;
    }
    pre[0] = cnt[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + cnt[i];
    }

    // for(auto x : pre){
    //     cout << x << " ";
    // }
    // cout << "\n";

    for(int i = n - 1; i >= 0; i--){
        if(pre[i] == i+1){
            maxi = b[i];
        }
        maxx[i] = maxi;
    }

    // for(auto x : maxx){
    //     cout << x << " ";
    // }
    // cout << "\n";

    for(int i = 0; i < n; i++){
        dmin.push_back(b[ab[i]] - a[i]);
        dmax.push_back(maxx[i] - a[i]);
    }
    for(auto x : dmin){
        cout << x << " ";
    }
    cout << "\n";
    for(auto x : dmax){
        cout << x << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1721/problem/C