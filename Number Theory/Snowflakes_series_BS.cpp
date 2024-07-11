#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    ll n;
    cin >> n;
    for(int t = 2; t < 64; ++t) {
        __int128 low = 2, high = 1e18;
        while(low <= high){
            __int128 sum = 1, mid = (low + high) / 2;
            __int128 next = mid;
            for(int i = 1; i <= t; i++){
                sum += next; // 1 + k + k^2 + ..... + k^t
                if(sum > n) break;
                next *= mid;
            }
            if(sum == n){
                cout << "YES\n";
                return;
            }
            if(sum < n) low = mid + 1;
            else high = mid - 1;
        }
    }
    cout << "NO\n";
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