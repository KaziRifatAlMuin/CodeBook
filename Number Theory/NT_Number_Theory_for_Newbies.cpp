#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void solve()
{
    string n;
    while(cin >> n){
        sort(n.begin(), n.end());
        reverse(n.begin(), n.end());
        ll a = stoll(n);
        string mn;
        bool check = false;
        for(int i = n.size() - 1; i >= 0; i--){
            while(n[i] == '0'){
                mn.push_back(n[i]);
                i--;
            }
            if(!check){
                check = true;
                mn.push_back(n[i]);
                reverse(mn.begin(), mn.end());
            }
            else
                mn.push_back(n[i]);
        }
        ll b = stoll(mn);
        cout << a << " - " << b << " = " << a - b << " = " << 9 << " * " << (a - b) / 9 << "\n";
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