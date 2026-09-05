#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    int sum=0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int count=0;
    int endum=0;
    for(int i=n-1; i>=0; i--){
        sum-=a[i];
        endum+=a[i];
        count++;
        if(endum > sum){
            cout << count << "\n";
            return 0;
        }
    }
    return 0;
}