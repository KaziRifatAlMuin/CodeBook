#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 7;

void solve() {
    ll n, m, p;
    cin >> n >> m >> p;
    vector<string> s(n);
    string me;
    map<string, pair<ll, ll>> score;
    map<pair<string, char>, ll> WA;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        score[s[i]] = {0, 0};
        for (int j = 0; j < p; j++) {
            char c = 'A' + j;
            WA[{s[i], c}] = 0;
        }
    }

    ll prev = 0, ans = 0;
    bool isFirst = true;
    me = s[0];

    for (int i = 0; i < m; i++) {
        string name, verdict;
        char prob;
        ll time;
        cin >> name >> prob >> time >> verdict;

        bool isok = verdict == "OK";

        if (isFirst) {
            ans += (time - prev);
        }
        if (isok) {
            score[name] = {score[name].first + 1, score[name].second + time + WA[{name, prob}]};
        } else {
            WA[{name, prob}] += 20;
        }

        bool down = false;
        for (const auto &x : score) {
            if (x.second.first > score[me].first) {
                isFirst = false;
                down = true;
                break;
            } else if (x.second.first == score[me].first && x.second.second < score[me].second) {
                isFirst = false;
                down = true;
                break;
            }
        }

        if (!down) {
            isFirst = true;
        }

        prev = time;
    }
    if(isFirst){
        ans += (300 - prev); 
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
