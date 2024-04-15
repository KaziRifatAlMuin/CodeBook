#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;

void mul(string &n1, string &n2) {
    ll n = n1.size();
    ll lim = 1 << n; // Total number of subsets = 2^n
    ll ans = 0;
    for (ll i = 0; i < lim; ++i) {
        string a = n1, b = n2;
        for (ll j = 0; j < n; ++j) {
            if (i & (1 << j)) { // If jth bit is set in i
                ll x = n1[j], y = n2[j];
                a[j] = y, b[j] = x;
            }
        }
        ll num1 = stoll(a);
        ll num2 = stoll(b);
        if(num1 * num2 > ans){
            cout << num1 << " x " << num2 << " = " << num1 * num2 << "\n";
            ans = num1 * num2;
        }
    }
}

void solve() {
    string n1, n2;
    cin >> n1 >> n2;
    string x, y;
    bool done = false;
    for(int i = 0; i < n1.size(); i++){
        int a = n1[i] - '0', b = n2[i] - '0';
        if(a == b){
            x.push_back(a + '0');
            y.push_back(b + '0');
        }
        else{
            if(done){
                x.push_back(min(a,b) + '0');
                y.push_back(max(a,b) + '0');
            }
            else{
                y.push_back(min(a,b) + '0');
                x.push_back(max(a,b) + '0');
            }
            done = true;
        }
    }
    cout << x << "\n" << y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
