#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 12;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n;
char s[N][N];
pair<int, int> A, B, C;
set<pair<int, int>> target, have;

bool isOK(int x, int y, pair<int, int> P, pair<int, int> Q){
    pair <int, int> temp = {x,y};
    return x > 0 && x <= n && y > 0 && y <= n && s[x][y] != '#' && temp != P &&  temp != Q;
}

int BFS(){
    queue<tuple<pair<int, int>, pair<int, int>, pair<int, int>, int>> q;
    set<tuple<pair<int, int>, pair<int, int>, pair<int, int>>> visited;
    
    q.push({A, B, C, 0});
    visited.insert({A, B, C});
    
    while(!q.empty()){
        auto [a, b, c, time] = q.front();
        q.pop();

        // cout << "[" << a.first << " " << a.second << ", ";
        // cout << b.first << " " << b.second << ", ";
        // cout << c.first << " " << c.second << "]\n";

        have.clear(), have.insert(a), have.insert(b), have.insert(c);
        if(target == have) return time;
        
        for(int i = 0; i < 4; ++i){
            int na_x = a.first + dx[i], na_y = a.second + dy[i];
            int nb_x = b.first + dx[i], nb_y = b.second + dy[i];
            int nc_x = c.first + dx[i], nc_y = c.second + dy[i];
            pair<int, int> na = {na_x, na_y}, nb = {nb_x, nb_y}, nc = {nc_x, nc_y};

            bool moveA = false, moveB = false, moveC = false;
            if(na == b){
                if(nb == c){
                    moveA = moveB = moveC = isOK(nc_x, nc_y, a, b);
                }
                else{
                    moveA = moveB = isOK(nb_x, nb_y, na, c);
                }
            }
            else if(na == c){
                if(nc == b){
                    moveA = moveB = moveC = isOK(nb_x, nb_y, a, c);
                }
                else{
                    moveA = moveC = isOK(nc_x, nc_y, na, b);
                }
            }
            else{
                moveA = isOK(na_x, na_y, nb, nc);
            }


            if(nb == a){
                if(na == c){
                    moveA = moveB = moveC = isOK(nc_x, nc_y, a, c);
                }
                else{
                    moveA = moveB = isOK(na_x, na_y, nb, c);
                }
            }
            else if(nb == c){
                if(nc == a){
                    moveA = moveB = moveC = isOK(na_x, na_y, b, c);
                }
                else{
                    moveB = moveC = isOK(nc_x, nc_y, nb, c);
                }
            }
            else{
                moveB = isOK(nb_x, nb_y, na, nc);
            }

            if(nc == a){
                if(na == b){
                    moveA = moveB = moveC = isOK(nb_x, nb_y, c, a);
                }
                else{
                    moveA = moveC = isOK(na_x, na_y, nc, b);
                }
            }
            else if(nc == b){
                if(nb == a){
                    moveA = moveB = moveC = isOK(na_x, na_y, c, b);
                }
                else{
                    moveB = moveC = isOK(nb_x, nb_y, nc, a);
                }
            }
            else{
                moveC = isOK(nc_x, nc_y, na, nb);
            }

            
            if(!moveA){
                na_x = a.first;
                na_y = a.second;
            }
            if(!moveB){
                nb_x = b.first;
                nb_y = b.second;
            }
            if(!moveC){
                nc_x = c.first;
                nc_y = c.second;
            }
            
            tuple<pair<int, int>, pair<int, int>, pair<int, int>> new_state = {
                {na_x, na_y}, {nb_x, nb_y}, {nc_x, nc_y}
            };
            
            if(visited.find(new_state) == visited.end()) {
                visited.insert(new_state);
                q.push({{na_x, na_y}, {nb_x, nb_y}, {nc_x, nc_y}, time + 1});
            }
        }
    }
    
    return -1;
}

void solve()
{
    cin >> n;
    target.clear();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> s[i][j];
            if(s[i][j] == 'A') A = {i,j};
            else if(s[i][j] == 'B') B = {i,j};
            else if(s[i][j] == 'C') C = {i,j};
            else if(s[i][j] == 'X') target.insert({i,j});
        }
    }

    ll ans = BFS();
    if(ans == -1) cout << "trapped\n";
    else cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}