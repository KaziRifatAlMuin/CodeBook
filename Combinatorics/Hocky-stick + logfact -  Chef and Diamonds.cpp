#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;
ld logfact[N+5];

void pre(){
    logfact[0] = 0.0L; // log10(0!) = 0
    for(ll i = 1; i < N; i++){
        logfact[i] = logfact[i-1] + log10l((ld)i);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    // ld mul = q * fact[n] / fact[n+q];
    // ld ans = mul * fact[q+n+1] / (fact[n] * (q+1)); // Hocky-stick formula
    ld log_mul = log10l((ld)q) + logfact[n] - logfact[n + q];
    ld log_ans = log_mul + logfact[n + q + 1] - logfact[n] - log10l((ld)q + 1.0L);
    ld ans = powl(10.0L, log_ans);
    cout << fixed << setprecision(15) << ans << "\n";
}
    
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, cs = 1;
    cin >> t;
    pre();
    while(t--){
        // cout << "Case " << cs++ << ":\n";
        solve();
    }
    return 0;
}
// https://vjudge.net/problem/CodeChef-RANDID