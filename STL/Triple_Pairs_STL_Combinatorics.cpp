#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
const int N = 3e5 + 7;
const long long INF = 1e18 + 7;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    map <pair <int, int>, map <int, int>> mp1, mp2, mp3;
    for(int i = 0; i < n - 2; i++){
        int a = v[i], b = v[i+1], c = v[i+2];
        mp1[{a,b}][c]++;
        mp2[{b,c}][a]++;
        mp3[{a,c}][b]++;
    }
    ll ans = 0;
    for(auto x : mp1){
        ll left = 0;
        for(auto y : x.second) left += y.second;
        for(auto y : x.second){
            left -= y.second;
            ans += (y.second * left);
        }
    }
    for(auto x : mp2){
        ll left = 0;
        for(auto y : x.second) left += y.second;
        for(auto y : x.second){
            left -= y.second;
            ans += (y.second * left);
        }
    }
    for(auto x : mp3){
        ll left = 0;
        for(auto y : x.second) left += y.second;
        for(auto y : x.second){
            left -= y.second;
            ans += (y.second * left);
        }
    }

    cout << ans << "\n";
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
