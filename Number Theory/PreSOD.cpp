#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e7+ 7;

ll spf[N+5];
ll PreSOD[N+5];

void seive(){
    spf[1] = 1;
    for(int i = 2; i < N; i++){
        if(spf[i] == 0){
            for(int j = i; j <= N; j += i){
                spf[j] = i;
            }
        }
    }
}

void pre(){
    seive();
    for(int i = 2; i < N; i++){
        ll x = i;
        ll sod = 1;
        while(x > 1){
            ll p = spf[x];
            ll mul = p;
            while(x % p == 0){
                x /= p;
                mul *= p; // mul = pi^ni (at the end of loop)
            }
            mul -= 1;
            mul /= (p-1); // geometric series formula applied
            sod *= mul;
        }
        PreSOD[i] = PreSOD[i-1] + sod;
    }
}

void solve()
{
    ll n;
    while(cin >> n){
        if(n) cout << PreSOD[n] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    pre();
    while(t--){
        solve();
    }
    return 0;
}