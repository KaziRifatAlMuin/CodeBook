#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e6 + 7;

bool NotPrime[N+5];
vector <int> primes;

void seive(){
    NotPrime[1] = 1;
    for(int i = 2; (1ll * i * i) <= N; i++){
        if(!NotPrime[i]){
            for(int j = i * 2; j <= N; j += 2){
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
    int cs = 1;
    while(1){
        int n; cin >> n;
        if(n == 0) break;
        ll ans = 0;
        cout << "Case " << cs++ << ": ";
        map <int, int> mp = factor(n);
        
        for(auto x : mp){
            ans += pow(x.first, x.second);
        }
        if(mp.size() == 1) ans++;
        cout << max(2ll, ans) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    //cin >> t;
    seive();
    while(t--){
        solve();
    }
    return 0;
}