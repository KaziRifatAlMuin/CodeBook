#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 2e5 + 5;
#define PI acos(-1.0)
#define eps 1e-6

void solve()
{
    ll a, b, m, n, angle;
    cin >> a >> b >> m >> n >> angle;
    ll gcd = __gcd(m,n);
    m /= gcd;
    n /= gcd;

    double theta = angle * PI / 180.0;
    auto h = (double) a * cos(theta) + (double) b * sin(theta);
    auto w = (double) a * sin(theta) + (double) b * cos(theta);

    ll L = 0, R = 2e9 + 7, mid, ans = 0; // Be careful about R
    while(L <= R){
        //FFFFFFTTTTTT
        mid = (L + R) / 2;
        ll H = mid * m, W = mid * n;
        if(h - eps <= H && w - eps <= W){
            ans = mid;
            R = mid - 1;
        }
        else{
            L = mid + 1;
        }
    }
    cout << m * ans << " " << n * ans << "\n";
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
