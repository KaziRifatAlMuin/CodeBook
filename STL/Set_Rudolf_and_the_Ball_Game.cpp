#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1005;

void solve()
{
    vector <pair <int, char>> v;
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++){
        int a; char c;
        cin >> a >> c;
        v.push_back({a,c});
    }
    set <int> s;
    s.insert(x-1);
    for(auto x : v){
        int d = x.first;
        char c = x.second;
        set <int> temp;
        for(auto it : s){
            if(c == '0' || c == '?'){
                int next = (it + d) % n;
                temp.insert(next);
            }
            if(c == '1' || c == '?'){
                int next = (it - d) % n;
                if(next < 0) next += n;
                temp.insert(next);
            }
        }
        s = temp;
    }
    cout << s.size() << "\n";
    for(auto x : s){
        cout << x + 1 << " ";
    }
    cout << "\n";
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