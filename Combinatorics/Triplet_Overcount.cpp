#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
const int N = 3e5 + 7;
const long long INF = 1e18 + 7;

void solve() {
    ll n;
    cin >> n;
    vector <ll> v(n);
    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }
    map <pair <ll, ll>, map <ll, ll>> mp1, mp2, mp3;
    for(ll i = 0; i < n - 2; i++){
        ll a = v[i], b = v[i+1], c = v[i+2];
        mp1[{a,b}][c]++;
        mp2[{b,c}][a]++;
        mp3[{a,c}][b]++;
    }
    ll ans = 0;
    for(auto x : mp1){
        ll sum = 0, overcount = 0, exclude = 0;
        for(auto y : x.second){
            sum += y.second;
            exclude += (y.second * (y.second - 1)) / 2;
        }
        overcount = (sum * (sum - 1)) / 2;
        // cout << overcount - exclude << " ";
        ans += (overcount - exclude);
    }
    for(auto x : mp2){
        ll sum = 0, overcount = 0, exclude = 0;
        for(auto y : x.second){
            sum += y.second;
            exclude += (y.second * (y.second - 1)) / 2;
        }
        overcount = (sum * (sum - 1)) / 2;
        // cout << overcount - exclude << " ";
        ans += (overcount - exclude);
    }
    for(auto x : mp3){
        ll sum = 0, overcount = 0, exclude = 0;
        for(auto y : x.second){
            sum += y.second;
            exclude += (y.second * (y.second - 1)) / 2;
        }
        overcount = (sum * (sum - 1)) / 2;
        // cout << overcount - exclude << " ";
        ans += (overcount - exclude);
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
