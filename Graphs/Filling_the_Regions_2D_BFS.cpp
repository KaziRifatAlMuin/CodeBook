#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const INF = 1000;
int const N = 55;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
char s[N][N];
bool visited[N][N];

void BFS(char zone){
    memset(visited, 0, sizeof(visited));
    queue <pair <int, int>> Q;

    for(int i = 1; i <= n; i++){
        if(s[i][1] != zone) visited[i][1] = true, Q.push({i, 1});
        if(s[i][m] != zone) visited[i][m] = true, Q.push({i, m});
    }
    for(int i = 1; i <= m; i++){
        if(s[1][i] != zone) visited[1][i] = true, Q.push({1, i});
        if(s[n][i] != zone) visited[n][i] = true, Q.push({n, i});
    }

    while(!Q.empty()){
        pair <int, int> node = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++){
            int x = node.first + dx[i];
            int y = node.second + dy[i];
            if(!visited[x][y] && x > 0 && x <= n && y > 0 && y <= m && s[x][y] != zone){
                Q.push({x,y});
                visited[x][y] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j]) s[i][j] = zone;
        }
    }

}


void solve()
{
    set <char> st;
    memset(s, 0, sizeof(s));
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
            if(s[i][j] != '.') st.insert(s[i][j]);
        }
    }
    
    for(auto x : st) BFS(x);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << s[i][j];
        }
        cout << "\n";
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