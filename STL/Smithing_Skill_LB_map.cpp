#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 2e6 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector <ll> a(n), b(n), c(m);
    map <int, int> cc;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < m; i++) cin >> c[i], cc[c[i]]++;
    
    map <int, pair <int, int>> mp;
    for(int i = 0; i < n; i++){
        if(mp.find(a[i] - b[i]) == mp.end() || mp[a[i] - b[i]].first > a[i]) mp[a[i] - b[i]] = {a[i], i};
    }
    // The map is having differences smaller to greater with lowest possible ai for that
    // Because it is of no use with bigger ai of same difference
    // Smaller difference means always better profit and lowest ai means lowest requirment with same profit
    ll ans = 0;
    for(auto x : mp){
        auto d = x.first;
        auto [ai, i] = x.second;
        auto it = cc.lower_bound(ai); // Taking the smallest possible ingot type from c

        while(it != cc.end()){ // Repeat as long as it is possible with this ai, next ai may be smaller with less profit
            auto [ci, cnt] = *it;
            ll cycle = (ci - b[i]) / d;
            ans += cycle * cnt * 2;
            ll rem = ci - ((a[i] - b[i]) * cycle); // The remaining portion can be used for smaller ai
            cc.erase(it);
            if(cc.find(rem) == cc.end()) cc[rem] = cnt;
            else cc[rem] += cnt;
            it = cc.lower_bound(ai);
        }
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
// https://codeforces.com/contest/1989/problem/D