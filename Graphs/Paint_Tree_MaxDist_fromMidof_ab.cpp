#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const mod = 998244353;
int const N = 2e5 + 5;

void bfs1(int start, int end, bool visited[], int n, vector<int> G[], int dist[], map <int, vector <int>> &mp){
    queue<int> Q;
    visited[start] = true;
    dist[start] = 0;
    Q.push(start);
    while(!Q.empty()){
        int parent = Q.front();
        Q.pop();
        for(auto child : G[parent]){
            if(!visited[child]){
                Q.push(child);
                visited[child] = true;
                dist[child] = dist[parent] + 1;
                mp[dist[child]].push_back(child);
            }
        }
    }
}

int bfs2(int start, bool visited[], int n, vector<int> G[], int dist[]){
    int ans = 0;
    queue<int> Q;
    visited[start] = true;
    dist[start] = 0;
    Q.push(start);
    // cout << " [" << start << "] ";
    while(!Q.empty()){
        int parent = Q.front();
        Q.pop();
        for(auto child : G[parent]){
            if(!visited[child]){
                Q.push(child);
                visited[child] = true;
                dist[child] = dist[parent] + 1;
                ans = max(ans, dist[child]);
                // cout << " (" << dist[child] << ") ";
            }
        }
    }
    return ans; // get distance of farthest node
}

void bfs3(int start, bool visited[], int n, vector<int> G[], int dist[]){
    queue<int> Q;
    visited[start] = true;
    dist[start] = 0;
    Q.push(start);
    while(!Q.empty()){
        int parent = Q.front();
        Q.pop();
        for(auto child : G[parent]){
            if(!visited[child]){
                Q.push(child);
                visited[child] = true;
                dist[child] = dist[parent] + 1;
            }
        }
    }
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> G[n+1];
    int dist[n+1];
    map <int, vector <int>> mp;

    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    bool visited[n+1];
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    if(a == b) {
        cout << 2 * (n - 1) - bfs2(a, visited, n, G, dist) << "\n";
    } 
    else {
        bfs1(b, a, visited, n, G, dist, mp);
        int dis = abs(dist[a] - dist[b]);
        int db = (dis + 1) / 2;
        int da = dis - db;
        int ans = 1e9;

        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        bfs3(a, visited, n, G, dist);

        for(auto r : mp[db]){
            if(abs(dist[r] - dist[a]) == da){
                memset(visited, 0, sizeof(visited));
                memset(dist, 0, sizeof(dist));
                int d = bfs2(r, visited, n, G, dist);
                // cout << db << " " << da << " " << r << " " << d << " " << 2 * (n-1) - d + db << "\n";
                // ans = min(ans,  2 * (n-1) - d + db);
                cout << 2 * (n-1) - d + db << "\n";
                return;
            }
        }
    }
    mp.clear();
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
// https://codeforces.com/contest/1975/problem/D