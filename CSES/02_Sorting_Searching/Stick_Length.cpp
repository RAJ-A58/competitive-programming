#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (cin >> n) {
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long median = a[n / 2];
        long long min_cost = 0;
        for (int i = 0; i < n; i++) {
            min_cost += abs(a[i] - median);
        }
        cout << min_cost << "\n";
    }
    return 0;
}