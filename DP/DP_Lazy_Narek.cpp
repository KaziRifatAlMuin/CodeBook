#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll INF = 1e9 + 7;

void solve() {
    const string target = "narek";
    const set<char> allowed_chars(target.begin(), target.end());
    const ll M = target.size();
    
    int n, m;
    cin >> n >> m;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    // DP array initialized to -INF, except dp[0] which is 0
    vector<int> dp(M, -INF);
    dp[0] = 0;
    
    for (const auto& str : strings) {
        vector<int> current_dp = dp;
        
        // Iterate through all states of `dp[j]`
        for (int j = 0; j < M; j++) {
            int score = dp[j];  // Previous score
            int k = j;          // Position in the target string "narek"

            // Process each character of the string `str`
            for (const char& c : str) {
                if (allowed_chars.count(c)) score--;   // Penalize any valid char

                // Check if the current character matches the target at position k
                if (target[k] == c) k++;
                
                // If we complete one "narek" sequence, reward Narek and reset k
                if (k == M) {
                    score += 2 * M;
                    k = 0;
                }
            }
            // Update current DP state
            current_dp[k] = max(current_dp[k], score);
        }

        dp = current_dp;  // Move to the next iteration with updated dp
    }

    // Find the maximum value in the DP array
    const int ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
// https://codeforces.com/contest/2005/problem/C