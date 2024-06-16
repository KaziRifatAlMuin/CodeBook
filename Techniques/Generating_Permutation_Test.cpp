#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 3e5 + 7;

void Test(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i + 1;
    }
    set <int> st;
    map <int, vector <int>> mp;
    cout << "Start : " << n << "\n";
    do{
        ll sum = 0;
        for (int i = 1; i <= n; ++i) {
            int a = abs(v[i-1] - i);
            sum += a;
            // cout << v[i-1] << " ";
        }
        st.insert(sum);
        mp[sum] = v;
        // cout << " = " << sum << "\n";
        if(sum == 4){
            for(auto x : v){
                cout << x << " ";
            }
            cout << "\n";
        }
    } while (next_permutation(v.begin(), v.end()));

    // for(auto x : st){
    //     cout << x << " -> ";
    //     for(auto v : mp[x]){
    //         cout << v << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
}

void solve() 
{
    ll n, k;
    cin >> n >> k;
    // Test(n);
    ll maxi = 0;
    vector <ll> v(n);
    for(int p = n, i = 1; i <= n; i++, p--){
        ll a = abs(p - i);
        maxi += a;
        v[i-1] = i;
    }
    // cout << maxi << "\n";
    ll val = (n - 1) * 2;

    if(k & 1 || k > maxi){
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    ll todo = k;

    for(int i = 0; i <= n / 2; i++){
        if(todo > val){
            swap(v[i], v[i + val / 2]);
            todo -= val;
            val -= 4;
        }
        else{
            swap(v[i], v[i + todo / 2]);
            break;
        }
    }
    ll y = 1, z = 0;
    for(auto x : v){
        cout << x << " ";
        z += abs(x - y);
        y++;
    }
    cout << "\n";
    // cout << z << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
