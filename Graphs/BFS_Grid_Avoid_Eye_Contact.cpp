#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2005;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
char s[N][N];
bool visited[N][N];
int level[N][N];
int sx, sy, gx, gy;

bool BFS(){
    memset(visited, 0, sizeof(visited));
    memset(level, 0, sizeof(level));
    queue <pair <int, int>> Q;
    Q.push({sx, sy});
    visited[sx][sy] = true;
    while(!Q.empty()){
        pair <int, int> node = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int x = node.first + dx[i];
            int y = node.second + dy[i];
            if(x > 0 && x <= n && y > 0 && y <= m && !visited[x][y] && s[x][y] == '.'){
                Q.push({x,y});
                visited[x][y] = true;
                level[x][y] = level[node.first][node.second] + 1;
                // prev[{x,y}] = {node.first, node.second};
                // cout << "[" << x << "," << y << "]" << " ";
                if(x == gx && y == gy) return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
            if(s[i][j] == 'S'){
                sx = i, sy = j;
                s[i][j] = '.';
            }
            else if(s[i][j] == 'G'){
                gx = i, gy = j;
                s[i][j] = '.';
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '>'){
                for(int k = j + 1; k <= m; k++){
                    if(s[i][k] == '.' || s[i][k] == '!') s[i][k] = '!';
                    else break;
                }
            }
            else if(s[i][j] == '<'){
                for(int k = j - 1; k > 0; k--){
                    if(s[i][k] == '.' || s[i][k] == '!') s[i][k] = '!';
                    else break;
                }
            }
            else if(s[i][j] == 'v'){
                for(int k = i + 1; k <= n; k++){
                    if(s[k][j] == '.' || s[k][j] == '!') s[k][j] = '!';
                    else break;
                }
            }
            else if(s[i][j] == '^'){
                for(int k = i - 1; k > 0; k--){
                    if(s[k][j] == '.' || s[k][j] == '!') s[k][j] = '!';
                    else break;
                }
            }
        }
    }

    if(!BFS()){
        cout << -1 << "\n";
    }
    else{
        cout << level[gx][gy] << "\n";
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
// https://atcoder.jp/contests/abc317/tasks/abc317_e