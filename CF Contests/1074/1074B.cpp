#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int max_val = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        max_val = max(max_val, x);
    }
    cout << max_val*n << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}