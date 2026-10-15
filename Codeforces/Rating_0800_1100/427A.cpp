#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count=0;
    int ans=0;
    for(int i=0;i<n;i++){
        int crime;
        cin >> crime;
        if(count <=0 && crime==-1){
            ans++;
        }
        else if(count >0 && crime==-1){
            count--;
        }
        else if(crime > 0){
            count+=crime;
        }
    }
    cout << ans << endl;
    return 0;
}
