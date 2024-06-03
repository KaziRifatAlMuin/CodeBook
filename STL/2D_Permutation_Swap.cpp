#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
const int N = 1e4 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    if(n == 1 || m == 1){
        cout << "YES\n";
        return;
    }

    set < set <int> > rowa, rowb, cola, colb;

    for(int i = 0; i < n; i++){
        set <int> row;
        for(int j = 0; j < m; j++){
            row.insert(a[i][j]);
        }
        rowa.insert(row);
    }

    for(int i = 0; i < n; i++){
        set <int> row;
        for(int j = 0; j < m; j++){
            row.insert(b[i][j]);
        }
        rowb.insert(row);
    }

    for(int i = 0; i < m; i++){
        set <int> col;
        for(int j = 0; j < n; j++){
            col.insert(a[j][i]);
        }
        cola.insert(col);
    }

    for(int i = 0; i < m; i++){
        set <int> col;
        for(int j = 0; j < n; j++){
            col.insert(b[j][i]);
        }
        colb.insert(col);
    }

    if(rowa == rowb && cola == colb) cout << "YES\n";
    else cout << "NO\n";
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