#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long median = a[n / 2];

    long long minops = a[n - 1] - a[0];
    long long mincost = 0;

    for (int i = 0; i < n; i++) {
        mincost += abs(a[i] - median);
    }

    cout << mincost << ' ' << minops << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}