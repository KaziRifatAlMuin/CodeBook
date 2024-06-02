#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const mod = 32768;
int const N = 32768;

bool vis[N+5];
int level[N+5];
vector <int> graph[N+5];

void bfs(int n){
    queue <int> q;
    q.push(n);
    level[n] = 0;
    while(!q.empty()){
        int cur_v = q.front();
        vis[cur_v] = true;
        q.pop();
        for(auto child : graph[cur_v]){
            if(!vis[child]){
                q.push(child);
                if(level[child] > level[cur_v] + 1){
                    level[child] = level[cur_v] + 1;
                }
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 0; i < N; i++){
        graph[(i * 2) % mod].push_back(i);
        graph[(i + 1) % mod].push_back(i);
        level[i] = 2 * N;
    }
    bfs(0);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        cout << level[a] << " ";
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
// https://codeforces.com/contest/1661/problem/B