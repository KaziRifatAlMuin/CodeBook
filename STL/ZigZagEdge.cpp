#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector <int> a, b; // a = SBSB, b = BSBS
    for(int i = 0; i < n; i++){
        if(a.size() == 0){
            a.push_back(v[i]);
        }
        else{
            if(a.size() & 1){
                if(v[i] > a.back()) a.push_back(v[i]);
                else if(v[i] < a.back()){
                    a.pop_back();
                    a.push_back(v[i]);
                }
            }
            else{
                if(v[i] < a.back()) a.push_back(v[i]);
                else if(v[i] > a.back()){
                    a.pop_back();
                    a.push_back(v[i]);
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(b.size() == 0){
            b.push_back(v[i]);
        }
        else{
            if(!(b.size() & 1)){
                if(v[i] > b.back()) b.push_back(v[i]);
                else if(v[i] < b.back()){
                    b.pop_back();
                    b.push_back(v[i]);
                }
            }
            else{
                if(v[i] < b.back()) b.push_back(v[i]);
                else if(v[i] > b.back()){
                    b.pop_back();
                    b.push_back(v[i]);
                }
            }
        }
    }

    if(a.size() > b.size()){
        cout << a.size() << "\n";
        for(auto x : a) cout << x << " ";
        cout << "\n";
    }
    else{
        cout << b.size() << "\n";
        for(auto x : b) cout << x << " ";
        cout << "\n";
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