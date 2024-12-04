/*who_knows_*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define endl '\n'

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using omap = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e18 + 10;
const int N = 1500 + 10;

int power(long long n, long long k, const int mod) {
    int ans = 1 % mod;
    n %= mod;
    if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
    pw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = power(p1, MOD1 - 2, MOD1);
    ip2 = power(p2, MOD2 - 2, MOD2);
    ipw[0] =  {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }

}
struct Hashing {
    int n;
    string s; // 0 - indexed
    vector<pair<int, int>> hs; // 1 - indexed
    Hashing() {}
    Hashing(string _s) {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r) { // 1 - indexed
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<int, int> get_hash() {
        return get_hash(1, n);
    }
};

void solve() {
    string s, bin; cin >> s >> bin;
    int n = s.size();
    Hashing hs(s);
    int k; cin >> k;
    map<char, bool>bad;
    vector<pair<int, int>>v;
    for (int i = 0; i < 26; ++i) {
        if (bin[i] == '0') bad['a' + i] = true;
    }
    // for(auto[x,y]:bad) cout<<x<<endl;
    for (int i = 1; i <= n; ++i) {
        deque<char>dq;
        int cnt = 0;
        for (int j = 0; j < i; ++j) {
            dq.push_back(s[j]);
            if (bad[s[j]]) ++cnt;
        }
        if (cnt <= k) v.push_back(hs.get_hash(1, i));
        // cout << s.substr(0, i) << endl;
        for (int j = i; j < n; ++j) {
            if (bad[dq.front()]) --cnt;
            dq.pop_front();
            dq.push_back(s[j]);
            if (bad[s[j]]) ++cnt;
            if (cnt <= k) v.push_back(hs.get_hash(j - i + 2, j + 1));
            // cout << s.substr(j - i + 1, i) << endl;
        }
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    cout << v.size() << endl;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    prec();
    int t = 1, cs = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case " << cs++ << ": ";
        solve();
    }

    return 0;
}
