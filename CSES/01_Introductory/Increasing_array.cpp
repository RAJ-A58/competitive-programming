#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long ans=0;
    int prev=0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(i==0){
            prev = x;
            continue;
        }
        if(prev > x){
            ans += prev - x;
            x=prev;
        }
        prev=x;
    }
    cout << ans << "\n";
}