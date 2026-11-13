#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n,k;
    cin >> n >> k;
    int odd_a=0,odd_b=0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(x%2) odd_a++;
    }
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(x%2) odd_b++;
    }
    if(k%2==0){
        if(odd_a >= odd_b) cout << "YES\n";
        else cout << "NO\n";
    }
    else{
        if(odd_a <= odd_b) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Number of test cases (t = 1 for single test problem; cin >> t for multi-test)
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
