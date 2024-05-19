#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e6 + 7;

bool NotPrime[N+5];
vector <int> primes;

void seive()
{
    for(int i = 2; i * i <= N; i++){
        if(!NotPrime[i]){
            for(int j = i * i; j <= N; j += i){
                NotPrime[j] = true;
            }
        }
    }
    for(int i = 2; i <= N; i++){
        if(!NotPrime[i]){
            primes.push_back(i);
        }
    }
}

void Factor(map <int, int> &mp, int n){
    for(int i = 0; i < n; i++){
        while(n % primes[i] == 0){
            mp[primes[i]]++;
            n /= primes[i];
        }
    }
}

bool DigitFactor(map <int, int> &mp, int n){
    int digit[8] = {9,8,7,6,5,4,3,2};
    for(int i = 0; i < 8; i++){
        while(n % digit[i] == 0){
            mp[digit[i]]++;
            n /= digit[i];
        }
    }
    return n == 1;
}

void solve()
{
    int n; cin >> n;
    map <int, int> mp;
    string ans;
    bool ok = DigitFactor(mp, n);
    for(auto x : mp){
        int num = x.first;
        char c = x.first + '0';
        int cnt = x.second;
        while(cnt--) ans.push_back(c);
    }
    if(n < 10) cout << n << "\n";
    else if(ok) cout << ans << "\n";
    else cout << -1 << "\n";
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