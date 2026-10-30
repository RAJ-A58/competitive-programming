#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long shared_start = max(a, b);
    long long shared_end = min(c, d);

    if (shared_start <= shared_end) {
        long long ans = abs(a - b) + (shared_end - shared_start) + abs(c - d);
        cout << ans << "\n";
    } else {
        long long ans = (c - a) + (d - b);
        cout << ans << "\n";
    }
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