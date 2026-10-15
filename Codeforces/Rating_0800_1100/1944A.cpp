#include <iostream>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    
    // If there is only 1 island, he can only visit 1.
    // If Dominater can destroy at least n-1 bridges, he completely isolates island 1.
    if (n == 1 || k >= n - 1) {
        cout << 1 << "\n";
    } 
    // Otherwise, the graph mathematically cannot be disconnected.
    else {
        cout << n << "\n";
    }
}

int main() {
    // Optimize standard I/O operations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}