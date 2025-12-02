#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;

bool NotPrime[N];
vector <int> primes;

void seive()
{
    NotPrime[1] = 1; NotPrime[0] = 1;
    for(ll i = 4; i < N; i += 2) NotPrime[i] = 1;
    for(ll i = 3; i * i < N; i += 2){
        if(!NotPrime[i]){
            for(ll j = i * i; j < N; j += (i+i)) NotPrime[j] = 1;
        }
    }
    for(ll i = 2; i < N; i++){
        if(!NotPrime[i]) primes.emplace_back(i);
    }
}


void solve(ll n)
{
    // ll cnt = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    // cout << "There are " << cnt << " Prime Numbers : \n";
    // for(auto x : primes){
    //     if(x > n) break;
    //     cout << x << " ";
    // }
    cout << primes.size() << "\n";
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