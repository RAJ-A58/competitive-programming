#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> arr(3);
        for(int i=0;i<3;i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        int end=arr[0]+arr[1];
        if(arr[2]>end){
            cout << end-arr[0] << endl;
        }
        else{
            cout << arr[2]-arr[0] << endl;
        }
    }
    return 0;
}