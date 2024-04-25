#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
const int N = 3e5 + 7;

ll dp[N];

ll f(ll n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    else if(n == 2) return 3;
    else if(dp[n] != -1) return dp[n];
    return dp[n] = (f(n - 1) % mod + (((2 * (n - 1)) % mod) * f(n - 2)) % mod) % mod;
}

void solve()
{
    int n, k; 
    cin >> n >> k;
    set <int> st;
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        st.insert(x);
        st.insert(y);
    }
    int m = n - st.size();
    memset(dp, -1, sizeof(dp));
    cout << f(m) << "\n";
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
