// Problem: Sliding Window Minimum
// CSES Problem Set - Sliding Window Problems
// Link: https://cses.fi/problemset/task/3214

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    int x, a, b, c;
    cin >> x >> a >> b >> c;
    
    // Generate the array
    arr[0] = x;
    for(int i = 1; i < n; i++){
        arr[i] = (1LL * a * arr[i-1] + b) % c;
    }
    
    ll ans = 0;
    // dq stores pairs of {value, index}
    deque<pair<ll, int>> dq; 
    
    for(int i = 0; i < n; i++) {
        // 1. Remove elements from the back that are greater than or equal to current
        while(!dq.empty() && dq.back().first >= arr[i]) {
            dq.pop_back();
        }
        
        // 2. Add current element to the deque
        dq.push_back({arr[i], i});
        
        // 3. Remove the front element if it has fallen out of the window [i - k + 1, i]
        if(!dq.empty() && dq.front().second <= i - k) {
            dq.pop_front();
        }
        
        // 4. Once we hit index k-1, our window is full and we start XORing the minimums
        if(i >= k - 1) {
            ans ^= dq.front().first;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}