#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 101;
long long const INF = 1e18 + 7;


vector <int> G[N];
bool vis[N];

void DFS(int v){
    vis[v] = true;
    char c = v + 'a';
    cout << c;
    for(auto child : G[v]){
        if(!vis[child]){
            DFS(child);
        }
    }
}


void solve()
{
    int n;
    cin >> n;
    vector <string> str;
    map <char, pair <char, char>> mp;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        str.push_back(s);
    }
    set <char> st;
    queue <int> q;
    vector <int> prev(26, -1), next(26, -1); 
    string ans;
    for(auto s : str){
        int k = s.size();
        for(int i = 0; i < k; i++){
            st.insert(s[i]);
            if(k == 1){
                prev[s[i] - 'a'] = max(prev[s[i] - 'a'], -1);
                next[s[i] - 'a'] = max(next[s[i] - 'a'], -1);
            }
            else if(i == 0){
                prev[s[i] - 'a'] = max(prev[s[i] - 'a'], -1);
                next[s[i] - 'a'] = s[i+1] - 'a';
            }
            else if(i == k - 1){
                prev[s[i] - 'a'] = s[i-1] - 'a';
                next[s[i] - 'a'] = max(next[s[i] - 'a'], -1);
            }
            else{
                prev[s[i] - 'a'] = s[i-1] - 'a';
                next[s[i] - 'a'] = s[i+1] - 'a';
            }
        }
    }
    for(auto x : st){
        if(prev[x - 'a'] != -1){
            G[prev[x - 'a']].push_back(x - 'a');
            G[x - 'a'].push_back(prev[x - 'a']);
        }
        if(next[x - 'a'] != -1){
            G[next[x - 'a']].push_back(x - 'a');
            G[x - 'a'].push_back(next[x - 'a']);
        }
    }
    for(auto x : st) q.push(x - 'a');

    while(!q.empty()){
        int now = q.front();
        if(vis[now]) q.pop();
        else{
            if(prev[now] == -1){
                DFS(now);
                q.pop();
            }
            else{
                q.pop();
                q.push(now);
            }
        }
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
// https://codeforces.com/contest/638/problem/B