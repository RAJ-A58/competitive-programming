#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    // -1e18 is safer for long long to avoid edge cases with large negative numbers
    long long maxsum = -1e18; 
    long long currsum = 0;
    
    while(n--) {
        long long val;
        cin >> val;
        currsum += val;

        if (currsum > maxsum) {
            maxsum = currsum;
        }
        if (currsum < 0) {
            currsum = 0;
        }
    }
    
    cout << maxsum << "\n";
    return 0;
}