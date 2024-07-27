#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    int cnta[n+1][26] = {0}, cntb[n+1][26] = {0};
    memset(cnta, 0, sizeof(cnta));
    memset(cntb, 0, sizeof(cnta));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            cnta[i+1][j] = cnta[i][j];
            cntb[i+1][j] = cntb[i][j];
        }
        cnta[i+1][a[i] - 'a']++;
        cntb[i+1][b[i] - 'a']++;
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        vector <int> fa(26), fb(26);
        for(int j = 0; j < 26; j++){
            fa[j] = cnta[r][j] - cnta[l-1][j];
            fb[j] = cntb[r][j] - cntb[l-1][j];
        }
        int mismatch = 0;
        for(int j = 0; j < 26; j++){
            // cout << fa[j] << " " << fb[j] << "\n";
            mismatch += abs(fa[j] - fb[j]);
        }
        cout << mismatch / 2 << "\n";
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
https://codeforces.com/contest/1996/problem/C