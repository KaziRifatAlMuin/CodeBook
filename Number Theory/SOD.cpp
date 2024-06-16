#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e6 + 7;

bool NotPrime[N+5];
vector <int> primes;

void seive(){
    NotPrime[1] = 1;
    for(int i = 2; (1ll * i * i) <= N; i++){
        if(!NotPrime[i]){
            for(int j = i * 2; j <= N; j += i){
                NotPrime[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for(int i = 3; i <= N; i+= 2){
        if(!NotPrime[i]) primes.push_back(i);
    }
}

map <int, int> factor(ll n){
    map <int, int> mp;
    for(int i = 0; (1ll * primes[i] * primes[i]) <= n; i++){
        while(n % primes[i] == 0){
            mp[primes[i]]++;
            n /= primes[i];
        }
    }
    if(n > 1) mp[n]++;
    return mp;
}

void solve()
{
    ll n;
    cin >> n;
    map <int, int> pf = factor(n);
    ll sod = 1;
    for(auto x : pf){
        ll pi = x.first;
        ll ni = x.second;
        sod *= ((pow(pi, ni+1) - 1) / (pi - 1));
    }
    cout << sod << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    seive();
    while(t--){
        solve();
    }
    return 0;
}
