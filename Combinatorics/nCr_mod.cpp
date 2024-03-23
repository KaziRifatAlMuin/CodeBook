#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 7;
const int MOD = 998244353;


// Function to calculate power a^b modulo mod
long long power(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

// Function to calculate modular inverse of a modulo m
long long modInverse(long long a, long long m) {
    return power(a, m - 2);
}

// Function to calculate nCr modulo m using modular arithmetic
int nCr(int n, int r) {
    if (r > n)
        return 0;

    vector<long long> fact(n + 1, 1);

    // Pre-calculate factorials modulo m
    for (int i = 2; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    // Calculate nCr modulo m
    long long numerator = fact[n];
    long long denominator = (fact[r] * fact[n - r]) % MOD;
    long long inv_denominator = modInverse(denominator, MOD);

    return (numerator * inv_denominator) % MOD;
}

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }
    ll ans = 1;
    for(ll i = 0; i < n; i += 3){
        map <ll, ll> mp;
        mp[v[i]]++;
        mp[v[i+1]]++;
        mp[v[i+2]]++;
        auto it = mp.begin();
        ll seg = it->second;
        ans = (ans * seg) % MOD;
        mp.clear();
        // cout << ans << " ";
    }

    ans = (ans * nCr(n/3, n/6)) % MOD;
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
}S