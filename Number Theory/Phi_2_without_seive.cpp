#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e7 + 7;

// coprime = No common factors between two numbers except 1
// phi(n) = number of numbers less than n that are coprime with n
// phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
// phi(n) = n * ((p1 - 1)/p1) * ((p2 - 1)/p2) * ... * ((pk - 1)/pk)
// Here p1, p2, ... , pk - everyone devides n because they are prime divisors
// In this seive, phi[j] is always divisible by i (The Prime Factor)

// Properties of Phi :
//     1. if p is a prime number, phi[p] = p - 1;
//     2. if p is a prime number and n is a positive integer, phi[p^n] = p^n - p^(n-1);
//     3. if a and m are coprime, a^phi[m] = 1 mod m (Euler's Theorem)
//     4. if a and m are coprime and m is prime, a^(m-1) = 1 mod m (Fermat's little theorem)

int phi(int n){
    int ans = n;
    for(int i = 2; 1ll * i * i <= n; i++){
        if(n % i == 0){ // i is prime
            while(n % i == 0){
                n /= i;
            }
        }
        ans -= (ans / i); // n * (1 - 1/p1) -> (n - n/p1)
    }
    if(n > 1){
        ans -= (ans / n); // there can be only one prime factor > sqrt(n)
    }
    return ans;
}

void solve(ll n)
{
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        // cout << "phi(" << i << ") = " << phi(i) << "\n";
        sum += phi(i);
    }
    cout << sum << "\n";
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