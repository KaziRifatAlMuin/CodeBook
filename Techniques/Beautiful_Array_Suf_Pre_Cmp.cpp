#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e5 + 7;
long long const INF = 1e18 + 7;

int n, k;
bool inline cmp(int i, int j){
    if((i % k) == (j % k)) return i < j;
    return (i % k < j % k);
}

void solve()
{
    cin >> n >> k;
    vector <ll> v(n), pre(n+1), suf(n+1);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);

    map <int, int> mp;
    for(auto x : v) mp[x % k]++;
    ll odd = 0, ans = 0;
    for(auto x : mp) if(x.second & 1) odd++;
    if(odd > 1){
        cout << -1 << "\n";
        return;
    }
    if(odd == 0){
        for(int i = 0; i < n; i += 2) ans += (v[i+1] - v[i]);
        cout << ans / k << "\n";
        return;
    }

    for(int i = 2, j = n - 2; i < n; i += 2, j -= 2){
        pre[i] = pre[i-2] + v[i-1] - v[i-2];
        suf[j] = suf[j+2] + v[j+1] - v[j];
    }

    // for(auto x : v) cout << x << " ";
    // cout << "\n";

    ans = INF;
    for(int i = 0; i < n; i += 2){
        // cout << pre[i] << " " << suf[i+1] << "\n";
        if(mp[v[i] % k] & 1) ans = min(ans, pre[i] + suf[i+1]);
    }
    cout << ans / k << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}