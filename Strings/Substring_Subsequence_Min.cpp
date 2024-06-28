#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 3e5 + 7;

void solve()
{
    string a, b;
    cin >> a >> b;
    int n1 = a.size(), n2 = b.size();
    ll ans = n1 + n2;
    for(int j = 0; j < n2; j++){
        ll cnt = 0, it = j;
        for(int i = 0; i < n1 && it < n2; i++){
            if(b[it] == a[i]){
                it++;
                cnt++;
            }
        }
        ans = min(ans, n1 + n2 - cnt);
    }
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