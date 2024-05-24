#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 3e5 + 7;

vector <ll> len(N);
ll n, m;

bool isPossible(ll k){
    ll line = 1, width = 0;
    for(int i = 1; i <= n; i++){
        width += len[i];
        if(width > k) line++, width = len[i];
        if(line > m) return false;
        width += (i < n);
    }
    return (line <= m && width <= k);
}

void solve()
{
    ll low = 1, high = 1e15, ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> len[i];
        low = max(low, len[i]);
    }
    while(low <= high){
        // FFFFTTTTTTTTTTTT
        ll mid = low + (high - low) / 2;
        if(isPossible(mid)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        // cout << mid << " ";
    }
    cout << ans << "\n";
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