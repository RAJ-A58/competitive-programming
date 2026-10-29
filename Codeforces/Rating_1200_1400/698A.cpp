#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Initialize an N x 3 DP table with 1e9 to represent invalid states
    vector<vector<int>> dp(n, vector<int>(3, 1e9));

    // Base cases for Day 0
    dp[0][0] = 1; // We can always rest, adding 1 to the count
    if (a[0] == 1 || a[0] == 3) dp[0][1] = 0; // Contest
    if (a[0] == 2 || a[0] == 3) dp[0][2] = 0; // Sport

    // Fill the table iteratively from Day 1 to n-1
    for (int i = 1; i < n; i++) {
        
        // Activity 0: Rest today. We add 1 rest day.
        // We can transition from ANY activity yesterday.
        dp[i][0] = 1 + min({dp[i-1][0], dp[i-1][1], dp[i-1][2]});

        // Activity 1: Contest today (if available). We add 0 rest days.
        // We can transition from Rest (0) or Sport (2) yesterday.
        if (a[i] == 1 || a[i] == 3) {
            dp[i][1] = 0 + min(dp[i-1][0], dp[i-1][2]);
        }

        // Activity 2: Sport today (if available). We add 0 rest days.
        // We can transition from Rest (0) or Contest (1) yesterday.
        if (a[i] == 2 || a[i] == 3) {
            dp[i][2] = 0 + min(dp[i-1][0], dp[i-1][1]);
        }
    }

    // The final answer is the minimum rest days on the last day across all possible ending activities
    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}