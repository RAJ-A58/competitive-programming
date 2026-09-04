#include<iostream>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin >> n >> x;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int sum=0;
    int l=0;
    int count=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        while(sum > x){
            sum-=a[l];
            l++;
        }
        if(sum == x){
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}