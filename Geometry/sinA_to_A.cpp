#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const mod = 998244353;
int const N = 2e5 + 5;
#define PI acos(-1.0)

void solve()
{
    long double a, b, c, aa, bb, cc;
    ll x, y , z;
    cin >> a >> b >> c;
    aa = asin(a) * 180.0 / PI;
    bb = asin(b) * 180.0 / PI;
    cc = asin(c) * 180.0 / PI;

    x = round(aa), y = round(bb), z = round(cc);
    
    if(x + y + z != 180){
        ll xx, yy, zz;
        xx = 180 - x;
        yy = 180 - y;
        zz = 180 - z;
        if(xx + y + z == 180){
            cout << xx << "\n";
            return;
        }
        if(x + yy + z == 180){
            cout << yy << "\n";
            return;
        }
        if(x + y + zz == 180){
            cout << zz << "\n";
            return;
        }
    }
    cout << max(x, max(y,z)) << "\n";
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
