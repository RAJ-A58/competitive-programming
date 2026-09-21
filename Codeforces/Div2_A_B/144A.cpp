#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    int minindex = 0;
    int maxindex = 0;
    int min_val = INT_MAX;
    int max_val = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        
        // We want the FIRST occurrence of the tallest soldier
        if (arr[i] > max_val) {
            max_val = arr[i];
            maxindex = i;
        }
        
        // We want the LAST occurrence of the shortest soldier
        // Using <= ensures the index updates if we find a duplicate minimum
        if (arr[i] <= min_val) {
            min_val = arr[i];
            minindex = i;
        }
    }
    
    // Number of swaps to move max to the front (index 0) 
    // + Number of swaps to move min to the back (index n-1)
    int total_swaps = maxindex + (n - 1 - minindex);
    
    // If the max index is after the min index, they cross paths during the swaps.
    // This overlapping swap does two things at once, saving us exactly 1 move.
    if (maxindex > minindex) {
        total_swaps--;
    }
    
    cout << total_swaps << "\n";
    
    return 0;
}