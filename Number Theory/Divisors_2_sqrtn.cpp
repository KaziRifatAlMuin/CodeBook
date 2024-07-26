#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e6 + 7;

vector <int> findDivisors(int n){
    vector <int> d;
    for(int i = 1; 1LL * i * i < n; i++){
        if(n % i == 0){
            d.push_back(i);
            if(i != n / i) d.push_back(n/i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

void solve(ll n)
{
    vector <int> ans = findDivisors(n);
    for(auto x : ans){
        cout << x << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    while(t--){
        ll n;
        cin >> n;
        solve(n);
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}