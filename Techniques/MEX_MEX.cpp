#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long const mod = 1e9 + 7;
int const N = 1e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    if(m == 1){
        cout << 0 << "\n";
        for(int i = 0; i < n; i++) cout << 0 << "\n";
    }
    else if(m > n){
        cout << n + 1 << "\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << (i - j + m) % m << " ";
            }
            cout << "\n";
        }
    }
    else{
        cout << m << "\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i < m - 1) cout << (i - j + m) % m << " ";
                else cout << (m - j + m) % m << " ";
            }
            cout << "\n";
        }
    }
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
https://codeforces.com/problemset/problem/1868/A