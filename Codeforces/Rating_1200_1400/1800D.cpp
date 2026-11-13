#include<iostream>
#include<string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int ans = n - 1;
    for (int i = 0; i < n - 2; i++) {
        if (s[i] == s[i+2]) {
            ans--;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}