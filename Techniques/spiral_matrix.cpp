#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

bool NotPrime[N + 5];
vector <int> primes;

void seive()
{
    for(int i = 2; i * i <= N; i++){
        if(!NotPrime[i]){
            for(int j = i * i; j <= N; j += i){
                NotPrime[j] = true;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(!NotPrime[i]) primes.push_back(i);
    }
}

void solve()
{
    int n, zero = 0;
    cin >> n;
    // for(int i = 0; i < n; i++){
    //     cout << primes[i] << " ";
    // }
    int mat[n+1][n+1];
    int k = 0, i = 1, j = 1, turn = 0, right = n, left = 1, up = 2, down = n;
    while(k < (n * n)){
        mat[i][j] = primes[k];
        k++;

        if(turn % 4 == 0){
            if(j == right){
                right--;
                turn++;
                i++; 
            }
            else{
                j++;
            }
        }
        else if(turn % 4 == 1){
            if(i == down){
                down--;
                turn++;
                j--;
            }
            else{
                i++;
            }
        }
        else if(turn % 4 == 2){
            if(j == left){
                left++;
                turn++;
                i--;
            }
            else{
                j--;
            }
        }
        else if(turn % 4 == 3){
            if(i == up){
                up++;
                turn++;
                j++;
            }
            else{
                i--;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    seive();
    while(t--){
        solve();
    }
    return 0;
}
