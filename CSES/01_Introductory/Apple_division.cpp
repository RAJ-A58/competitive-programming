#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<long long> p(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        total_sum += p[i];
    }
    long long min_diff = total_sum;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        long long group1_sum = 0;
        
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                group1_sum += p[j];
            }
        }
        
        long long group2_sum = total_sum - group1_sum;
        long long current_diff = abs(group1_sum - group2_sum);
        
        min_diff = min(min_diff, current_diff);
    }
    cout << min_diff << "\n";
    return 0;
}