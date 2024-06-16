#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const mod = 1e9 + 7;
int const N = 1e5 + 2;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll zero = 0, sum = 0, one = 0, two = 0;
    for(int i = 0; i < n; i++){
        int d = (s[i] - '0') % 3;
        sum = (sum + d) % 3;
        if(sum == 0) zero++;
        if(sum == 1) one++;
        if(sum == 2) two++;
    }
    // Prefix[R] == Prefix[L-1]
    // cout << zero << " " << one << " " << two << " ";
    ll ans = zero * (zero - 1) / 2 + one * (one - 1) / 2 + two * (two - 1) / 2 + zero;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
// https://codeforces.com/gym/104663/problem/K