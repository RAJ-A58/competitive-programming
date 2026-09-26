#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    
    // Use long long to prevent integer overflow since max n is 10^6
    long long sum = n * (n + 1) / 2;
    
    if (sum % 2 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<int> set1, set2;
        long long target = sum / 2;
        
        // Greedily pick elements from largest to smallest
        for (int i = n; i >= 1; i--) {
            if (target >= i) {
                set1.push_back(i);
                target -= i;
            } else {
                set2.push_back(i);
            }
        }
        
        cout << set1.size() << "\n";
        for (int x : set1) cout << x << " ";
        cout << "\n";
        
        cout << set2.size() << "\n";
        for (int x : set2) cout << x << " ";
        cout << "\n";
    }
    return 0;
}