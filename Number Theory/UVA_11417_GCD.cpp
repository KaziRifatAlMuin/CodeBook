#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    while(1){
        ll n, gcd = 0;
        cin >> n;
        if(n == 0) break;
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                gcd += __gcd(i,j);
            }
        }
        cout << gcd << "\n";
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