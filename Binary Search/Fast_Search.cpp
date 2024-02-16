#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

// First index where value >= target
int lowerbound(vector <int> v, int n, int x){
    int low = 0, high = n - 1, ans = n;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(v[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

// First index where value > target
int upperbound(vector <int> v, int n, int x){
    int low = 0, high = n - 1, ans = n;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(v[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n;
    vector <int> v(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    cin >> k;
    while(k--){
        int l, r; 
        cin >> l >> r;
        int low = 0, high = n - 1;
        // int lb = lowerbound(v, n, l); // Gets TLE
        // int ub = upperbound(v, n, r); // Gets TLE
        int lb = lower_bound(v.begin(), v.end(), l) - v.begin();
        int ub = upper_bound(v.begin(), v.end(), r) - v.begin();
        cout << ub - lb << " ";
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