#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define SetBit(x, k) (x |= (1ll << k))
#define ClearBit(x, k) (x &= ~(1ll << k))
#define CheckBit(x, k) ((x >> k) & 1)
#define PowerOf2(v) (v && !(v & (v - 1)))
#define to_Binary(n) bitset<sizeof(n) * 4> (n).to_string()
long long int const MOD = 1e9 + 7;
int const N = 5005;

void solve()
{
    int n;
    cin >> n;
    vector <int> v(n), need(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        need[i] = i + 1;
        // cout << to_Binary(v[i]) << "\n";
    }
    for(int j = 0; j < 30; j++){
        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            x += CheckBit(v[i], j);
            y += CheckBit(need[i], j);
        }
        if(x == y) continue;
        else if(x == n - y){
            int mask = 0;
            SetBit(mask, j);
            for(int i = 0; i < n; i++) v[i] = v[i] xor mask;
        }
        else{
            cout << "NO\n";
            return;
        }
    }
    sort(v.begin(), v.end());
    if(v == need) cout << "YES\n";
    else cout << "NO\n";
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
