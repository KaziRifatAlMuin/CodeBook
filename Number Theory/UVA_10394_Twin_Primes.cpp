#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e7 + 7;

bool NotPrime[N + 5];
vector <pair <int,int>> twinPrime;

void seive()
{
    for(int i = 2; i * i <= N; i++){
        if(!NotPrime[i]){
            for(int j = i * i; j <= N; j += i){
                NotPrime[j] = true;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(!(NotPrime[i] || NotPrime[i+2])){
            twinPrime.push_back({i, i+2});
        }
    }
}

void solve()
{
    int n;
    while(cin >> n){
        cout << "(" << twinPrime[n-1].first << ", " << twinPrime[n-1].second << ")\n";
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