#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

string findSum(string str1, string str2)
{
    if(str1.length() > str2.length()) swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for(int i = 0; i < n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for(int i = n1; i < n2; i++)
    {
        int sum = ((str2[i]-'0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if(carry)
        str.push_back(carry + '0');
    reverse(str.begin(), str.end());
    return str;
}

void solve()
{
    ll n;
    cin >> n;
    string s, ans = "";

    cin >> s;
    while(s[0] == '0'){
        s.erase(0,1);
    }
    n = s.size();
    vector <string> pre(n+1);
    pre[0] = "0";
    for(int i = 0; i < n; i++){
        pre[i+1] = findSum(pre[i], string(1, s[i]));
    }

    ll carry = 0;
    for(int i = n; i > 0; i--)
    {
        ll sum = stoll(pre[i]) + carry;
        ans.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(ans.begin(), ans.end());
    if(carry) ans = to_string(carry) + ans;
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