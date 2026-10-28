#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<long long> dp(n+1,-1);
    dp[0]=0;
    for(int i = 1; i <= n; i++){
        int cuta = -1e9, cutb = -1e9, cutc = -1e9;
        
        if(i >= a) {
            cuta = dp[i - a] + 1;
        }
        if(i >= b) {
            cutb = dp[i - b] + 1;
        }
        if(i >= c) {
            cutc = dp[i - c] + 1;
        }
        
        dp[i] = max({cuta, cutb, cutc});
    }
    cout << dp[n] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}