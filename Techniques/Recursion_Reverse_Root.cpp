#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 5005;

void solve(){
    ll n;
    if(!(cin >> n)) return;
    else solve();
    cout << fixed << setprecision(4) << sqrtl(n) << "\n";
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

// Problem ID : 1001