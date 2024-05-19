#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll r;
    cin >> r;
    ll ans = 0;
    for(ll x = 0; x <= r; x++){
        long double y1 = sqrtl((r * r) - (x * x));
        long double y2 = sqrtl(((r + 1) * (r + 1)) - (x * x));
        ll low = y1, high = y2;
        if(floor(y1) != ceil(y1)) low++;
        if(floor(y2) == ceil(y2)) high--;
        ans += (high - low + 1);
        // cout << x << " " << low << " " << high << "\n";
    }
    ans = (ans * 4) - 4; // on x axis and y axis, there wiil be no 2 symmetry instead of 4
    cout << ans << "\n"; // 627824 for 10000
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