#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, long long> freq;
    long long total_pairs = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        int diff = a - i;
        total_pairs += freq[diff];
        freq[diff]++;
    }
    cout << total_pairs << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}