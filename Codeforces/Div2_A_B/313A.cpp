#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n >=0){
        cout << n;
    }
    else{
        string s=to_string(n);
        int len=s.length();
        int a=stoi(s.substr(0,len-1));
        int b=stoi(s.substr(0,len-2)+s.substr(len-1,1));
        cout << max(a,b);
    }
    return 0;
}