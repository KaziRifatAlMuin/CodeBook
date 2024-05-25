#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 5005;

void solve()
{
    string s;
    int n;
    cin >> n >> s;
    int zero = 0, one = 0;
    for(auto x : s) x == '0' ? zero++ : one++;
    vector <int> ans;
    ll L = 0, R = n - 1, x;
    if(zero != one){
        cout << -1 << "\n";
        return;
    }
    while(L <= R){
        if(s[L] != s[R]) L++, R--;
        else{
            if(s[L] == '1'){
                s.insert(L, "01");
                x = L;
            }
            else{
                s.insert(R + 1, "01");
                x = R + 1;
            }
            L++, R++;
            ans.push_back(x);
        }
        // cout << s << "\n";
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    cout << "\n";
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
