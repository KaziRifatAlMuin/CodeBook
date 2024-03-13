#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

int dp[N];
string s;

int f(int i){
    if(i == 0 && s[i] == '1') return dp[i] = 1;
    if(s[i] == '0') return dp[i] = 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = 1 + f(i - 1);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cin >> s;
    int c[26] = {0};
    for(int i = 0; i < k; i++){
        char ch; cin >> ch;
        c[ch - 'a'] = 1;
    }
    for(int i = 0; i < n; i++){
        if(c[s[i] - 'a']){
            s[i] = '1';
        }
        else{
            s[i] = '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    // cout << s << "\n";
    for(int i = 0; i < n; i++){
        ans += f(i);
        // cout << f(i) << " ";
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