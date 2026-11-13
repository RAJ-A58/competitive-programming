#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    // Extract unique elements to avoid redundant modulo calculations
    vector<int> unique_a;
    for (auto const& [val, count] : freq) {
        unique_a.push_back(val);
    }
    
    int max_kept = 0;
    
    // For every unique element, count how many elements in the array are its multiples
    for (int i = 0; i < unique_a.size(); i++) {
        int current_min = unique_a[i];
        int kept = 0;
        
        for (int j = i; j < unique_a.size(); j++) {
            if (unique_a[j] % current_min == 0) {
                // Add the frequency of this multiple
                kept += freq[unique_a[j]];
            }
        }
        max_kept = max(max_kept, kept);
    }
    
    // The minimum removed is the total elements minus the maximum we can keep
    cout << n - max_kept << "\n";
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