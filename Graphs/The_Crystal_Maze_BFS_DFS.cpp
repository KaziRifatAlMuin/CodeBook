#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 505;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
char s[N][N];
bool visited[N][N] = {false};
vector <pair<int,int>> graph[N];
int component[N][N];
int crystal[N*N/2];

void BFS(pair <int, int> start, int no){
    queue <pair <int, int>> Q;
    Q.push(start);
    visited[start.first][start.second] = true;
    component[start.first][start.second] = no;
    if(s[start.first][start.second] == 'C') crystal[no]++;
    // cout << "[" << start.first << "," << start.second << "]" << " ";
    while(!Q.empty()){
        pair <int, int> node = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int x = node.first + dx[i];
            int y = node.second + dy[i];
            if(!visited[x][y] && x > 0 && x <= n && y > 0 && y <= m && s[x][y] != '#'){
                Q.push({x,y});
                visited[x][y] = true;
                component[x][y] = no;
                if(s[x][y] == 'C') crystal[no]++;
                // cout << "[" << x << "," << y << "]" << " ";
            }
        }
    }
}

void DFS(pair <int, int> node, int no){
    visited[node.first][node.second] = true;
    component[node.first][node.second] = no;
    if(s[node.first][node.second] == 'C') crystal[no]++;
    // cout << "[" << node.first << "," << node.second << "]" << " ";
    for(int i = 0; i < 4; i++){
        int x = node.first + dx[i];
        int y = node.second + dy[i];
        if(!visited[x][y] && x > 0 && x <= n && y > 0 && y <= m && s[x][y] != '#'){
            // if(s[x][y] == 'C') crystal[no]++;
            DFS({x,y}, no);
        }
    }
}

void solve()
{
    int q;
    cin >> n >> m >> q;

    memset(visited, 0, sizeof(visited));
    memset(crystal, 0, sizeof(crystal));
    memset(component, 0, sizeof(component));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
        }
    }
    int no = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j] && s[i][j] != '#'){
                BFS({i,j}, no); // BFS Faster & Less Space
                // cout << "\n";
                no++;            
            }
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << crystal[component[x][y]] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ":\n";
        solve();
    }
    return 0;
}