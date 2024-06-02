#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 1e5 + 7;

void solve()
{
    map <string, string> score;
    int place[6][8] = {
        {13, 9, 5, 4, 3, 1, 0, 0},
        {13, 9, 7, 5, 4, 3, 2, 1},
        {13, 9, 7, 5, 4, 3, 2, 1},
        {13, 9, 5, 4, 3, 2, 1, 0},
        {13, 9, 5, 3, 2, 1, 0, 0},
        {13, 9, 5, 4, 2, 0, 0, 0},
    };
    string name, res;
    for(int i = 0; i < 16; i++){
        cin >> name >> res;
        score[name] = res;
    }
    vector <pair <int, string>> ans;
    for(auto x : score){
        int won = 0, FirstLose = 0, m = 1, pos;
        for(auto it : x.second){
            if(it == '1') won++;
            if(it == '0' && FirstLose == 0) FirstLose = m;
            m++;
        }
        pos = place[FirstLose][won];
        ans.push_back({pos, x.first});
    }

    sort(ans.begin(), ans.end());

    for(auto x : ans){
        int r = x.first;
        string name = x.second;
        if(r < 5){
            cout << r << " " << name << "\n";
        }
        else if(r == 5 || r == 7){
            cout << r << "-" << r + 1 << " " << name << "\n";
        }
        else if(r == 9 || r == 13){
            cout << r << "-" << r + 3 << " " << name << "\n";
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