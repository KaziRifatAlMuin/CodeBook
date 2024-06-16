#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
const int N = 3e5 + 7;

template <class T>
using pbds = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
// greater for descending, less_equal for muiltiset

void solve()
{
    ll n, q;
    cin >> n >> q;
    pbds <ll> st;
    map <int, int> mp;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        st.insert(a);
        ll temp = a;
        while(temp){
            mp[temp % 10]++;
            temp /= 10;
        }
    }
    while(q--){
        char c;
        ll k;
        cin >> c >> k;
        if(c == '+'){
            if(st.find(k) == st.end()){
                st.insert(k);
                while(k){
                    mp[k % 10]++;
                    k /= 10;
                }
            }
            else{
                st.erase(k);
                while(k){
                    mp[k % 10]--;
                    k /= 10;
                }
            }
        }
        else if(c == '-'){
            if(st.size() >= k){
                ll num = *st.find_by_order(k - 1);
                st.erase(st.find_by_order(k - 1));
                while(num){
                    mp[num % 10]--;
                    num /= 10;
                }
            }
        }
        else if(c == '?'){
            ll ans = 0;
            if(st.find(k) == st.end()){
                cout << -1 << "\n";
                continue;
            }
            while(k){
                ans += mp[k % 10];
                k /= 10;
            }
            cout << ans << "\n";
        }
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