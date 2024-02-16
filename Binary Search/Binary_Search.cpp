#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(auto &x : v) cin >> x;
    while(k--){
        int a;
        cin >> a;
        int low = 0, high = n - 1;
        bool NotFound = true;
        while(low <= high){
            int mid = low + (high - low)/ 2;
            if(v[mid] == a){
                cout << "YES\n";
                NotFound = false;
                break;
            }
            else if(v[mid] > a){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(NotFound) cout << "NO\n";
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