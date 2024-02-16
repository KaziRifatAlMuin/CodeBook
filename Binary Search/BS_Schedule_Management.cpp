#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

int n, m;
vector <int> v(N);
map <int, int> mp;

bool isPossible(ll x){
    ll left = 0, help = 0;
    for(int i = 1; i <= n; i++){
        if(x < mp[i]){
            left += abs(mp[i] - x);
        }
        else if(x > mp[i]){
            help += (abs(x - mp[i]))/2;
        }
    }
    return left <= help;
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        mp[i] = 0; // It is must
    }
    for(int i = 0; i < m; i++){
        cin >> v[i];
        mp[v[i]]++;
    }
    
    ll low = 1, high = 2 * m, ans = 0;
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}