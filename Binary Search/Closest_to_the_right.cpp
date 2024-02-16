#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n+2);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    v[0] = INT_MIN, v[n+1] = INT_MAX;
    while(k--){
        int x; cin >> x;
        int low = 0, high = n + 1;
        while(high - low > 1){
            int mid = low + (high - low)/ 2;
            if(v[mid] < x){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        cout << high << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}