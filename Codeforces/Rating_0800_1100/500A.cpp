#include<bits/stdc++.h>
using namespace std;

int main(){
    //fast input output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //Your Solution goes here
    int n,t;
    cin >> n >> t;
    vector<int> a(n-1);
    for(int i=0;i<n-1;i++){
        cin >> a[i];
    }
    int currloc=0;
    while(currloc <= t-1){
        if(currloc==t-1){
            cout << "YES" << "\n";
            return 0;
        }
        currloc+=a[currloc];
    }
    cout << "NO" << "\n";
} 