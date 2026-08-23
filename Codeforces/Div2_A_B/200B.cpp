#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    double ans = 0;
    for(int i=0;i<n;i++){
        double x;
        cin >> x;
        if(x != 0) ans += x/100;
    }
    cout << fixed << setprecision(12) << 100*ans/n << endl;
    return 0;
}