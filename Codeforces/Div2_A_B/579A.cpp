#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int count=0;
    while(n > 0){
        if(n & 1) count++;
        n >>=1;
    }
    cout << count << endl;
}