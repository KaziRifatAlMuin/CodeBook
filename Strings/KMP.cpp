#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

vector<int> build_lps(string p) {
    vector<int> lps(p.size());
    int j = 0;
    for(int i = 1; i < p.size(); ) {
        if(p[i] == p[j]){
            lps[i] = j + 1;
            ++i, j++;
        }
        else{
            if(j != 0) j = lps[j - 1];
            else lps[i] = 0, ++i;
        }
    }
    return lps;
}

vector<int>ans;
// returns matches in vector ans in 0-indexed

void kmp(string s, string p) {
    vector<int> lps = build_lps(p);
    int psz = p.size(), sz = s.size();
    int i = 0, j = 0; // i -> s, j -> p;
    while(i < s.size()) {
        if(s[i] == p[j]){
            ++i, j++;
        }
        else{
            if(j != 0) j = lps[j - 1];
            else ++i;
        }
        if(j == p.size()){
            ans.push_back(i - p.size());
        }
    }
}

void solve()
{
    string a, b;
    cin >> a >> b;
    kmp(a,b);
    for(auto x : ans){
        cout << x << " ";
    }
    cout << "\n";
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