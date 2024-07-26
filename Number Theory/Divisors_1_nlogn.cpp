#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e6 + 7;

vector <int> divisors[N];

void getDivisors(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            divisors[j].push_back(i);
        }
    }
}

void solve(ll n)
{
    for(auto x : divisors[n]){
        cout << x << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    getDivisors();
    while(t--){
        ll n;
        cin >> n;
        solve(n);
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}