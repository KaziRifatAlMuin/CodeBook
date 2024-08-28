#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

void solve() {
    int n; 
    cin >> n;
    fflush(stdout);
    set <pair<int,int>> tree;
    // cout << "Hehe\n";
    for(int a = 1, b = 2; b <= n; b++){
        int x = a, y = b, last, go = n;
        while(go--){
            cout << "? " << x << " " << y << "\n";
            fflush(stdout);
            int mid;
            cin >> mid;
            if(mid == x){
                tree.insert({x,y});
                y = x;
                x = last;
                if(mid == 1 || x == y) break;
            }
            else{
                last = x;
                x = mid;
                y = b;
            }
        }
    }
    cout << "! ";
    for(auto x : tree){
        cout << x.first << " " << x.second << " ";
    }
    cout << "\n";
    fflush(stdout);
}

int32_t main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/2001/problem/C