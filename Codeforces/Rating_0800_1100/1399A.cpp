#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        // Sort the array to easily check differences between closest values
        sort(a.begin(), a.end());
        bool possible = true;
        for(int i = 1; i < n; i++){
            // If the gap between any two adjacent elements is greater than 1,
            // we can never bridge that gap to reduce the array to size 1.
            if(a[i] - a[i-1] > 1){
                possible = false;
                break;
            }
        }
        if(possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}