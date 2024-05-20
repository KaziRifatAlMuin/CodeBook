#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 10056;
int const N = 1007;

int C[N+2][N+2];
int ans[N+2];

void pre(){
    C[0][0] = 1;
    for (int n = 1; n < N; n++) {
        C[n][0] = 1;
        for (int k = 1; k <= n; k++) {
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
        }
    }
    ans[0] = 1;
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= i; j++){
            ans[i] = (ans[i] + (C[i][j] * ans[i-j])) % MOD;
        }
    }
}

void solve()
{
    ll n; cin >> n;    
    cout << ans[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    pre();
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}