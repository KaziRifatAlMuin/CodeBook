#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;

ll spf[N];
vector <ll> primes;

void seive() {
    for(ll i = 1; i < N; i ++) spf[i] = i;
    for(ll i = 2; i < N; i += 2) spf[i] = 2;
    for(ll i = 3; i * i < N; i += 2){
        if(spf[i] == i){
            for(ll j = i * i; j < N; j += (i+i)){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

    for(ll i = 2; i < N; i++){
        if(spf[i] == i) primes.emplace_back(i);
    }
}

vector <pair<ll,ll>> factor(ll n) {
    vector <pair<ll,ll>> fact;
    for(auto p : primes){
        if(p * p > n) break;
        if(n % p == 0){
            ll power = 0;
            while(n % p == 0){
                n /= p;
                power++;
            }
            fact.push_back({p, power});
        }
    }
    if(n > 1){
        fact.push_back({n, 1});
    }
    return fact;
}

ll NOD(ll n) {
    vector<pair<ll, ll>> fact = factor(n);
    ll divisors = 1;
    for(auto x : fact){
        divisors *= (x.second + 1);
    }
    return divisors;
}

void solve()
{
    ll n;
    cin >> n;
    cout << NOD(n) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    seive();
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}