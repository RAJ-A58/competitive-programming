#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<long long> a(n+1,0);
    // a.reserve(n+1);
    long long presum=a[0];
    for(int i=1;i<=n;i++){
        long long x;
        cin >> x;
        presum += x;
        a[i] = presum;
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        long long result=a[r]-a[l-1];
        cout << result << "\n";
    }
    return 0;
}