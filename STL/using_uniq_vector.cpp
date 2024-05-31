#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define uniq(v) sort((v).begin(), (v).end()), (v).erase(unique((v).begin(), (v).end()), (v).end())
const int N = 2e5 + 7;

void solve()
{
    string s;
    int n; cin >> n >> s;
    string r = s;
    uniq(r);
    map <char, char> mp;
    for(int i = 0; i < r.size(); i++){
        mp[r[i]] = r[r.size() - i - 1];
    }
    for(auto x : s) cout << mp[x];
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// https://codeforces.com/contest/1974/problem/B