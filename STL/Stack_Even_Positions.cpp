#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int open = 0, close = 0, safe = 0;
    for(auto x : s){
        if(x == '(') open++;
        else if(x == ')') close++;
    }
    open = n/2 - open;
    close = n/2 - close;
    stack <int> last;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') safe++;
        else if(s[i] == ')') safe--;
        else if(s[i] == '_'){
            if(safe > 0 && close > 0){
                s[i] = ')';
                safe--;
            }
            else{
                s[i] = '(';
                safe++;
            }
        }
        if(s[i] == '('){
            last.push(i);
        }
        else{
            ans += (i - last.top());
            last.pop();
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/contest/1997/problem/C