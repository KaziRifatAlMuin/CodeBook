#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;

int gpf[N];
ll SOD[N];

void seive(){
    gpf[1] = 1;
    for(int i = 2; i < N; i++){
        if(gpf[i] == 0){
            for(int j = i; j <= N; j += i){
                gpf[j] = i; // greatest prime factor
            }
        }
    }
}

void FindSOD(){
    seive();
    for(int i = 2; i < N; i++){
        ll x = i;
        ll sod = 1;
        while(x > 1){
            ll p = gpf[x];
            ll mul = p;
            while(x % p == 0){
                x /= p;
                mul *= p; // mul = pi^ni (at the end of loop)
            }
            mul -= 1;
            mul /= (p-1); // geometric series formula: (p^(n+1)-1)/(p-1)
            sod *= mul;
        }
        SOD[i] = sod;
    }
}

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

vector <pair<int,int>> factor(ll n){
    vector <pair<int,int>> fact;
    while(n > 1){
        ll p = gpf[n];
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
    // ll sum = 0;
    // vector <int> ans = findDivisors(n);
    // for(auto x : ans){
    //     cout << x << " ";
    //     sum += x;
    // }
    // cout << "\n";
    // cout << sum << "\n";

    // vector <pair<int,int>> ans = factor(n);
    // for(auto x : ans){
    //     cout << "(" << x.first << ", " << x.second << ")\n";
    // }

    cout << SOD[n] << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    // cin >> t;
    FindSOD();
    while(t--){
        ll n;
        cin >> n;
        solve(n);
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}