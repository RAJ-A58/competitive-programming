#include <iostream>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    
    // Condition 1: Total coins must be divisible by 3
    // Condition 2: Neither pile can be more than double the other
    if ((a + b) % 3 == 0 && a <= 2 * b && b <= 2 * a) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}