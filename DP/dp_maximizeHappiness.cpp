#include <bits/stdc++.h>
using namespace std;
 
// Datatypes
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
//Constants
const ld pi= 3.141592653589793238;
const ll INF= LONG_LONG_MAX;
const ll mod=1000000007;
 
//TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
typedef vector<vector<ll>> vvll;
 
// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
 
// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
template<typename T>
void printvec(vector<T>v){ll n=v.size();fl(i,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}
 
// Mathematical functions
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
 
//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
 
//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
 
//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(ll n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
 
// Solution

ll findMax(ll i, ll hap, ll cur_money , ll n, ll x, vll& c, vll& h, vvll& dp, vvll& have){
    
    if(i==(n-1)){
        return (cur_money >= c[i]) ? h[i] : 0;
    } 
    
    if(dp[i][hap]!=-1 && have[i][hap]>=cur_money ) return dp[i][hap];
    
    ll not_take, take=0;
    
    not_take = findMax(i+1, hap, cur_money +x, n, x, c, h, dp, have);
    
    if(cur_money >=c[i]) take = findMax(i+1, hap+h[i], cur_money -c[i]+x, n, x, c, h, dp, have) + h[i];
    
    have[i][hap] = cur_money ;
    
    return dp[i][hap] = max(not_take, take);
}

void solve()
{
    ll n, x, i, sum_h=0;
    cin >> n >> x;
    
    vll c(n), h(n);
    
    for(i = 0 ; i < n; i++){
        cin >> c[i] >> h[i];
        sum_h += h[i];
    }
    
    vvll have(n, vll(sum_h+1));
    vvll dp(n, vll(sum_h+1, -1));
    
    ll ans = findMax(0, 0, 0, n, x, c, h, dp, have);
    cout << ans << "\n";
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