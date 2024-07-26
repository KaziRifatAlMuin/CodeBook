#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;

int spf[N];
vector <int> primes;

void seive(){
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

vector <pair<int,int>> factor(ll n){
    vector <pair<int,int>> fact;
    while(n > 1){
        ll p = spf[n];
        ll power = 0;
        while(n % p == 0){
            n /= p;
            power++;
        }
        fact.push_back({p, power});
    }
    return fact;
}

void solve(ll n)
{
    cout << primes.size() << "\n";
    vector <pair<int,int>> ans = factor(n);
    for(auto x : ans){
        cout << "(" << x.first << ", " << x.second << ")\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    seive();
    while(t--){
        ll n;
        cin >> n;
        solve(n);
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}