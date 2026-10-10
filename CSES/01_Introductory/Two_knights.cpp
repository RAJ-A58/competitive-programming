#include <iostream>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    if (cin >> n) {
        for (long long k = 1; k <= n; k++) {
            // Calculate total ways to place 2 items on k*k board
            long long total_ways = (k * k) * (k * k - 1) / 2;
            
            // Calculate ways they can attack each other
            long long attack_ways = 4 * (k - 1) * (k - 2);
            
            cout << total_ways - attack_ways << "\n";
        }
    }
    
    return 0;
}