#include<bits/stdc++.h>
using namespace std;

void solve(){
    int l,r;
    cin >> l >> r;
    if(l >0 and r > 0){
        cout << r-l << endl;
    }
    else if(l < 0 and r < 0){
        cout << abs(l) - abs(r) << endl;
    }
    else{
        int M = min(abs(l), r);
        int total_elements = r - l + 1;
        int max_kept = min(total_elements, 2 * M + 2);
        
        cout << max(0, total_elements - max_kept) << "\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}