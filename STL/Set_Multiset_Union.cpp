#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long const mod = 1e9 + 7;
int const N = 1e5 + 7;

void solve()
{
    int n;
    cin >> n;
    set <int> st;
    map <int, int> mp;
    multiset <multiset <int>> all; 
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        multiset <int> s;
        for(int j = 0; j < k; j++){
            int a; cin >> a;
            s.insert(a);
            st.insert(a);
            mp[a]++;
        }
        all.insert(s);
    }
    int ans = 0, sz = st.size();
    for(auto x : st){
        map <int, int> remove;
        for(auto s : all){
            if(s.count(x) >= 1){
                for(auto it : s) remove[it]++;
            }
        }
        int minus = 0;
        for(auto x : st){
            if(mp[x] == remove[x]) minus++;
        }
        if(minus != 0) ans = max(ans, sz - minus);
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
// https://codeforces.com/problemset/problem/1882/B