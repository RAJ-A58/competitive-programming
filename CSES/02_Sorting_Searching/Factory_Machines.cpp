#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long t;
    cin >> n >> t;
    
    vector<long long> times(n);
    for(int i = 0; i < n; i++){
        cin >> times[i];
    }
    
    long long low = 0;
    long long high = 1e18;
    long long ans = high;
    
    while(low <= high){
        long long mid = low + (high - low) / 2;
        long long products = 0;
        
        for(int i = 0; i < n; i++){
            products += mid / times[i];
            if(products >= t) break; 
        }
        if(products >= t){
            ans = mid;
            high = mid - 1; 
        } 
        else {
            low = mid + 1; 
        }
    }
    
    cout << ans << "\n";
    return 0;
}