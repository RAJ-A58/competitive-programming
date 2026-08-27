#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> arr;
    arr.reserve(n);
    for(int i=0;i<n;i++){
        int num;
        cin >>num;
        arr.emplace_back(num,i+1);
    }
    sort(arr.begin(),arr.end());
    int l=0,r=n-1;
    while (l < r) {
            int sum = arr[l].first + arr[r].first;
            if (sum == k) {
                cout << arr[l].second << " " << arr[r].second << "\n";
                return 0;
            } 
            else if (sum < k) {
                l++;
            } 
            else {
                r--;
            }
        }

    cout << "IMPOSSIBLE\n";
}