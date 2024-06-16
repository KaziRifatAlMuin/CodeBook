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


void solve()
{
    int n;
    while(1){
        int flag = 1;
        cin >> n;
        if(n == 0) break;
        for(int i = 3; i <= n; i++){
            if(NotPrime[i] == 0 && NotPrime[n-i] == 0){
                cout << n << " = " << i << " + " << n - i << "\n";
                flag = 0;
                break;
            }
        }
        if(flag) cout << "‘Goldbach's conjecture is wrong.\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    seive();
    while(t--){
        solve();
    }
    return 0;
}